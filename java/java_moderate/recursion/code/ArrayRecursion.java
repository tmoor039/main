/**
Created 7 April 2014
Reviewed 6 June 2018
*TODO: Change start and count variable names 
 */

import java.util.* ;

/**
 * Class including methods that implement recursion
 * @author tmoore
 */
class ArrayRecursion
{
	// instance var's
	private int [] list ;		// array of ints
	private int count = 0 ;		// number of elements used
	private Random r ;
	
	/**
	 * Create an ArrayRecursion object.  
	 * Create an array with between 10 and 15 elements, and fill it with 
	 * random positive 2-digit ints
	 */
	public ArrayRecursion()
	{
		r = new Random() ;
		count = r.nextInt(6) + 10 ;
		list = new int[count] ;

		for (int i = 0 ; i < count ; i++)
		   list[i] = r.nextInt(90) + 10 ;
	}
	
	/*
	 * Return the list as a string
	 * @return a string containing all ints stored in list
	 */
	public String toString()
	{
		String out = "" ;
		for (int i = 0 ; i < count ; i++)
		   out += list[i] + "  " ;
		return out + "\n" ;
	}

	/**
	 * Reverse the order of the values stored in the list.
	 * (called by client to reverse list using first algorithm)
	 */
	public void reverse()
	{
		reverseRecurse(list, 0, count) ;
	}
	
	// recursive "helper" method to reverse the values stored in the list 
	// (called by public method reverse1())
	// uses the first list reversal algorithm
	private void reverseRecurse ( int[] list, int start, int count )
	{
         
            if (count-1 < start) // for the even number case
            {
               // do nothing
              // needed because if the array is even, count -1 will be less than start
              // in the final swap
            }
         
        
         
              //trivial case
               if(count-1  == start) // odd case
              {
               // needed if when all reversing has been done, if there is only one 
                 // element to swap with itself, stop
              }             
              else
              {
                int temp = list[start];// get a temp variable
                list[start] =list[count-1];// set the first as last
                list[count-1] = temp;   // set last as temp
                reverseRecurse(list, start, count-1);// do it again
               
              }       
	}
	
	/*
	 * Return the largest value in the array.
	 * @return the largest value in the array
	 */
	public int getIndexOfLargest()
	{                 

		return recursiveGetIndexOfLargest(list, count) ;
	}
	
	// recursive "helper" method to return largest value in the array
	// (called by public method getLargest())
	private int recursiveGetIndexOfLargest( int[] list, int count )
	{
                
         int largestIndex = 0;
         if(count == 1) 
         {
           return 0; // 0 is set as the smallest value
         }
         
         // compare all elements of inner array with last element of awway
         else

            // puts the method into a stack in memory
           // compared the valued returned to the last element in the array( in memory)
           // after it hit 1 or the trivial case, the stack being poped has a count-1
           // value of 2, so it compares the value of 0 to 1, and returns the largest
           // then compares the value of 2 and 3 and returnst he largest.. all the way to
           // the very first count -1 initially called above, essentially returning
           // the index of the largest portion compared to the last for the entire array
           largestIndex = recursiveGetIndexOfLargest(list, count-1);

           if(list[largestIndex] <= list[count-1])// if  we have a new largest
           {
           largestIndex = count-1; // keep track of it
           }
       
           return largestIndex; // return the new largest
         }

	/*
	 * Sort the array in ascending order using the selection sort
	 */
	public void sort()
	{
		recursiveSort(list, count) ;
	}
	
	// recursive "helper" method to sort the array
	// (called by public method sort())
	private void recursiveSort( int[] list, int count )
	{
 
         if(count == 1)
         {
           // do nothing 
         }
         
         else
         {
           // get the largest index
          int largest =recursiveGetIndexOfLargest(list, count);
          // swap last with largest
          int temp = list[count-1];
          list[count-1] = list[largest];
          list[largest] = temp;       
          recursiveSort(list, count-1);// do it again without the last element  
         }

	}	
}
