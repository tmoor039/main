
/**
 *Created by Tiago Moore on Mar 4, 2014.
 *This file contains a human player obeject that implements the Player interface 
 * Reviewed 5 June 2018
 */
import java.util.Scanner;
/**
 * Class to be used with the Player interface
 * @author tmoore
 */
public class Human implements Player
{
  private int marblesToRemove; // number of marbles to take out 
/**
 * Constructor creates a human object
 */
  public Human()
  {
    this.marblesToRemove = 0;
  }
/**
 * Prompts the user for its move
 * @param numOfMarbles the number of marbles left in the pile 
 * @return the number of marbles to remove from the pile 
 */
  public int move(int numOfMarbles)
  {
    Scanner input = new Scanner(System.in); // scanner for input 
    do
    {
      //Display remaining marbles
      System.out.print("\nThere are " + numOfMarbles + " marbles left in the pile.\n\n");
      
      //promt the user 
      System.out.print("Enter the number of marbles  you would like to to remove:");
      marblesToRemove = input.nextInt();
      // if invalid input, display error
      if ((marblesToRemove > numOfMarbles) || (marblesToRemove <= 0) 
              ||(marblesToRemove > numOfMarbles / 2))
      {
        System.out.println("\nInvalid! The number you take out must be between 1 and " 
        + numOfMarbles / 2 + " inclusive.");
      }
   
      // while there is invalid input, repeat 
    } while ((marblesToRemove > numOfMarbles) || (marblesToRemove <= 0)
            || (marblesToRemove > numOfMarbles / 2));
    //Display marbles removed
    System.out.println("\nYou have removed " + marblesToRemove + " marble(s).\n");
    return marblesToRemove;
  }
/**
 * Prints a message saying human is the winner 
 */
  public void printWinner()
  {
    System.out.println("You win!");
  }
}
