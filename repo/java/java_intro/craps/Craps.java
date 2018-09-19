import java.util.Random;

/**
 * Simulate a game of Craps played with 2 6-sided dice
 */
public class Craps
{
	// instance variables
	private boolean traceOn ;				// print all rolls of dice or not?
	private Die dieOne ; 					// a 6-sided die object
	private Die dieTwo ; 					// another  6-sided die object
	private boolean winner ; 				// result of the game (won/lost)
	
	/**
	 * Create dice and initialize the game
	 * @param trace true if user wants all rolls of the dice to be printed, 
	 * false to just see end result (won or lost)
	 */
	public Craps(boolean trace)
	{
		traceOn = trace;
		dieOne = new Die(6);
		dieTwo = new Die(6);
		winner = false;
	}
	
	/**
	 * Play a game of craps. Continue throwing until a result is decided
	 */
	public void play()
	{
		if (traceOn)
		  System.out.println("\nThe dice are coming out...") ;
		
		// make initial roll of the dice
		int initialRoll = dieOne.roll() + dieTwo.roll() ;
		
		if (traceOn)
		  System.out.println("Initial Roll:  " + initialRoll) ;
		
		// when dice are coming out, 7 or 11 wins, and 2,3, or 12 loses.  Any
		// other number becomes player's "point" to be matched...
		
		if ( initialRoll == 7 || initialRoll == 11 )
		{
			winner = true ;
		} 
		else if ( initialRoll == 2 || initialRoll == 3 || initialRoll == 12 )
		{
			winner = false ;
		} 
		else	// player's "point" is established
		{
			int point = initialRoll ;
			if (traceOn)
		      System.out.print(point + " is your point.\nRolling...  ") ;

            boolean gameOver = false ;
            
			// repeat until the game is over...
			do
			{
				// roll again
				int newRoll = dieOne.roll() + dieTwo.roll() ;
			         	
			    if (traceOn)
		    	   System.out.print(newRoll + "  ");

				// evaluate the new roll
			    if (newRoll == 7)				// player loses!  :-(
			    {
			       winner = false ;
			       gameOver = true ;
			    }
			    else if (newRoll == point)		// player wins!  :-)
			    {
			       winner = true ;
			       gameOver = true ;
			    }
			} 
			while( !gameOver ) ;
			
			if (traceOn)
		      System.out.println() ;
		}
	}
	
   /**
	* Report outcome of the game.
	* @return true if player won, false if player lost
	*/
	public boolean isWinner()
	{
		return winner ;
	}
}