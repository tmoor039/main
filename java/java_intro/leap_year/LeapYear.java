/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Oct 8, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
/*
 File:  LeapYearTester.java

 Purpose:  Indicates whether or not a year - entered by the user - is a
 leap year.  A year is a leap year if either one of the following is true:
 1.  the year is divisible by 4 and not by 100
 2.  the year is divisible by 400

 Demonstrates boolean type - variables, assignments, operators, and methods
 */

import javax.swing.JOptionPane;

/**
 * A class thats tests whether a given year is a leap year
 */
public class LeapYear
{
    // instance var

    private int year;	// 4-digit year being tested

    /**
     * Create a LeapYearTester object.
     *
     * @param inputYear the year being tested Precondition: inputYear >= 1583
     */
    public LeapYear(int inputYear)
    {
        year = inputYear;
    }

    /**
     * Is a year a leap year?
     *
     * @return true if year is a leap year, false if not
     */
    public boolean isLeapYear()
    {
        boolean regularLeap;   // true if "regular" leap year (every 4 years
                               // except for years ending in 00)
        boolean leap400;       // true if "century" leap year (every 400 years)

        regularLeap = (year % 4 == 0) && !(year % 100 == 0);
        leap400 = (year % 400 == 0);

        return regularLeap || leap400;   // true if either is true
    }

    public static void main(String[] args)
    {
        String input = JOptionPane.showInputDialog("Enter a 4-digit year");

        int inputYear = Integer.parseInt(input);

        LeapYear testYear = new LeapYear(inputYear);

        // Is it a leap year?

        if (testYear.isLeapYear()) // calls boolean method
        {
           System.out.println(inputYear + " IS a leap year.");
        } 
        else
        {
            System.out.println(inputYear + " is NOT a leap year.");
        }
        System.exit(0) ;
    }
}

/* sample output from 4 runs:

 2013 is NOT a leap year.

 2016 IS a leap year.

 2100 is NOT a leap year.

 2400 IS a leap year.

 */