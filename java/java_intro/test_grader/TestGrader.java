/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Oct 10, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
//  Class:  TestGrader.java

//  Purpose:  Evaluates a test score and prints an appropriate message

import javax.swing.JOptionPane ;

class TestGrader
{
	private static final int MIN_GOOD = 80 ;
	private static final int MIN_PASS = 65 ;
	
	public static void main(String [] args)
	{
		int score ;		// Test score in the range 0 .. 100

		String grade ;	// "GOOD"(80..100)  "PASS"(65..79)  or  "FAIL"(0..64)

		String input = JOptionPane.showInputDialog("Enter test score") ;
		
		score = Integer.parseInt(input) ;

		if (score >= MIN_PASS)
		{
			grade = "PASS" ;
		}

                else if (score >= MIN_GOOD)
		{
			grade = "GOOD" ;
		}
               
                
                else 
                {
                    grade = "FAIL" ;
                }
                

		System.out.println("\n" + score + ": " + grade) ;
	}
}