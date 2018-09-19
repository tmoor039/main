
import javax.swing.JOptionPane;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Nov 12, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
public class SpeedDatingTester

        {
          
             public static void main(String args[])
             {
                 // declare and initialize variables 
                 int year = 0, electionday = 0,d = 0,m= 0,y = 0, excelvalue =0 ;
                
             
                 
                  //create a speed dating object 
                 SpeedDating s = new SpeedDating();
            
                 // have the user enter a yhear 
                 String input = JOptionPane.showInputDialog("Enter the year: ");
                 year = Integer.parseInt(input);
                  //call the auldangsyn method to get the next year in which
                 //new years will fall on same day of week 
                 
                 // create a new date object 
                 Date Sameyear = new Date(1,1,year);
                
                 //print both the date and year election day will be the same 
                 System.out.println("Next year in  which the new years day will"
                         + "be on a "+ Sameyear.getDayOfWeek()
                         + " is : "+ 
                         s.auldLangSynch(year) );
                 // get data from user
                 input = JOptionPane.showInputDialog("Enter the year you would "
                         +"like to test for election day: ");
                electionday = Integer.parseInt(input);
                 
                //create a new date object with the most recent date as its year 
                Date  Electionday = new Date(1, 1, electionday);
                
                  // call poll dancer method 
                 Electionday = s.pollDancer(Electionday.getYear()); 
                 System.out.print("\nElection Day for the year "
                         +Electionday.getYear()
                         + " is on: "+ Electionday.getLongDate());        
                                 
                
                 // get data from user for excel method 
                 input = JOptionPane.showInputDialog("Enter the day to be "
                         + "calculated in the excel method");
                  d= Integer.parseInt(input);
                  input = JOptionPane.showInputDialog("Enter the month to be "
                         + "calculated in the excel method");
                  m = Integer.parseInt(input);
                   input = JOptionPane.showInputDialog("Enter the year to be "
                         + "calculated in the excel method");
                  y= Integer.parseInt(input);
                  

             //create a new object with data aquired from user for exel method
                 Date Excel = new Date(m,d,y);
                    
                 SpeedDating yo = new SpeedDating();
                 
                  //call the excel method and 
                  excelvalue = yo.iExcel(Excel);
                 
                  //print the excel value for the date inputted
                  System.out.println("\n\nThe excel value for the date you "
                          + "entered "
                          + "is : "+ excelvalue);  
                  
                  //exit from JOptionPane
                  System.exit(0);
             }
}
