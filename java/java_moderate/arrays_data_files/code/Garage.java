
/**
 * Created by Tiago Moore on Feb 2, 2014. Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *
 */
package Garage;
import java.util.*;

/**
 *Creates a garage to manipulate a Car object
 * 
 * @author tmoore
 */
public class Garage
{
  private Car myGarage[];
  private Car parkingLot[];
  private  final int sizeOfGarage = 10;
  private int numberOfCostumers;
 /**
  * Constructor initializes variables
  */
  public Garage()
  {
    myGarage = new Car[sizeOfGarage];
    parkingLot = new Car[sizeOfGarage];
    numberOfCostumers = 0;
  }

  /**
   * Searches the garage for the first available spot to put a car in
   * @return the position in the garage of the first empty spot
   */
  private int firstAvailableSpot()
  {
    // set the first spot to a dummy value
    int firstSpot = -1;

    for (int i = 0; i < sizeOfGarage; i++)
    {
      if (myGarage[i] == null)
      {
        // when a spot is avaible, record that position
        firstSpot = i;
        //exit loop
        break;
      }
    }

    return firstSpot;
  }

  /**
   * places a Car with a given license plate in the garage
   * @param newPlate the license plate of the Car
   * @return a message stating whether or not the car was parked
   */
  public String arrive(String newPlate)
  {
    // set a value that makes the garage full 
    int parkingSpot = -1;
    String message = "";// initialize a variable 

    // find the first spot to park in 
    parkingSpot = firstAvailableSpot();
    // if a spot is the dummy value; the garage is full
    if (parkingSpot == -1)
    {
      message = "The garage is full! the car with the license plate: "
              + newPlate + " has turned away. \n";
    }
    else if (parkingSpot != -1)
    {
      numberOfCostumers++;
      // park the car in the spot
      myGarage[parkingSpot] = new Car(newPlate);
      message = "A vehicle with a license plate of : "
              + newPlate + " has been added to "
              + "spot #" + (parkingSpot + 1) + "\n";
    }

    return message;
  }

  /**
   * searches the garage for the car that will be departing
   * @param carLeaving the Car that is departing
   * @return carLocation the location in the Garage where the Car is
   */
  private int findCar(Car carLeaving)
  {
    int carLocation = -1;

    for (int i = 0; i < numberOfCostumers; i++)
    {
      // if its the last run of the loop 
      //and the car is not in the garage, return -1
      if (i == numberOfCostumers - 1 && myGarage[i] == null)
      {
        return carLocation;
      }
      // look for the car in the array 
      else if (carLeaving.getPlate().equals(myGarage[i].getPlate()))
      {
        // if car is found, record and exit loop
        carLocation = i;
        break;
      }
    }
    return carLocation;
  }

  /**
   * After a car Departs, this method moves all cars up one location in the garage and makes sure
   * all the other spaces are empty
   * @param fromThisPosition the position from where the cars will behin moving up
   */
  private void moveCarsUp(int fromThisPosition)
  {
    // everyone behind the car thats leaving 
    int x = fromThisPosition + 1;

    for (int i = x; i < sizeOfGarage; i++)
    {
      // move the car up one positon  
      myGarage[i - 1] = myGarage[i];
    }

  }

  /**
   * When a car departs and there are cars in the way, this method 
   * removes all cars and stores them
   * in a parking lot temporarilt until the car departs
   * @param fromThisPosition the position to start clearing the way
   */
  private void clearTheWay(int fromThisPosition)
  {
    // move all the cars out of the garage
    for (int i = 0; i < fromThisPosition; i++)
    {
      // put all the cars in the way in the parking lot 
      parkingLot[i] = myGarage[i]; 
      // increment the moves of the specific vehicle being put 
      //into the parking lot 
      parkingLot[i].incrementMoves();
      myGarage[i] = null;// make sure the car is not in the garage 
    }
  }

  /**
   * removes a car from the garage and make sure 
   * that there is an empty space behind
   * @param PlateLeaving the license plate of the Car leaving
   * @return a message stating what car was removed and how many times it was
   */
  public String depart(String PlateLeaving)
  {
    // create a car with given plate
    Car departingCostumer = new Car(PlateLeaving);
    int carLocation = findCar(departingCostumer);
    String message = "";

    if (carLocation == -1)
    {
      message = "The car with the license plate: "
      + "" + departingCostumer.getPlate() + " is not in the garage!\n";
    }
    else if (carLocation == 0)
    {
      numberOfCostumers--;// update numberof cars in garage
      message = "The car with license plate : "
      + departingCostumer.getPlate() + " has been removed from "
      + "the garage location #" + (carLocation + 1) + " with a total of "
      + myGarage[carLocation].getNumMoves() + " moves. \n";
      myGarage[0] = null; // remove the car from the garage
      moveCarsUp(carLocation);// move the cars up 
    }
    else if (carLocation != 0)
    {
      numberOfCostumers--;// update number of cars in garage
      clearTheWay(carLocation);
      message = "The car with license plate : "
      + departingCostumer.getPlate() + " has been removed from "
      + "the garage location #" + (carLocation + 1) + " with a total of "
      + myGarage[carLocation].getNumMoves() + " moves. \n";
      myGarage[carLocation] = null;// remove the car
      moveCarsUp(carLocation);

      // for the amount of cars in the parking lot
      for (int i = 0; i < parkingLot.length; i++)
      {
        // if there are no cars to be moved in
        if (parkingLot[i] == null)
        {
          parkingLot = null;// clear the parking lot
          // allocate more memory for the lot
          parkingLot = new Car[sizeOfGarage];
          break;// exit loop
        }
        else
        {
          // put the cars in the parking lot back in the garage
          myGarage[i] = parkingLot[i];
        }
      }
    }

    // make sure that the cars are out of the garage!
    for (int i = sizeOfGarage - 1; i >= numberOfCostumers; i--)
    {
      //asserts that the carage has empty spaces 
      //exept for the first n spaces with cars
      myGarage[i] = null;
    }

    return message;
  }
}
