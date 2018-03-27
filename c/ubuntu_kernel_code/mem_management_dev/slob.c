/*
 * Best Fit Simple List Of Blocks
 *
 * Modified Tiago Moore & Lukas borges
 *
 * Nov 2015
 *

 *
 *Chages made include the following:
 * We modified the slob_page_alloc to attempt to alocate a best page
 * The funtion that performes this is defined as 100, the fucngion returns the slob with 
 * the best fit given a page sp . In addidtion , a function get_best_block was added to  
 * returns the best bloc page, found by our modified find page alloc ,it is subsequently used
 * for comparison. Subsequently, the slob_alloc() function was modified to get us the best fit block using
 * the implemented functions and the logic that saves best page until it is replaced by new best page. 
 * We keep *track of the variables for the system call when an allocation requested memory is not server - !b
 *
 * * Allocation from heap involves first searching for a page with
 * sufficient free blocks (best-fit approach) followed by
 * a best-fit scan of the page.
 *
 * Implementation is testing with  kmalloc/kfree, since blocks returned
 * from kmalloc are prepended with a 4-byte header with the kmalloc size.
 * If kmalloc is asked for objects of PAGE_SIZE or larger, it calls
 * alloc_pages() directly, allocating compound pages so the page order
 * does not have to be separately tracked, and also stores the exact
 * allocation size in page->private so that it can be used to accurately
 * provide ksize(). These objects are detected in kfree() because slob_page()
 * is false for them.
 *
 * Sources:  
 Chapter 8 (Memory Management) of book: Daniel P.
 Bovet, Marco Cesati. Understanding the
 Linux Kernel, Third Edition, ISBN: 978-0596005658.
 • The file header for
 mm/slob.c
 *
 * http://lxr.free-electrons.com/source/mm/slob.c
 *
 */
 



#include <linux/linkage.h> 
#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/swap.h> /* struct reclaim_state */
#include <linux/cache.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/rcupdate.h>
#include <linux/list.h>
#include <linux/kmemleak.h>

#include <trace/events/kmem.h>

#include <asm/atomic.h>

/*
 * slob_block has a field 'units', which indicates size of block if +ve,
 * or offset of next block if -ve (in SLOB_UNITs).
 *
 * Free blocks of size 1 unit simply contain the offset of the next block.
 * Those with larger size contain their size in the first SLOB_UNIT of
 * memory, and the offset of the next free block in the second SLOB_UNIT.
 */
#if PAGE_SIZE <= (32767 * 2)
typedef s16 slobidx_t;
#else
typedef s32 slobidx_t;
#endif

struct slob_block {
    slobidx_t units;
};
typedef struct slob_block slob_t;

/*
 * We use struct page fields to manage some slob allocation aspects,
 * however to avoid the horrible mess in include/linux/mm_types.h, we'll
 * just define our own struct page type variant here.
 */
struct slob_page {
    union {
        struct {
            unsigned long flags;	/* mandatory */
            atomic_t _count;	/* mandatory */
            slobidx_t units;	/* free units left in page */
            unsigned long pad[2];
            slob_t *free;		/* first free slob_t in page */
            struct list_head list;	/* linked list of free pages */
        };
        struct page page;
    };
};
static inline void struct_slob_page_wrong_size(void)
{ BUILD_BUG_ON(sizeof(struct slob_page) != sizeof(struct page)); }

/*
 * free_slob_page: call before a slob_page is returned to the page allocator.
 */
static inline void free_slob_page(struct slob_page *sp)
{
    reset_page_mapcount(&sp->page);
    sp->page.mapping = NULL;
}




//*************************
// LAB3 Global Variables
//************************
int position = 0; // position in the actual list 
long saved_position = 0;// keeps track of last position in array
long current_position = 0; // keeps track in actual position in array 
long free_mem[100];// for system call average
size_t mem_claimd[100]; // for system call average
long allocationNewCount = 0; //count for each new allocation 
long allocationCount = 0; //to keep track of not needed page allocations
//*************************
// LAB3 Global Variables
//************************



