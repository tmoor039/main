/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Nov 21, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
/*
File: AirDataListTester.java

This file contains 3 classes:

  1. The AirData class.  Stores data for an airline - the name and 
     the number of revenue miles and pasenger miles flown.
     (You will make no changes to this class)

  2. The AirDataList class. Maintains a list of AirData objects and has methods
     to add an object to the list and to return the list as a multi-line string
     (You will add a new method to this class but not modify the existing ones)

  3. The AirDataList class. Reads and echo prints lines from a data file 
     until eof.  You will add statements in the indicated places to
     a. Create a Scanner object associated with the current line of input
     b. Call Scanner methods to extract the tokens from the line 
     c. Create an AirData object using the tokens
     d. Add the object to the list
*/

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/*
 * A class to store data for an airline
 */
class AirData
{
    // instance vars

    private String name;		// airline name
    private int revenueMiles;	// annual revenue miles (in 1000's)
    private int passengerMiles;	// annual passenger miles (in 1000's)

    /**
     * Creates an AirData object.
     *
     * @param name the airline name
     * @param revenueMiles the number of revenue miles flown
     * @param passengerMiles the number of passenger miles flown
     */
    public AirData(String name, int revenueMiles, int passengerMiles)
    {
        this.name = name;
        this.revenueMiles = revenueMiles;
        this.passengerMiles = passengerMiles;
    }

    /**
     * Returns the airline name.
     *
     * @return the airline name
     */
    public String getName()
    {
        return name;
    }

    /**
     * Returns the airline's revenue miles flown.
     *
     * @return the revenue miles
     */
    public int getRevMiles()
    {
        return revenueMiles;
    }

    /**
     * Returns the airline's passenger miles flown.
     *
     * @return the passenger miles
     */
    public int getPassMiles()
    {
        return passengerMiles;
    }
} // end of AirData class definition ========================================

/**
 * A class to implement a list of AirData objects
 */
class AirDataList
{
    // instance var
    private ArrayList<AirData> list;	// list of AirData objects

    /**
     * Creates an empty list
     */
    public AirDataList()
    {
        list = new ArrayList<AirData>();
    }

    /**
     * Appends an AirData object to the list.
     *
     * @param current the object to be appended to the list
     */
    public void addToList(AirData current)
    {
        list.add(current);  // calls add method of ArrayList class
    }

    /**
     * Converts the list to a multi-line string, with each line containing the
     * data for one airline.
     *
     * @return the String containing all the data on the list
     */
    public String toString()
    {
        // headings
        String out = 
              String.format("%28s%18s%n", "Revenue Miles", "Passenger Miles") +
              String.format("%12s%16s%18s%n", "Airline", "(in 1000's) ", 
                            "(in 1000's)  ") +
              String.format("%12s%16s%18s%n","=======","=============", 
                            "===============");

        // for each AirData object on the list...
        for (int i = 0; i < list.size(); i++)
        {
            AirData air = list.get(i);             // get next AirData obj
            String name = air.getName();           // get airline name
            int revMiles = air.getRevMiles();      // get revenue miles
            int passMiles = air.getPassMiles();    // get passenger miles
            // concatenate data to output string
            out = out + String.format("%12s", name)
                    + String.format("%16s", revMiles)
                    + String.format("%18s", passMiles) + "\n";
        }
        return out + "\n";
    }
    
    
    public void printData()
    {
                 double revtotal = 0,passtotal = 0;
        
        for ( int i = 0; i < list.size(); i++)
        {
          
                 AirData Data = list.get(i);
           
            passtotal += Data.getPassMiles();
            revtotal = Data.getRevMiles();
        
        }
        double x = 0, y = 0;
        for ( int i = 0 ; i < list.size() ; i++)
        {
            AirData Data = list.get(i);
            
         x =    (Data.getRevMiles()/revtotal)*100;
         y =    (Data.getPassMiles()/passtotal)*100;
             
      System.out.printf("%20.2f%19.2f%n",x,y);
               
     
    }
    
    }
    
    
    
    
} // end of AirDataList class definition =====================================

public class AirDataListTester
{

    public static void main(String[] args) throws IOException
    {
        AirDataList list = new AirDataList();

       
        // create Scanner object to read each line of file until eof
        Scanner infile = new Scanner(new File("AirData.txt"));

        System.out.println("Data entered:\n");

        while (infile.hasNext()) // while not eof...
        {
            // read next line
            String line = infile.nextLine();

            // "echo print" data entered
            System.out.println(line);

            // a. create a Scanner object associated with String "line"
            Scanner fileScanner = new Scanner(line);

            // b. extract the 3 tokens from the current line
              String name =   fileScanner.next();
              int revmil = fileScanner.nextInt();
              int passmil = fileScanner.nextInt();

            // c. create an AirData object passing the tokens to the constructor
              AirData Mydata = new AirData(name,revmil,passmil);

            // d. add the object to the list
              list.addToList(Mydata);

        }
        System.out.println();

        System.out.println(list.toString());  // print the list
        
        list.printData();
        
        PrintWriter out = new PrintWriter("Lab.out");
        out.print(list.toString());
        out.close();
        
    
        
     
        
    }
} // end of AirDataListTester class definition
