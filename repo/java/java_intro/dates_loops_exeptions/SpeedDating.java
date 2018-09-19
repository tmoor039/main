
import apple.laf.JRSUIConstants;
import javax.swing.JOptionPane;
import sun.net.www.content.image.gif;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Nov 5, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
/**
 * A class to give students experience using loops.  This class
 * creates and manipulates objects of Greg's Date class.
 */
 public  class SpeedDating
 {
    // Note: this class has no instance variables!
 	
    /**
     * Create an empty SpeedDating object
     */
     public SpeedDating()
     {}	   // Constructor has empty body
           // (this is known as a "default" constructor)
 	
    /**
     * Computes and returns the next year in which New Year's Day will
     * fall on the same day of the week as in a given year
     * @param theYear the given year
     * @return the next year in which New Year's day is the same day
     * of the week as in parameter theYear
     */
     public int auldLangSynch(int theYear)
     {
         String day = " ";
           String day2 = " ";
         //create a new object with given year 
       Date NewYear = new Date(1,1, theYear);
         //get objects day for the given year 
       day = NewYear.getDayOfWeek();
      
       // create one for the following year and see if it matches
       Date NewYea = new Date(1, 1, theYear+1);
       
       day2 = NewYea.getDayOfWeek();
  
   // while  objects  firsts day is not equal to the same day of the on entered
       
       while(!day.equals(day2))
       {
           // increment  the date until it reaches the first of the month and 
           // the same day as the orignal date
               NewYea.add(365);
               day2 = NewYea.getDayOfWeek();
       }
       
      // when the days are the same, return the year that it will be the same 
       
       return NewYea.getYear();

         
     }
 	
    /**
     * Computes and returns the Date on which Election Day will fall 
     * in the USA for a given year.
     *
     * NOTE: By law, Election  Day is the first Tuesday after the first
     * Monday in November.
     *
     * @param year the year for which to compute the date of Election Day
     * @return the Date of Election Day for the specified year
     */
      public Date pollDancer(int year)
     {
       //count until monday
         
         String d1 = "";
         int count = 1;
         
         Date D1 = new Date(11, 1, year);
   
         d1 = D1.getDayOfWeek();
         // incriment the day hile its not the first monday of the week 
         while (!d1.equals("Monday"))
         {
             D1.next();
             d1 = D1.getDayOfWeek();
             count ++;
         }
         
         
         // count until tuesday
           while(!d1.equals("Tuesday"))
           {
               D1.next();
               d1 = D1.getDayOfWeek();
               count++;
           }
           
            // create new object with the total amount of days
           D1= new Date(11, count, year);
           
           //return the date
           return D1;

     }

 	 	
     /**
      * Computes and returns the corrected "Excel Date" for a given Date.
      * I.e., the number of the given Date where 1/1/1900 is date #1
      * 
      * @param aDate the Date for which to return the Excel Date
      * @return the Excel Date of parameter aDate 
      */
      public int iExcel(Date aDate) 
      {
            //create int to act as a counter
          int x = 1 ;
          
 	 // TO DO: write remainder of body of this method here
     
          //create new date object to start
          Date NewDate = new Date(1,1,1900);
          
          // while its not euqual to parameter date increment ont he number
          //and keep adding days 
          while(!NewDate.equals(aDate))
          {
              NewDate.next();
              x++;
          }
          
           // return the total number of times it incrimented 
          return x;
      }
 }

