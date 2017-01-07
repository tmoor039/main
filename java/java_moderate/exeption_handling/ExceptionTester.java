import javax.swing.JOptionPane;
import java.io.*;
import java.util.*;
/**
 *
 * Created by Tiago Moore on Apr 17, 2014. 
 * Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * Instructor: Greg Shaw Section 4 I affirm that this program is entirely my own work and none of it
 * is the work of any other person.
 *
 *
 *
 * _________________________________________________
 */
public class ExceptionTester
{

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args)
  {
    Time time = null; // a Time object
    Scanner inFile = null;//  a scanner object which will read file
    String fileName, next; //  Strings for getting next token and the file name 
    int hour = 0, minutes = 0, seconds = 0;//  local variables to be used with Time
    // prompt for a file name 


    while (inFile == null) // while the file is not found
    {
      // promt the  user for a file name 
      fileName = JOptionPane.showInputDialog("Enter the name of the text file:(Case sensitive) ");
      try// check to see if it is found 
      {
        //create a file object associated with the file name 
        File textFile = new File(fileName);
        // create a scanner object to read file
        // if not found will throw exception
        inFile = new Scanner(textFile);
      }
      catch (FileNotFoundException e)
      {
        System.out.println("\nFile:'" + fileName + "' does not exist.FileNotFound Exception"
                + " has been thrown.");
      }
    }// done testing for file

    while (inFile.hasNextLine())// while there are still lines in the file 
    {
      //extract the next trhee tokens from the file 
      next = inFile.next();
      //try to convert it to an integer
      try
      {
        // if its not an integer, exception will be thrown
        hour = Integer.parseInt(next);
      }
      catch (NumberFormatException e)
      {
        System.out.println("Number format has been thrown"
                + " Exception.The value " + hour + " is not an integer value.");
      }
      // repeat for next two tokens in the line
      next = inFile.next();
      try
      {
        minutes = Integer.parseInt(next);
      }
      catch (NumberFormatException e)
      {
        System.out.println("Number format has been thrown"
                + " Exception.The value " + minutes + " is not an integer value.");
      }
      next = inFile.next();
      try
      {
        seconds = Integer.parseInt(next);
      }
      catch (NumberFormatException e)
      {
        System.out.println("Number format has been thrown"
                + " Exception.The value " + seconds + " is not an integer value.");
      }// done checking for valid integer inputs

      try//create a time object for the line, 
      {
        time = new Time(hour, minutes, seconds);
        // if erroneous input, trhow exceptions
        if (hour < 0 || hour > 23)
        {
          throw new illegalHourValue();
        }
        if (minutes < 0 || minutes > 59)
        {
          throw new IllegalMinuteValue();
        }
        if (minutes < 0 || seconds > 59)
        {
          throw new IllegalSecondValue();
        }
        System.out.print(time.toString() + "\n");

      }
      catch (illegalHourValue e)
      {
        System.out.print(e + "\nThe illegal value is : " + hour + ".\n");
      }
      catch (IllegalMinuteValue e)
      {
        System.out.print(e + "\nThe illegal value is : " + minutes + ".\n");
      }
      catch (IllegalSecondValue e)
      {
        System.out.print(e + "\nThe Illegal value is : " + seconds + ".\n");
      }
    }
  }
}

/**
 * Class to throw an exception if hour value is incorrect
 * @author tmoore
 */
class illegalHourValue extends Exception
{
  public illegalHourValue()
  {
    super("(The house must be between 0 and 23 inclusive)");
  }
}

/**
 * Class to throw an exception if minute value is incorrect
 * @author tmoore
 */
class IllegalMinuteValue extends Exception
{
  public IllegalMinuteValue()
  {
    super("(The minute value is not between 0 and 59 inclusive)");
  }
}

/**
 * Class to throw an exception if second value is incorrect
 * @author tmoore
 */
class IllegalSecondValue extends Exception
{
  public IllegalSecondValue()
  {
    super("(The seconds is not between 0 and 59 inclusive)");
  }
}
/**********************************OUTPUT********************************
 * 
 * File:'FakeFile' does not exist.FileNotFound Exception has been thrown.
12:30:00 A.M.
5:00:00 P.M.
IllegalMinuteValue: (The minute value is not between 0 and 59 inclusive)
The illegal value is : -1.
Number format has been thrown Exception.The value 11 is not an integer value.
11:11:10 A.M.
6:25:00 P.M.
7:11:00 A.M.
 * 
 */