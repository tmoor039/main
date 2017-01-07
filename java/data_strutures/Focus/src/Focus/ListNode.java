package Focus;
/**
 *Created by Tiago Moore on Sep 27, 2014.
 *  Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * 
 */

/**
 * This is a ListNode class to be used with the Dequeue Class 
 * @author Tiago Moore
 * @param <T> the generic type
 */
public class ListNode <T>
{
  //instance variables
  public ListNode<T> next; // a reference to another node i.e the next node
  public T data; // a data variable of the type specified when node is created
   
  /**
   * Constructor creates a new Node following parameters
   * @param data the Data value of the current node
   * @param node a reference to the following node 
   */
  public ListNode(T data, ListNode node)
  {
    this.data = data;
    this.next = node; 
  }
  public ListNode()
  {
    
    data = null; 
    next = null; 
  }
  
}