/*
 * All partially free slob pages go on these lists.
 */
#define SLOB_BREAK1 256
#define SLOB_BREAK2 1024
static LIST_HEAD(free_slob_small);
static LIST_HEAD(free_slob_medium);
static LIST_HEAD(free_slob_large);

/*
 * is_slob_page: True for all slob pages (false for bigblock pages)
 */

static inline int is_slob_page(struct slob_page *sp)
{
    return PageSlab((struct page *)sp);
}

static inline void set_slob_page(struct slob_page *sp)
{
    __SetPageSlab((struct page *)sp);
}

static inline void clear_slob_page(struct slob_page *sp)
{
    __ClearPageSlab((struct page *)sp);
}

static inline struct slob_page *slob_page(const void *addr)
{
    return (struct slob_page *)virt_to_page(addr);
}

/*
 * slob_page_free: true for pages on free_slob_pages list.
 */
static inline int slob_page_free(struct slob_page *sp)
{
    return PageSlobFree((struct page *)sp);
}

static void set_slob_page_free(struct slob_page *sp, struct list_head *list)
{
    list_add(&sp->list, list);
    __SetPageSlobFree((struct page *)sp);
}

static inline void clear_slob_page_free(struct slob_page *sp)
{
    list_del(&sp->list);
    __ClearPageSlobFree((struct page *)sp);
}

#define SLOB_UNIT sizeof(slob_t)
#define SLOB_UNITS(size) (((size) + SLOB_UNIT - 1)/SLOB_UNIT)
#define SLOB_ALIGN L1_CACHE_BYTES

/*
 * struct slob_rcu is inserted at the tail of allocated slob blocks, which
 * were created with a SLAB_DESTROY_BY_RCU slab. slob_rcu is used to free
 * the block using call_rcu.
 */
struct slob_rcu {
    struct rcu_head head;
    int size;
};

/*
 * slob_lock protects all slob allocator structures.
 */
static DEFINE_SPINLOCK(slob_lock);

/*
 * Encode the given size and next info into a free slob block s.
 */
static void set_slob(slob_t *s, slobidx_t size, slob_t *next)
{
    slob_t *base = (slob_t *)((unsigned long)s & PAGE_MASK);
    slobidx_t offset = next - base;
    
    if (size > 1) {
        s[0].units = size;
        s[1].units = offset;
    } else
        s[0].units = -offset;
}

/*
 * Return the size of a slob block.
 */
static slobidx_t slob_units(slob_t *s)
{
    if (s->units > 0)
        return s->units;
    return 1;
}

/*
 * Return the next free slob block pointer after this one.
 */
static slob_t *slob_next(slob_t *s)
{
    slob_t *base = (slob_t *)((unsigned long)s & PAGE_MASK);
    slobidx_t next;
    
    if (s[0].units < 0)
        next = -s[0].units;
    else
        next = s[1].units;
    return base+next;
}

/*
 * Returns true if s is the last free block in its page.
 */
static int slob_last(slob_t *s)
{
    return !((unsigned long)slob_next(s) & ~PAGE_MASK);
}

static void *slob_new_pages(gfp_t gfp, int order, int node)
{
    void *page;
    
#ifdef CONFIG_NUMA
    if (node != -1)
        page = alloc_pages_exact_node(node, gfp, order);
    else
#endif
        page = alloc_pages(gfp, order);
    
    if (!page)
        return NULL;
    
    return page_address(page);
}

static void slob_free_pages(void *b, int order)
{
    if (current->reclaim_state)
        current->reclaim_state->reclaimed_slab += 1 << order;
    free_pages((unsigned long)b, order);
}



/*
 * Allocate a slob block within a given slob_page sp.
 */
