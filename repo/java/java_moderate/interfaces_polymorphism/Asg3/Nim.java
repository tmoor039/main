/**
 * Created by Tiago Moore on Feb 23, 2014. 
Updated 5 June 2018 
 * Nim Game Class
 * This file provides a Nim game object and the playing function
 * The playing method checks what the player wants to do based on their move method 
 * The Nim class also declares a winner in the play method  based on the player move 
 *
 */
public class Nim
{
  // private int totalMarbleNum;

  private Pile myPile; // Pile of marbles
  private Player P1;   // First player
  private Player P2;   // Second player
  private boolean winner;  // a boolean to tell if someone has won

/**
 * Constructor creates a Nim Game Object
 * @param playerOne the first player in the game
 * @param playerTwo the second player in the game
 */
  public Nim(Player playerOne, Player playerTwo)
  {
    P1 = playerOne;;
    P2 = playerTwo;
    myPile = new Pile(); 
    winner = false;

  }

/**
 * Method calls an individual Players move() method
 * while there is still 1 marble in the pile 
 */
  public void play()
  {
    // while there is more than 1 marble and no one has won
    while (myPile.getmarbles() != 1 && !winner)
    {
      // subtract the amount of marbles player 1 wants to take out from the 
      // total amount of marbles
      myPile.setmarbles(P1.move(myPile.getmarbles()));
      // if there is one marble left
      if (myPile.getmarbles() == 1)
      {
        //print the winner
        P1.printWinner();
        winner = true;
        break;
      }
      // subtract the amount of marbles player 2 wants to take out from the 
      // total amount of marbles  
      myPile.setmarbles(P2.move(myPile.getmarbles()));
      if (myPile.getmarbles() == 1)
      {
        P2.printWinner();
        winner = true;
      }
    }
  }


}
