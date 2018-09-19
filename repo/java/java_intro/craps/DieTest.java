/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Nov 7, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
/**
 * A class to test the "randomness" of a simulated die.
 */
public class DieTest
{
	public static void main(String[] args)
	{
		int count_1 = 0 ; 				// number of times a 1 is rolled
		int count_2 = 0 ; 				// number of times a 2 is rolled
		int count_3 = 0 ; 				// number of times a 3 is rolled
		int count_4 = 0 ; 				// number of times a 4 is rolled
		int count_5 = 0 ; 				// number of times a 5 is rolled
		int count_6 = 0 ; 				// number of times a 6 is rolled
		
		Die myDie = new Die(6); 		// creates a 6-sided die
		
		final int numberTrials = 100 ; 	// number of test throws to do

		int times = 1; 					// counts number of throws

		// perform the trials by rolling the die several times and counting 
		// the frequency of each outcome				
		
		while (times <= numberTrials)
		{
			int test = myDie.roll() ;
			
			if (test == 1)
			  count_1++ ;
			else if (test == 2)
			  count_2++ ;
			else if (test == 3)
			  count_3++ ;			
			else if (test == 4)
			  count_4++ ;			
			else if (test == 5)
			  count_5++ ;		
			else if (test == 6)
			  count_6++ ;		
			else					// an error has occurred
			{
				System.out.println("*** BAD DIE ***\nNUMBER ROLLED: " + test) ;
			    System.exit(1) ;
			}
		}
		
		// report the percentage of rolls for each outcome 1..6
		times = 1;
		while (times <= 6)
		{
			double percent = 0.0;
			if (times == 1)
			  percent = count_1 / (double)numberTrials * 100 ;
			else if (times == 2)
			  percent = count_2 / (double)numberTrials * 100 ;
			else if (times == 3)
			  percent = count_3 / (double)numberTrials * 100 ;			
			else if (times == 4)
			  percent = count_4 / (double)numberTrials * 100 ;			
			else if (times == 5)
			  percent = count_5 / (double)numberTrials * 100 ;		
			else // test was 6)
			  percent = count_6 / (double)numberTrials * 100 ;	
			  	
			System.out.println(times + " : " + percent + "%");
			times++ ;
		}
	}
}