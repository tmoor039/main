
/**
 * Created by Tiago Moore on Feb 2, 2014. 
 *  Copyright (c) 2013 __TiagoMoore__. All rights reserved. 
 * Assignment#2 Unit #4
 *I affirm that this program is entirely my own work and none of it is the work of any other person.
 *
 *
 *
 * _______________________________________________________
 *
 *
 */
package Garage;
import java.io.*;
import java.util.*;

public class GarageTester
{

  public static void main(String args[]) throws IOException
  {
    //declare and initialize variables
    String output = "";
    int numOfOps = 0;

    // create a textfile object asscociated with garage.txt
    File textFile = new File("garage.txt");
    //create a scanner object associated with the textfile
    Scanner inFile = new Scanner(textFile);
    
    // create a file for output
    File echoedOutput = new File("echoedOutput.txt");
    echoedOutput.createNewFile();
    //create a FileWriterObject associated with the outputFile
    FileWriter writer = new FileWriter(echoedOutput);
    
    
    
    // get the total number of operations that w
    //will be done in the garage
    while (inFile.hasNextLine())
    {
      inFile.nextLine();
      numOfOps++;
    }
    inFile.close();
    inFile = null;// reset the scanner 
    inFile = new Scanner(textFile);
    // create an array the size of the total number of 
    //operations to hold all the license plates 
    String licencePlates[] = new String[numOfOps];
    //create an array to hold all of the operations 
    String Operations[] = new String[numOfOps];

    // for the size of the file 
    for (int i = 0; i < numOfOps; i++)
    {
      // read in all the license plates into an array 
      licencePlates[i] = inFile.next(); 
      // read all the operations into an array 
      Operations[i] = inFile.next();  
    }
    
    // make a new Garage Object to put all the cars in
    Garage pantherGarage = new Garage();
    
    for (int i = 0; i < Operations.length; i++)
    {

      // do the particular operation to that car
      if (Operations[i].equals("ARRIVE"))
      {
        output = pantherGarage.arrive(licencePlates[i]);
        System.out.print(output);
        writer.write(output);
        writer.flush();
      }
      else if (Operations[i].equals("DEPART"))
      {
        output = pantherGarage.depart(licencePlates[i]);
        writer.write(output);
        writer.flush();
        System.out.print(output);
      }
    }
  }
}

/*
 OUTPUT:
 A vehicle with a license plate of : JAV001 has been added to spot #1
 A vehicle with a license plate of : JAV002 has been added to spot #2
 A vehicle with a license plate of : JAV003 has been added to spot #3
 A vehicle with a license plate of : JAV004 has been added to spot #4
 A vehicle with a license plate of : JAV005 has been added to spot #5
 The car with license plate : JAV001 has been removed from the garage location #1 with a total of 0 moves.
 The car with license plate : JAV004 has been removed from the garage location #3 with a total of 0 moves.
 A vehicle with a license plate of : JAV006 has been added to spot #4
 A vehicle with a license plate of : JAV007 has been added to spot #5
 A vehicle with a license plate of : JAV008 has been added to spot #6
 A vehicle with a license plate of : JAV009 has been added to spot #7
 A vehicle with a license plate of : JAV010 has been added to spot #8
 A vehicle with a license plate of : JAV011 has been added to spot #9
 A vehicle with a license plate of : JAV012 has been added to spot #10
 The garage is full! the car with the license plate: JAV013 has turned away.
 The garage is full! the car with the license plate: JAV014 has turned away.
 The car with license plate : JAV006 has been removed from the garage location #4 with a total of 0 moves.
 The car with the license plate: JAV014 is not in the garage!
 The car with the license plate: JAV013 is not in the garage!
 The car with license plate : JAV005 has been removed from the garage location #3 with a total of 1 moves.
 A vehicle with a license plate of : JAV015 has been added to spot #9
 The car with license plate : JAV010 has been removed from the garage location #6 with a total of 0 moves.
 The car with license plate : JAV002 has been removed from the garage location #1 with a total of 4 moves.
 The car with license plate : JAV015 has been removed from the garage location #7 with a total of 0 moves.
 The car with the license plate: JAV013 is not in the garage!
 The car with license plate : JAV009 has been removed from the garage location #4 with a total of 2 moves.
 The car with license plate : JAV003 has been removed from the garage location #1 with a total of 6 moves.
 The car with license plate : JAV008 has been removed from the garage location #2 with a total of 3 moves.
 The car with license plate : JAV007 has been removed from the garage location #1 with a total of 4 moves.
 The car with license plate : JAV012 has been removed from the garage location #2 with a total of 1 moves.
 The car with license plate : JAV011 has been removed from the garage location #1 with a total of 2 moves.
*/