static void *slob_page_alloc(struct slob_page *sp, size_t size, int align)
{
    slob_t *prev, *cur, *aligned = NULL;
    int delta = 0, units = SLOB_UNITS(size);
    
    for (prev = NULL, cur = sp->free; ; prev = cur, cur = slob_next(cur)) {
        slobidx_t avail = slob_units(cur);
        
        if (align) {
            aligned = (slob_t *)ALIGN((unsigned long)cur, align);
            delta = aligned - cur;
        }
        if (avail >= units + delta) { /* room enough? */
            slob_t *next;
            
            if (delta) { /* need to fragment head to align? */
                next = slob_next(cur);
                set_slob(aligned, avail - delta, next);
                set_slob(cur, delta, aligned);
                prev = cur;
                cur = aligned;
                avail = slob_units(cur);
            }
            
            next = slob_next(cur);
            if (avail == units) { /* exact fit? unlink. */
                if (prev)
                    set_slob(prev, slob_units(prev), next);
                else
                    sp->free = next;
            } else { /* fragment */
                if (prev)
                    set_slob(prev, slob_units(prev), cur + units);
                else
                    sp->free = cur + units;
                set_slob(cur + units, avail - units, next);
            }
            
            sp->units -= units;
            if (!sp->units)
                clear_slob_page_free(sp);
            return cur;
        }
        if (slob_last(cur))
            return NULL;
    }
}








/*
 This is a modified version on the page_alloc function
 This returns the slob with the best fit given a page sp  according to its units
 */
static void *alloc_best_page(struct slob_page *sp, size_t size, int align)
{
    slob_t *best_page_fit  = NULL; //the current best page
    
    slob_t *prev, *cur, *aligned = NULL;// pointers for traversing
    int delta = 0, units = SLOB_UNITS(size);// size parameters
    
    //travese blocks to find best page 
    for (prev = NULL, cur = sp->free; ; prev = cur, cur = slob_next(cur)) {
        slobidx_t avail = slob_units(cur);// number of units in this block
        
        //finds delta
        if (align) {
            aligned = (slob_t *)ALIGN((unsigned long)cur, align);
            delta = aligned - cur;
        }
        //if this page has enough space
        if(avail >= units + delta)// if there is enough room
	{
            if(best_page_fit == NULL)// and there is no best if
            {
                best_page_fit = cur; // set a best fit
            }
	// otherwise if the size available is smaller than the current
            // and we have not found one greater
            else if ((best_page_fit != NULL) && (avail < slob_units(best_page_fit ))){
                best_page_fit = cur;// reset the best fit to the current
            }
        }
        if(slob_last(cur)) // if the pointer is in the last position, we stop traversing
            break;// found best page, return
    }
    
  // this code mirrors slob_page_alloc since it does not select a specific page
    // we eventually return the best page
    aligned = NULL;
    delta = 0;
    units = SLOB_UNITS(size);
    for (prev = NULL, cur = sp->free; ; prev = cur, cur = slob_next(cur)) {
        slobidx_t avail = slob_units(cur);
        
        if (align) {
            aligned = (slob_t *)ALIGN((unsigned long)cur, align);
            delta = aligned - cur;
        }
        if ((avail >= units + delta) && (best_page_fit == cur)) { /* room enough? */
            slob_t *next;
            
            if (delta) { /* need to fragment head to align? */
                next = slob_next(cur);
                set_slob(aligned, avail - delta, next);
                set_slob(cur, delta, aligned);
                prev = cur;
                cur = aligned;
                avail = slob_units(cur);
            }
            
            next = slob_next(cur);
            if (avail == units) { /* exact fit? unlink. */
                if (prev)
                    set_slob(prev, slob_units(prev), next);
                else
                    sp->free = next;
            } else { /* fragment */
                if (prev)
                    set_slob(prev, slob_units(prev), cur + units);
                else
                    sp->free = cur + units;
                set_slob(cur + units, avail - units, next);
            }
            
            sp->units -= units;
            if (!sp->units)
                clear_slob_page_free(sp);
            return cur;
        }
        if (slob_last(cur))
            return NULL;
    }
}

























/*
 * Allocate a slob block within a given slob_page sp.
 // this uses first fit algorithm
 */
