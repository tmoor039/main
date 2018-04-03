
/**
 *Created by Tiago Moore on Sep 27, 2014.
 *Reviewed 29 Mar 2018 
 * 
 */
package Focus;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Class to assist provide access to aggregated data at a higher level of abstraction
 * @author tmoore
 */
public class DequeIterator<T> implements Iterator<T>
{
  private ListNode<T> nextNode;
  private ListNode<T> head; 
  
  /**
   * Constructor
   * @param head is the head of the list
   */
  public DequeIterator(ListNode<T> head)
  {
    this.head = head;
    nextNode = head; 
    
  }
  
  /**
   * Returns true if there is another element in the linked list false otherwise 
   */
  public boolean hasNext()
  {
	  // if either the first or second list nodes are a null value - then there are no next nodes and return false 
    if(head==null ||head.next == null )
    {
      return false; 
    }
    else 
    {
      return true; 
    }

  }

  /**
   * Object to get the next object of the list
   * @return the data of the next object in the list....... 
   * Do we care about the data of the next or the object itelself ? depends on what the implementation is asking for  
   */
  public T next()
  {
    if(nextNode == null)
    {
      throw new NoSuchElementException();
    }
   
    nextNode = nextNode.next;
    return nextNode.data;

  }

  /**
   * This method will run O(n) times since it will only 
   * traverse the list always looking two items ahead 
   */
  public void remove()
  {
    // create a temp node for a reference to the next node
    ListNode<T> temp = nextNode;

    //
    if(head.next == null)// if there is only one element 
    {
      head.data = null;// remove it 
    }
    // traverse the list until the next element is null (i.e it has reached the end )
    while(temp.next.next!= null)
    {
        temp = temp.next;
    }
    
    // set the pointer of the next node to null
    // disconnecting it from the list
    temp.next = null;
  }

}
