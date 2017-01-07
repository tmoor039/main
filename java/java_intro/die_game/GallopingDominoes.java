import java.util.Random ;

/**
 * A class to represent a standard 6-sided die
 */
class Die	// die is the singular of "dice"
{
	// random number generator object
	private static Random r = new Random() ;
        
     
	/**
	 * Roll one die.
	 * @return a random integer from 1 to 6
	 */
	public int roll()		
	{
		return r.nextInt(6) + 1 ;
	}
}

/**
 * Plays the game.  I.e., rolls the dice to get the initial roll and counts
 * number of additional rolls required to match it.  Repeats as long as the
 * user wants to play another game
 */
class MatchGame2
{
	// instance var's are Die objects 
	Die d1 = new Die() ;				// create pair of dice
	Die d2 = new Die() ;
        
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
         int imax = Integer.MIN_VALUE;
        int imin = Integer.MAX_VALUE;
        
        
        

	// This method just aligns the output...
	private static String format (int number)
	{
		if (number <= 9)				// if single-digit number...
		  return " " + number ;			// ...pad with one leading space
		else							// 2-digit number...
		  return "" + number ;			// ...no padding
	}

	/**
     * Plays the game.  I.e., rolls the dice to get the initial roll and counts
     * number of additional rolls required to match it.  Repeats as long as the
     * user wants to play another game
     */
	public void play()
	{
		int initialRoll=0 ;		// total of first roll of two dice

		int rollCount=0;         // counts number of rolls it takes to
		                      // match the initial roll

        int gameNumber = 0 ;	// counts number of games played

		System.out.println() ;
		

		while (rollCount != 100 )					// loop forever!
		{
			gameNumber++ ;				// increment # of games played

			// get the initial roll
			initialRoll = d1.roll() + d2.roll() ;

			// roll dice again to try to match initial roll
			int currentRoll = d1.roll() + d2.roll() ;
						
		    // initialize count of number of rolls needed to match
			rollCount = 1 ;	
                        
                        
                        
                        
                        
                        
                        
			
			// repeat as long as the initial roll is not matched
			// DO NOT MODIFY THIS LOOP!  ONLY THE OUTER ONE!
			while ( currentRoll != initialRoll )	// while NOT matched...
			{
				// ...roll 'em again!
				currentRoll = d1.roll() + d2.roll() ;
				
				// ...increment number of rolls made
				rollCount++ ;			
			}
			// Loop postcondition:  initialRoll has been matched
		
			// print stats
			System.out.println("Trial #" + format(gameNumber) + 
			                 "   Initial roll = " + format(initialRoll) + 
			                 "   Matched in " + format(rollCount) +
                             " rolls.") ;
                        
                        	
                        if ( initialRoll == 0 )
                        {
                            max = rollCount;
                        }
                        
                        if ( min > rollCount)
                        {
                            min = rollCount;
                        }
                        
                        System.out.println("Minimum rolls : "+ min+"\n"
                                + "Maximum rolls: "+ max+ "\n") ;
               
        
                        
                        if ( rollCount > imax)
                        {
                            initialRoll = imax;
                        }
                        
                        if (rollCount < imin)
                        {
                            initialRoll = imin;
                        }
                        
                        
                 System.out.print("most attempts : "+ imax+" to match a"+
                initialRoll+"\nLeast attempts : "+ imin + " to match a "+
                        initialRoll);
                        
                        
                   
	    }
                
	
                 
       
}
}
public class GallopingDominoes
{
	public static void main(String[] args)
	{
		MatchGame2 fun = new MatchGame2() ;
		fun.play() ;
	}
}