static void *locate_best_block(struct slob_page *sp, size_t size, int align)
{
    
    slob_t *best_block  = NULL; //the current page with the best size
    
    slob_t *prev, *cur, *aligned = NULL;// declare pointers for traversal
    int delta = 0, units = SLOB_UNITS(size);// declare variables for sizes
    
       //traverse the blocks in the best page
    for (prev = NULL, cur = sp->free; ; prev = cur, cur = slob_next(cur)) {
        slobidx_t avail = slob_units(cur);
        
        //finds delta
        if (align) {
            aligned = (slob_t *)ALIGN((unsigned long)cur, align);
            delta = aligned - cur;
        }
         //check for page availability
        if(avail >= units + delta){
            if(best_block == NULL)
            {
                best_block = cur;
            }
  	     // if the number of units is less than the one available
            // and block isint already set
            else if ((best_block != NULL) && (avail < slob_units(best_block ))){
                best_block = cur;
            }
        }
        
        if(slob_last(cur))
            break;
    }
    
    return best_block;// return the adaquet block in the current page
    
    
}



/*
 * slob_alloc: entry point into the slob allocator.
 */
static void *slob_alloc(size_t size, gfp_t gfp, int align, int node)
{
    
    struct slob_page *best_page = NULL; // pointer to the best page
    slob_t *best_block = NULL; // pointer to the best lblock
    slob_t *curr_block; // pointer to the best block for the sp page
    
    slobidx_t current_available; // pointer to traverse the page
    slobidx_t best_fit_available;
    
    struct slob_page *sp;
    struct list_head *prev;// pointer to access previous block in list
    struct list_head *slob_list;//pointer for  accessing block list
    slob_t *b = NULL;// pointer  to the best page returned by our function
    unsigned long flags;
    long unitCounter = 0;// for system call .. counts free units 
    
    if (size < SLOB_BREAK1)
        slob_list = &free_slob_small; // interested in this list
    else if (size < SLOB_BREAK2)
        slob_list = &free_slob_medium;
    else
        slob_list = &free_slob_large;
    
    spin_lock_irqsave(&slob_lock, flags);// to protect struct variables


    /* Iterate through each partially free page, try to find room */
    
    if(slob_list == &free_slob_small) 
	{ allocationNewCount++; }
    
    list_for_each_entry(sp, slob_list, list) // traverse the pages
 {
#ifdef CONFIG_NUMA
        /*
         * If there's a node specification, search for a partial
         * page with a matching node id in the freelist.
         */
        if (node != -1 && page_to_nid(&sp->page) != node)
            continue;
#endif
        /* Enough room on this page? */
        if (sp->units < SLOB_UNITS(size))
        {
            //count total free units in the small list
            if(slob_list == &free_slob_small)
                unitCounter = unitCounter + sp->units;
            
            continue;
        }
        
        // algorithm saves best page until it is replaced by new best page
        
        if(best_page == NULL)// if we do not yet have a best page
        {
                 // check this page for a fitting block
            curr_block = locate_best_block(sp,size,align);
            
            //if it exists save its value and save this page as the best fit
            if(curr_block != NULL)

		{  best_block = curr_block; 

		 best_page = sp;
	        }
            
            else
                continue;
        }
       
        else // check this page with previous page

	{
		//see if we found a block that fits 
            curr_block = locate_best_block(sp,size,align);
            
        
            if(curr_block != NULL)
            {

     		 //found a new best block 
                current_available = slob_units(curr_block);
                best_fit_available = slob_units(best_block);
                
      
                if(current_available < best_fit_available)// check if  this should be the best block
		{
			// make page best fit and
                    best_page = sp;
                    best_block = curr_block;
                }
            }
        }
       
    }

	// same algorithm as first fit to get new page

    if(best_page != NULL){
        prev = best_page->list.prev;
        b = alloc_best_page(best_page, size, align); //changed to best fit
        
        
 
        if (prev != slob_list->prev &&
            slob_list->next != prev->next)
            list_move_tail(slob_list, prev->next);
    }
    
    spin_unlock_irqrestore(&slob_lock, flags);
    
    /* Not enough space: must allocate a new page */
    if (!b) {
        b = slob_new_pages(gfp & ~__GFP_ZERO, 0, node);
        if (!b)
            return NULL;
        
        // system call code 
       
        if (slob_list == &free_slob_small) // assert we are in the free_slob_small list
        {
            if(saved_position != 100) // check for array boundary
                saved_position++;// if we are not at the end increment
            
           
            position = (current_position + 100) % 100; // keep the position with the bondary
            
           //add the claimed value to the array and add the total free units to its array
            mem_claimd[position] = size;// update claimed
            free_mem[position] = (unitCounter*SLOB_UNIT + 1) - SLOB_UNIT; // update free memory based on page
            current_position++;// for array boundary
            
        }
        
        
        sp = slob_page(b);// update pointer to newly allocated page
        set_slob_page(sp);// update pointer to newly allocated page
        

	// set new pointer variable values
        spin_lock_irqsave(&slob_lock, flags);// to protect variables
        sp->units = SLOB_UNITS(PAGE_SIZE);
        sp->free = b;
        INIT_LIST_HEAD(&sp->list);
        set_slob(b, SLOB_UNITS(PAGE_SIZE), b + SLOB_UNITS(PAGE_SIZE));
        set_slob_page_free(sp, slob_list);
        b = slob_page_alloc(sp, size, align);
        BUG_ON(!b);
        spin_unlock_irqrestore(&slob_lock, flags);// done protecting form sycnrhonization problems
    }
    if (unlikely((gfp & __GFP_ZERO) && b))
        memset(b, 0, size);
    return b;
}

