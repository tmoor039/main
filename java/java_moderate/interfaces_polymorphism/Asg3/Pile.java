import java.util.Random;
/**
 * Created by Tiago Moore on Feb 23, 2014.
 * Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *
 */

/**
 * This class creates a pile of marbles to be used by Nim
 * @author Tiago Moore
 */
public class Pile
{
  private int marbles; // number of marbles in pile
  /**
   * Constructor create a pile of marbles
   */
  public Pile()
  {
    Random setter = new Random();
    // need to set the amount to a random size from 10 to 100
    marbles = setter.nextInt(91) + 10;
  }
  
  /**
   * Gets the total number of marbles in the pile
   * @return the number of marbles remaining in the pile
   */
  public int getmarbles()
  {
    return marbles;
  }

  /**
   * Subtracts a given amount of marbles from the total amount
   * @param x the amount of marbles to change to
   */
  public void setmarbles(int x)
  {
    marbles -= x;
  }
}
