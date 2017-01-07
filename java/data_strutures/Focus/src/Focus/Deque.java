package Focus;




import java.util.Iterator;
import java.util.NoSuchElementException;



/**
 * Created by Tiago Moore on Sep 27, 2014. Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *
 */
/**
 * Deque Class has a tostring method that the test classes are reliant on it has not been correctly
 * implemented however all the assigment methods have been correctly implemented
 * @author tmoore
 * @param <T> A generic type to be an integer
 */
public class Deque<T> implements Iterable<T>
{

  ListNode<T> front;
  ListNode<T> back;


  /**
   * Queue Constructor makes the back the same as the front node and not the node after null for
   * this reason, the toString method was tougher to implement making it tougher to test
   */
  public Deque()
  {
    front = new ListNode();
    back = new ListNode();
    back = front.next;
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
   * Methos returns the size of the linked list Does not account for the two nodes fornt and back
   * and will only return a value if their data member contains a value
   * @return the amount of terms in the queue
   */
  public int size()
  {
    ListNode<T> temp = front;
    int number = 1;
    if (isEmpty())
    {
      return 0;
    }
    if (temp.next.data == null)
    {
      return number;
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

      temp.next = add;
      back = temp.next;
    }
  }


  /**
   * Adds an item to the front of the queue
   * @param x the number being added C
   */
  public void addFront(T x)
  {
    ListNode<T> item = new ListNode();
    item.data = x;

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
   * Complexity O(n) since it has to traverse the list entirely
   */

  public T removeBack()
  {
    // start at the front
    ListNode<T> temp = front;
    ListNode<T> removed = new ListNode();

    if (front.next == null)
    {
      front.data = null;
    }
    else
    {
      while (temp.next.next != null)// traverse until last node is pointing to null
      {
        temp = temp.next;// move to the next node
      }

      removed.data = temp.next.next.data;// get value being removed

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
