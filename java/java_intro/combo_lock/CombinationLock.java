
/**
 *Created by Tiago Moore on Oct 15, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
/**
 * A class to implement a combination lock with 26 dial positions
 * and a three-letter combination
 * 
 * @author your name
 */
public class CombinationLock
{
   String first,second,third, s1,s2,s3;
   int count;
   boolean open ;;
    
  /**
   * Creates a lock with a given combination consisting of three upper-case characters.
   * @param first the first letter of the combination
   * @param second the second letter of the combination
   * @param third the third letter of the combination
   */
   public CombinationLock(String first, String second, String third)
   {
       
       
     count = 0; 
     open = false;
     this.first = first;
     s1= first;
     this.second = second;
     s2 = second;
     this.third = third; 
     s3 = third;


   }

  /**
   * Set the dial to a position
   * @param aPosition a String consisting of a single uppercase letter (A..Z)
   */
   public void setPosition(String aPosition)
   {
    
do
{        
            // incriment counter
             count++;  
            
       if (count ==1)
       {
           first = aPosition;
       }
       else if (count ==2)
       {
           second = aPosition;
       }
       
       else if(count ==3)
       {
           third =aPosition;
       }
       
     else
       {
           count = 0;
       }
   // assert that if the counter goes over 3 it goes back to first position    
} while( count != 1 && count != 2 && count != 3);
   }

  /**
   * Try opening the lock
   */
   public void tryToOpen()
   {
        // if all conditions are true, open lock 
       if(s1.equals(first)&& s2.equals(second)&& s3.equals(third))
       {
           open = true;
       }
       else 
       {
           open = false;
       }

   }
  /**
   * Check whether the lock is open
   * @return true or false indicating whether the lock is open
   */
   public boolean isOpen()
   {
       // returns a boolean value, true or false
       return open;
   
   }

  /**
   * Close the lock and print a message indicating that the lock is now closed
   */
   public void lock()
   {
        // reset lock to false, and counter back to 0 
       open = false; 
       count = 0 ;
       
       System.out.print("Lock has been closed by default. ");
   
   }
}