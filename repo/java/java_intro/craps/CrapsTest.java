/**
 * A test class for the Craps class.  Plays a game and prints results.
 */
public class CrapsTest
{
	public static void main(String[] args)
	{
            int count1 = 0;
            int count2 = 0;
       
            for (int i = 0; i < 1000; i ++)
            {
		// create a Craps game object, with trace on
		Craps shooter = new Craps(false) ;
		
		// play a game
		shooter.play() ;
		
		if ( shooter.isWinner() )
                {
		  System.out.println("Player wins!\n") ;
                  
                 count1++;
                }
		else
                {
		  System.out.println("Sorry, player loses.\n") ;
                count2++;
                 }
            }
            
             System.out.println("%wins = "+(count1/1000.0)*100) ;
             
               System.out.println("%lose = "+(count2/1000.0)*100) ;
	}
}