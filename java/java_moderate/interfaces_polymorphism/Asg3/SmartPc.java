/**
 * Created by Tiago Moore on Feb 23, 2014. 
 * Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *
 */
import java.util.Random;

/**
 * A Smart Computer to be used with the Play interface
 * @author Tiago Moore
 */
public class SmartPc implements Player
{
  //declare a variable for the number of marbles to remove
  private int marblesToRemove;

  /**
   * Constructor makes a Dumb PC object
   * @param x the number of marbles in the Pile
   */
  public SmartPc()
  {
    marblesToRemove = 0;
  }

  /**
   * This method finds out exactly how many to 
   * remove to make the remaining pile a power of two
   * mines one
   * @param num the total number of marbles in the pile
   */
  private void smartFunction(int num)
  {

    // reset the number of marlbes to remove
    marblesToRemove = 0;
   int totalMarbleNum = num; // total number of marbles in pile 
   
   // while its not a power of 2 minus one 
    if (num > 63 && marblesToRemove < totalMarbleNum / 2)
    {
      while (num > 63 && marblesToRemove < totalMarbleNum / 2)
      {
        num--;// decrease total number of marbles
        marblesToRemove++;// increment the amount to remove
      }
    }
    else if (num > 31 && marblesToRemove < totalMarbleNum / 2)
    {
      while (num > 31 && marblesToRemove < totalMarbleNum/2)
      {
        num--;
        marblesToRemove++;
      }
    }
    else if (num > 15 && marblesToRemove < totalMarbleNum / 2)
    {
      while (num > 15 && marblesToRemove < totalMarbleNum / 2)
      {
        num--;
        marblesToRemove++;
      }
    }
    else if (num > 7 && marblesToRemove < totalMarbleNum / 2)
    {
      while (num > 7 && marblesToRemove < totalMarbleNum / 2)
      {
        num--;
        marblesToRemove++;
      }
    }
    else if (num > 3 && marblesToRemove < totalMarbleNum / 2)
    {
      while (num > 3 && marblesToRemove < totalMarbleNum / 2)
      {
        num--;
        marblesToRemove++;
      }
    }
    else if (num > 1 && marblesToRemove < totalMarbleNum / 2)
    {
      while (num > 1 && marblesToRemove < totalMarbleNum / 2)
      {
        num--;
        marblesToRemove++;
      }
    }
  }

  /**
   * method gives the SmartComputer a move remove
   * @param numOfMarbles the total number of marbles in the pile
   * @param Pile the pile of the pile of marbles we're playing with
   */
  public int move(int numOfMarbles)
  {
    
    System.out.println("\nThere are "+numOfMarbles+" marble(s) left in the pile.\n");
    // call smart function method
    smartFunction(numOfMarbles);
    //change the pile of marbles 
    System.out.println("Smart computer has removed " + marblesToRemove + " marbles.");
    return marblesToRemove;

  }

/**
 * Prints a message saying the Smart computer is the winner 
 */
  public void printWinner()
  {
    System.out.println("Smart Computer wins!");
  }


}
