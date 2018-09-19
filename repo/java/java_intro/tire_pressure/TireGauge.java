/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Oct 10, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */
//  Class:  TireGauge.java

//  Purpose:  Evaluates the air pressure in a tire and prints an appropriate
//            message

import javax.swing.JOptionPane ;

class TireGauge
{
	public static void main(String [] args)
	{
		double pressure ;					// tire pressure, in psi
		
		String input = JOptionPane.showInputDialog("Enter tire pressure: ") ;

		pressure = Double.parseDouble(input) ;

		// Pressure in the range 30 - 35 psi (inclusive) is OK
                    
                if (pressure >= 30 && pressure <= 25)
            {
                    System.out.print("OK");
            }
                
                else if (pressure > 35)
                {
                    System.out.print("Overinflated");
                    
                }
                
                else
                {
                   System.out.print("UNDERinflated");
                }
          

		// Write code below to display the appropriate message chosen from

		// "OVERinflated"    "UNDERinflated"    "Pressure OK"




	}
}
