import java.util.Scanner;

/**
 *
 * Created by Tiago Moore on Feb 23, 2014. 
 * Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * Instructor: Greg Shaw Section 4 
 * I affirm that this program is entirely my own work and none of it
 * is the work of any other person.
 *
 *
 * _______________________________________________________
 */
public class NimTester
{

  public static void main(String[] args)
  {

    int menuChoice = 0;//  the first menu option
    int opponentChoice = 0;// option for the oponent
    int orderChoice = 0;// option for first or second
    int playAgain = 0;// option for playing again

    //intro
    System.out.println("\n\nWELCOME TO MY NIM GAME!!!");
    System.out.println("--------------------------\n\n");
    do
    {
      // first menu
      System.out.println("\nChoose from the following menu:");
      System.out.println("1)Display Rules.");
      System.out.println("2)Play Game.");
      System.out.println("3)Quit.\n");

      System.out.print("Enter your choice here: ");
      Scanner choice = new Scanner(System.in);
      menuChoice = choice.nextInt();

      switch (menuChoice)
      {
        // Display rules
        case 1:
        {
          System.out.println("\nTwo players takes turns removing marbles from "
                  + "a pile. On each turn, the player must remove at least one "
                  + "but no more than half of the remaining marbles. The player"
                  + " who is forced to remove the last marble loses.\n\n");
          break;
        }

        //Play the game
        case 2:
        {
          playAgain = 1;
          do
          {
            System.out.println("\nYou have chosen to play the game!\n");

            System.out.println("Please choose your opponent:"
                    + " \n\n1)Smart Computer\n2)Dumb Computer\n");

            System.out.print("Enter your choice here: ");
            opponentChoice = choice.nextInt();
            // if structure for smart computer
            if (opponentChoice == 1)
            {
              System.out.println("\nYou have choosen to play the smart computer.\n");
              //Create a human player object
              Player You = new Human();
              // Create a Smart Computer player Object
              Player PC = new SmartPc();
              do
              {
                System.out.print("Would you like to play first or second?"
                        + "\n\nEnter 1 for first and 2 " + "for second: ");
                orderChoice = choice.nextInt();

                if (orderChoice == 1)
                {
                  Nim Game = new Nim(You, PC); // create a Nim game object
                  Game.play(); // play the game 
                  System.out.print("Play again?\nEnter 1 for yes and 0 for no: ");
                  playAgain = choice.nextInt();
                }
                else if (orderChoice == 2)
                {
                  Nim Game = new Nim(PC, You); //create Nim game object 
                  Game.play();
                  System.out.print("Play again?\nEnter 1 for yes and 0 for no: ");
                  playAgain = choice.nextInt(); // input
                }
              }
              // end of do while loop for first or second 
              while (orderChoice != 1 && orderChoice != 2);
            }
            // if structure for dumb computer
            else if (opponentChoice == 2)
            {
              System.out.println("\nYou have choosen to play the dumb computer.\n");
              Player You = new Human();
              Player PC = new DumbPc();
              do
              {
                System.out.print("Would you like to play first or second?\n"
                        + "\nEnter 1 for first and 2 " + "for second: ");
                orderChoice = choice.nextInt();

                if (orderChoice == 1)
                {
                  Nim Game = new Nim(You, PC);
                  Game.play();
                  System.out.print("Play again?\nEnter 1 for yes and 0 for no: ");
                  playAgain = choice.nextInt();
                }
                else if (orderChoice == 2)
                {
                  Nim Game = new Nim(PC, You);
                  Game.play();
                  System.out.print("Play again?\nEnter 1 for yes and 0 for no: ");
                  playAgain = choice.nextInt();
                }
                // do while loop for first or second
              }while (orderChoice != 1 && orderChoice != 2);

            }
            else
            {
              System.out.println("\nInvalid choice, please choose either 1 or 2.");
            }
          }
          while (playAgain != 0); // while the player wants to play
          break;
        }
        case 3:
        {
          System.out.println("Goodbye.");
          break;
        }

        default:
        {
          System.out.println("Invalid, please choose a valid menu choice.");
          break;
        }
      }
    }
    while (menuChoice != 3); // if its 3 quit 
  }
}