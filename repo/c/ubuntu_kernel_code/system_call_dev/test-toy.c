//Tiago Moore
//COP 4610 Lab,Fall 2015
#include <linux/module.h>

static int hello_init(void)
{
 printk("Hello world, this is Tiago Moore\n");
 printk("Hello world, this is Tiago G Moore 2\n");
 printk("Hello world this is Tiago G C Moore\n");
  return 0;
}

static void hello_exit(void)
{
 printk("Goodbye world, this is Tiago Moore\n");
 printk("Goodbye world, this is Tiago G Moore 2\n");
 printk("Goodbye world, this is Tiago G C Moore 3\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("TMoore_COP4610_Lab1");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Modified_Hello_World");
