
/**
 *This creates a player interface to be played with Nim
 * @author tmoore
 */
public interface Player
{
  /**
   * A move method for each individual player
   * @param numOfMarbles the total amount of marbles in the pile
   * @return the amount of marbles to remove from the pile 
   */
    int move(int numOfMarbles);
    /**
     * Prints a unique message for each individual player 
     */
    void printWinner();

}