/*
 * slob_free: entry point into the slob allocator.
 */
static void slob_free(void *block, int size)
{
    struct slob_page *sp;
    slob_t *prev, *next, *b = (slob_t *)block;
    slobidx_t units;
    unsigned long flags;
    struct list_head *slob_list;
    
    if (unlikely(ZERO_OR_NULL_PTR(block)))
        return;
    BUG_ON(!size);
    
    sp = slob_page(block);
    units = SLOB_UNITS(size);
    
    spin_lock_irqsave(&slob_lock, flags);
    
    if (sp->units + units == SLOB_UNITS(PAGE_SIZE)) {
        /* Go directly to page allocator. Do not pass slob allocator */
        if (slob_page_free(sp))
            clear_slob_page_free(sp);
        spin_unlock_irqrestore(&slob_lock, flags);
        clear_slob_page(sp);
        free_slob_page(sp);
        slob_free_pages(b, 0);
        return;
    }
    
    if (!slob_page_free(sp)) {
        /* This slob page is about to become partially free. Easy! */
        sp->units = units;
        sp->free = b;
        set_slob(b, units,
                 (void *)((unsigned long)(b +
                                          SLOB_UNITS(PAGE_SIZE)) & PAGE_MASK));
        if (size < SLOB_BREAK1)
            slob_list = &free_slob_small;
        else if (size < SLOB_BREAK2)
            slob_list = &free_slob_medium;
        else
            slob_list = &free_slob_large;
        set_slob_page_free(sp, slob_list);
        goto out;
    }
    
    /*
     * Otherwise the page is already partially free, so find reinsertion
     * point.
     */
    sp->units += units;
    
    if (b < sp->free) {
        if (b + units == sp->free) {
            units += slob_units(sp->free);
            sp->free = slob_next(sp->free);
        }
        set_slob(b, units, sp->free);
        sp->free = b;
    } else {
        prev = sp->free;
        next = slob_next(prev);
        while (b > next) {
            prev = next;
            next = slob_next(prev);
        }
        
        if (!slob_last(prev) && b + units == next) {
            units += slob_units(next);
            set_slob(b, units, slob_next(next));
        } else
            set_slob(b, units, next);
        
        if (prev + slob_units(prev) == b) {
            units = slob_units(b) + slob_units(prev);
            set_slob(prev, units, slob_next(b));
        } else
            set_slob(prev, slob_units(prev), b);
    }
out:
    spin_unlock_irqrestore(&slob_lock, flags);
}

