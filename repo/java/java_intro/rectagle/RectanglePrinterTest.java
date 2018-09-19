/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Nov 7, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
import javax.swing.JOptionPane ;

/**
 * A class to print block rectangles.
 */
class RectanglePrinter
{
	// instance var's
	int height ; 			// height of rectangle (i.e. number of segments)    
	int width ;				// width of each segment(i.e. number of "*"s printed) 
	                
	/**
	 * Create a RectanglePrinter object.
	 * @param height height of rectangle (i.e., number of lines to print)
	 * @param width width of rectangle (i.e., number of '*'s per line
	 */
	public RectanglePrinter(int height, int width)	// constructor
	{
		this.height = height ;
		this.width = width ;
	}

	/**
	 * Prints one line of a rectangle, by printing exactly "width" asterisks
	 */ 
	public void printSegment()
	{
		// write the body of this method here


	}

	/**
	 * Prints a rectangle exactly "height" lines in height.  Each line is 
	 * printed via a call to method printSegment
	 */ 
	public void printRectangle()
	{
		System.out.println("Printing a " + height + " x " + width + " rectangle:") ;
		// write the body of this method here
                
              for ( int i  = 0 ; i <=width; i++)
              {
                   System.out.print("*");
                  for ( int j = 0 ; j <= height; j++)
                  {
                      System.out.print("*");
                  }
     
                   System.out.print("\n");
              }

	}
	
}  // end of class rectanglePrinter definition

public class RectanglePrinterTest
{
	public static void main (String [] args)
	{
		String input = JOptionPane.showInputDialog
			                       ("What is the height of the rectangle?") ;
		int height = Integer.parseInt(input) ;
		
		input = JOptionPane.showInputDialog
			                ("What is the width of the rectangle?") ;
		
		int width = Integer.parseInt(input) ;

		RectanglePrinter r = new RectanglePrinter(height, width) ;

		System.out.println() ;
		r.printRectangle() ;
                
		System.out.println() ;
	}
}