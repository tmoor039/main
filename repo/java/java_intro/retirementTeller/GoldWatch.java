/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Oct 10, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
//  Class:  GoldWatch.java

//  Purpose:  Indicates whether an employee is eligible for retirement

import javax.swing.JOptionPane ;

public class GoldWatch
{
	private static final int RETIREMENT_AGE = 65 ;
	
	public static void main(String [] args)
	{
		int age ;			// Employee's age

		int years ;			// Employee's years of service

		boolean eligible ;	// Is employee eligible for pension?

		String input = JOptionPane.showInputDialog("Employee's age?") ;

		age = Integer.parseInt(input) ;

		input = JOptionPane.showInputDialog("Number of years with the company?") ;
		
		years = Integer.parseInt(input) ;
		
		eligible = age >= RETIREMENT_AGE || (age > 50 && years > 25);

		if  (eligible)
		{
			System.out.println("\nELIGIBLE") ;
		}
		else
		{
			System.out.println("\nNOT ELIGIBLE") ;
		}
	}
}
