/**
 * Created by Tiago Moore on Feb 2, 2014. Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *
 */
package Garage;


/**
 * Class that creates a Car to be used in coherence with the garage
 * @author tmoore
 */
public class Car
{

  private String licensePlate;
  private int numberOfMoves;


  /**
   * Creates a car object with a specified license plate and number of moves is set to zero
   * @param plate the license plate of the car
   */
  public Car(String plate)
  {
    licensePlate = plate;
    numberOfMoves = 0;

  }

  /**
   * Mutator method that increments the number of moves a car made
   */
  public void incrementMoves()
  {
    numberOfMoves++;
  }

  /**
   * Accessor method gets the place number
   * @return the license plate number
   */
  public String getPlate()
  {
    return licensePlate;
  }

  /**
   * Accessor method gets the number of moves
   * @return the number of moves a car had
   */
  public int getNumMoves()
  {
    return numberOfMoves;
  }

}
