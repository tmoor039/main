import java.util.Random ;

/**
 * A class that simulates an n-sided die.
 */
public class Die
{	
	// instance variables
	private int numberOfSides ;				// Number of sides of the die
	
	// create only 1 Random Number Generator object, no matter how many dice
	private static Random generator = new Random();

   /**
	* Construct a die with any number of sides.
	* @param n the number of sides (usually 6)
    */
	public Die(int n)
	{
		numberOfSides = n;
	}
	
   /*
	* Roll the die. 
	* @return an int between 1 and the number of sides, inclusive
	*/
	public int roll()
	{
		return generator.nextInt(numberOfSides) + 1 ;
	}
}