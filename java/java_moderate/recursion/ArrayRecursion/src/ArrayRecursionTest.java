 /**
 *
 *Created by Tiago Moore on Apr 7, 2014.
 *Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *Instructor: Greg Shaw Section 4
 *I affirm that this program is entirely my own work and none of it is the work 
 *of any other person.
 *
 * 
 * 
 *______________________________________________________________
 */

/**
 * A test class for the ArrayRecursion class
 */
public class ArrayRecursionTest
{
	public static void main(String[] args)
	{
		ArrayRecursion list = new ArrayRecursion();
		
		System.out.println("\nOriginal:  " + list);
		list.reverse() ;
		System.out.println("\nReversed:    " + list);
		System.out.println("Largest value is at index: " + list.getIndexOfLargest()) ;
		list.sort() ;
		System.out.println("\nSorted:    " + list);
	}
}