/**
Created 23 Feb 2014
Pending Review 4 June 2018
 *
 */


import java.util.Random;
/**
 * Dumb computer player to be used with Player
 */
public class DumbPc implements Player
{
  //number of marbles to remove form the pile 
  private int marblesToRemove;

  /**
   * Constructor creates a DumbPc object
   */
  public DumbPc()
  {
    marblesToRemove = 0;
  }

  /**
   * A move method for the DumbPc, selects a random number
   * to remove from the pile 
   * @param DumbPc the number of marbles in the pile 
   * @return  the number of marbles to remove from the pile 
   */
  public int move(int numOfMarbles)
  {
    Random RandomGen = new Random();

    System.out.println("\nThere are " + numOfMarbles + " marble(s) left in the pile.\n");
    
    // make a random number between 1 and half of total marbles 
    marblesToRemove = (RandomGen.nextInt((numOfMarbles/2)+1)+1);
    
    System.out.println("Dumb computer has removed " + marblesToRemove + " marble(s).");
    return marblesToRemove;
  }

  /**
   * Prints a message saying the dumbPC wins
   */
  public void printWinner()
  {
    System.out.println("Dumb Computer wins!");
  }
}