/*
 * End of slob allocator proper. Begin kmem_cache_alloc and kmalloc frontend.
 */

void *__kmalloc_node(size_t size, gfp_t gfp, int node)
{
    unsigned int *m;
    int align = max(ARCH_KMALLOC_MINALIGN, ARCH_SLAB_MINALIGN);
    void *ret;
    
    lockdep_trace_alloc(gfp);
    
    if (size < PAGE_SIZE - align) {
        if (!size)
            return ZERO_SIZE_PTR;
        
        m = slob_alloc(size + align, gfp, align, node);
        
        if (!m)
            return NULL;
        *m = size;
        ret = (void *)m + align;
        
        trace_kmalloc_node(_RET_IP_, ret,
                           size, size + align, gfp, node);
    } else {
        unsigned int order = get_order(size);
        
        ret = slob_new_pages(gfp | __GFP_COMP, get_order(size), node);
        if (ret) {
            struct page *page;
            page = virt_to_page(ret);
            page->private = size;
        }
        
        trace_kmalloc_node(_RET_IP_, ret,
                           size, PAGE_SIZE << order, gfp, node);
    }
    
    kmemleak_alloc(ret, size, 1, gfp);
    return ret;
}
EXPORT_SYMBOL(__kmalloc_node);

void kfree(const void *block)
{
    struct slob_page *sp;
    
    trace_kfree(_RET_IP_, block);
    
    if (unlikely(ZERO_OR_NULL_PTR(block)))
        return;
    kmemleak_free(block);
    
    sp = slob_page(block);
    if (is_slob_page(sp)) {
        int align = max(ARCH_KMALLOC_MINALIGN, ARCH_SLAB_MINALIGN);
        unsigned int *m = (unsigned int *)(block - align);
        slob_free(m, *m + align);
    } else
        put_page(&sp->page);
}
EXPORT_SYMBOL(kfree);

/* can't use ksize for kmem_cache_alloc memory, only kmalloc */
size_t ksize(const void *block)
{
    struct slob_page *sp;
    
    BUG_ON(!block);
    if (unlikely(block == ZERO_SIZE_PTR))
        return 0;
    
    sp = slob_page(block);
    if (is_slob_page(sp)) {
        int align = max(ARCH_KMALLOC_MINALIGN, ARCH_SLAB_MINALIGN);
        unsigned int *m = (unsigned int *)(block - align);
        return SLOB_UNITS(*m) * SLOB_UNIT;
    } else
        return sp->page.private;
}
EXPORT_SYMBOL(ksize);

struct kmem_cache {
    unsigned int size, align;
    unsigned long flags;
    const char *name;
    void (*ctor)(void *);
};

struct kmem_cache *kmem_cache_create(const char *name, size_t size,
                                     size_t align, unsigned long flags, void (*ctor)(void *))
{
    struct kmem_cache *c;
    
    c = slob_alloc(sizeof(struct kmem_cache),
                   GFP_KERNEL, ARCH_KMALLOC_MINALIGN, -1);
    
    if (c) {
        c->name = name;
        c->size = size;
        if (flags & SLAB_DESTROY_BY_RCU) {
            /* leave room for rcu footer at the end of object */
            c->size += sizeof(struct slob_rcu);
        }
        c->flags = flags;
        c->ctor = ctor;
        /* ignore alignment unless it's forced */
        c->align = (flags & SLAB_HWCACHE_ALIGN) ? SLOB_ALIGN : 0;
        if (c->align < ARCH_SLAB_MINALIGN)
            c->align = ARCH_SLAB_MINALIGN;
        if (c->align < align)
            c->align = align;
    } else if (flags & SLAB_PANIC)
        panic("Cannot create slab cache %s\n", name);
    
    kmemleak_alloc(c, sizeof(struct kmem_cache), 1, GFP_KERNEL);
    return c;
}
EXPORT_SYMBOL(kmem_cache_create);

