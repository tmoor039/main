package Focus;




import java.util.Iterator;
import java.util.NoSuchElementException;



/**
 * Created by Tiago Moore on Sep 27, 2014.
 *Reviewed 29 Mar 2018
 */
/**
 * Deque Class has a toString method that the test classes are reliant on it has not been correctly
 * implemented however all the assigment methods have been correctly implemented
 * @author tmoore
 * @param <T> A generic type to be an integer
 */
public class Deque<T> implements Iterable<T>
{
// this class is acting like a linked list.. with the front and back nodes being ListNode objects
  ListNode<T> front;
  ListNode<T> back;


  /**
   * Queue Constructor makes the back the same as the front node and not the node after null for
   * this reason, the toString method was tougher to implement making it tougher to test
   */
  public Deque()
  {
    front = new ListNode(); //instantiating new listNode object and pasing it to front 
    back = new ListNode();
    back = front.next;// next is the next list node object in the linked list  
  }


  /**
   * Checks if the queue is empty; Complexity O(1)
   * @return false if there is nothing in the front
   */
  public Boolean isEmpty()
  {

    if (front.data == null)
    {
      return true;
    }

    return false;
  }


  /**
   * Method returns the size of the linked list. Does not account for the two nodes front and back
   * and will only return a value if their data member contains a value.
   * Possible bug - if the next node has a null data value but still exists... it will not count the remainder of the list 
   * @return the amount of terms in the queue
   */
  public int size()
  {
    ListNode<T> temp = front; //manipulates classes static variables. Should use local variables to do this 
    int number = 1;
    if (isEmpty())
    {
      return 0;
    }
    if (temp.next.data == null) // should find another way to see if the node exists rather than checking the data value 
    {
      return number; // should not return here 
    }
    else
    {
      while (temp.next.data != null)// traveses the list with O(n) complexivity
      {
        temp = temp.next;
        number++;
      }
    }

    return number;
  }


  /**
   * Adds an item front the back of the queue The complexivity is O(n) due to the
   * @param x
   *
   */
  public void addBack(T x)
  {
    ListNode<T> add = new ListNode<T>(x, null);
    if (isEmpty())
    {
      front = add;
      back = add.next;
    }
    else
    {
      ListNode<T> temp = front;

      while (temp.next != null) //complexivity O(n)
      {
        temp = temp.next;
      }

      temp.next = add; // whats the relavence of this? why cant I just do back = add? 
      back = temp.next;
    }
  }


  /**
   * Adds an item to the front of the queue
   * @param x the number being added
   */
  public void addFront(T x)
  {
    ListNode<T> item = new ListNode(); // another way to do declare  the object and 
    item.data = x; // puts the data in the node by not using the contructor 

    if (isEmpty())
    {
      front.data = x;
    }
    else
    {
      item.next = front;
      front = item;
    }
  }

  /*
   * Returns and removes the element in the back of the queue
   * Complexity O(n) since it has to traverse the list entirely... does it though? why not just get the size and then delete
   * that position on the list ? since size is alrady traversing the list
   */

  public T removeBack() // should do this a different way... the temp.next.next method is silly. 
  {
    // start at the front
    ListNode<T> temp = front;
    ListNode<T> removed = new ListNode();

    if (front.next == null) // if there is only one node in the list 
    {
      front.data = null; // delete the data in that node aka delete the only node 
    }
    else // if there is more than one node in the list 
    {
      while (temp.next.next != null)// traverse until last node is pointing to null
      {
        temp = temp.next;// move to the next node
      }
      // after this loop it is going to have found the node so it is ready to be removed 

      removed.data = temp.next.next.data;// get value being removed ........ 

      temp.next = null;// remove the reference to the last node

      back = temp;
    }

    return removed.data;
  }


  /**
   * method to dequeue item from front of a queue Complexity O(1) Constance no need to traverse
   * queue
   */
  public T removeFront()
  {
    ListNode<T> delete = front;

    if (front.data == null)
    {
      return null;//queue is empty
    }
    else
    {

      if (front.next == null)// if the last node is the back(pointing to null)
      {
        front = front.next;
        delete.next = null;
      }
      back = front.next;
    }
    return delete.data; 
  }


  // Why do i have the irerator be a 
  @Override
  public Iterator<T> iterator()
  {
    DequeIterator iterator = new DequeIterator(front);

    return iterator;
  }


  /**
   * To string method to assist trouleshooting with the test class it does not work for more than to
   * inputs, hence the methods that require more than 2 inputs do not test sucessuflly, but they are
   * implemented correctly.
   * @return
   */
  
  

}