void kmem_cache_destroy(struct kmem_cache *c)
{
    kmemleak_free(c);
    if (c->flags & SLAB_DESTROY_BY_RCU)
        rcu_barrier();
    slob_free(c, sizeof(struct kmem_cache));
}
EXPORT_SYMBOL(kmem_cache_destroy);

void *kmem_cache_alloc_node(struct kmem_cache *c, gfp_t flags, int node)
{
    void *b;
    
    if (c->size < PAGE_SIZE) {
        b = slob_alloc(c->size, flags, c->align, node);
        trace_kmem_cache_alloc_node(_RET_IP_, b, c->size,
                                    SLOB_UNITS(c->size) * SLOB_UNIT,
                                    flags, node);
    } else {
        b = slob_new_pages(flags, get_order(c->size), node);
        trace_kmem_cache_alloc_node(_RET_IP_, b, c->size,
                                    PAGE_SIZE << get_order(c->size),
                                    flags, node);
    }
    
    if (c->ctor)
        c->ctor(b);
    
    kmemleak_alloc_recursive(b, c->size, 1, c->flags, flags);
    return b;
}
EXPORT_SYMBOL(kmem_cache_alloc_node);

static void __kmem_cache_free(void *b, int size)
{
    if (size < PAGE_SIZE)
        slob_free(b, size);
    else
        slob_free_pages(b, get_order(size));
}

static void kmem_rcu_free(struct rcu_head *head)
{
    struct slob_rcu *slob_rcu = (struct slob_rcu *)head;
    void *b = (void *)slob_rcu - (slob_rcu->size - sizeof(struct slob_rcu));
    
    __kmem_cache_free(b, slob_rcu->size);
}

void kmem_cache_free(struct kmem_cache *c, void *b)
{
    kmemleak_free_recursive(b, c->flags);
    if (unlikely(c->flags & SLAB_DESTROY_BY_RCU)) {
        struct slob_rcu *slob_rcu;
        slob_rcu = b + (c->size - sizeof(struct slob_rcu));
        slob_rcu->size = c->size;
        call_rcu(&slob_rcu->head, kmem_rcu_free);
    } else {
        __kmem_cache_free(b, c->size);
    }
    
    trace_kmem_cache_free(_RET_IP_, b);
}
EXPORT_SYMBOL(kmem_cache_free);

unsigned int kmem_cache_size(struct kmem_cache *c)
{
    return c->size;
}
EXPORT_SYMBOL(kmem_cache_size);

const char *kmem_cache_name(struct kmem_cache *c)
{
    return c->name;
}
EXPORT_SYMBOL(kmem_cache_name);

int kmem_cache_shrink(struct kmem_cache *d)
{
    return 0;
}
EXPORT_SYMBOL(kmem_cache_shrink);

int kmem_ptr_validate(struct kmem_cache *a, const void *b)
{
    return 0;
}

static unsigned int slob_ready __read_mostly;

int slab_is_available(void)
{
    return slob_ready;
}

void __init kmem_cache_init(void)
{
    slob_ready = 1;
}

void __init kmem_cache_init_late(void)
{
    /* Nothing to do */
}


asmlinkage long sys_user_call(int size)
{
    if( (kmalloc(sizeof(char)*size,GFP_KERNEL)) == NULL)
    {
        printk("sys_slob_user_alloc() error allocating %d space\n",size);
    }
}


asmlinkage long sys_get_slob_amt_claimed(void)
{
    long result=0;
    int i;
    //add the last 100 (200) elements
    for(i = 0; i < saved_position; i++)	{
        result = result + mem_claimd[i];
    }
    return result/saved_position;
}

asmlinkage long sys_get_slob_amt_free(void)
{
    long result=0;
    int i;
    //add the last 100 (200) elements
    for(i = 0; i < saved_position; i++){	
        result = result + free_mem[i];
    }
    
    return result/saved_position;
    
}
