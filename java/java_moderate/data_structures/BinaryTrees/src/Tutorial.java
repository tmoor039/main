
/**
 *
 * Created by Tiago Moore, Xavier Thomas, Jacob Leschen, Patrick Cherisol on Oct 21, 2014.
 * Instructor: Debra Davis Section 2 We affirm that this program is entirely my own work and none of
 * it is the work of any other person.
 */
import java.util.*;
import javax.swing.JOptionPane;
import java.lang.NullPointerException;



/**
 * Class to implement a query based tutorial.Turorial will be text based and driven off a menu which
 * will ask the user what he/she wants to learn
 */
public class Tutorial
{

  /**
   * Main class should be driven by a menu to fufill all assigment requirements
   * @param args
   */
  @SuppressWarnings("empty-statement")
  public static void main(String[] args)
  {
    try
    {

      int mainMenuSelection = 0, tutorialMenuSelection = 0;
      Scanner input = new Scanner(System.in);
      BinaryTreeUtility tutorialUtility = new BinaryTreeUtility();

      JOptionPane.showMessageDialog(null, "\n\n******************************************WELCOME TO "
              + "OUR BINARY TREE TUTORIAL!"
              + "******************************************************\n"
              + "This Tutorial was brought to you by:"
              + "\nTiago Moore\nXavier Thomas\nPatrick Cherisol\nJacob Leschen\nJose Ulloa");


      do
      {
        String select = JOptionPane.showInputDialog(null, "\nPlease select what you would like to do : \n1) See Tutorial Rules.\n2) Start the tutorial. \n3) Quit.");
        mainMenuSelection = Integer.parseInt(select);



        if (mainMenuSelection == 1)
        {
          JOptionPane.showMessageDialog(null, "\n\"You have chosen to see the tutorial rules!\n"
                  + "Are you ready? Then click OK!");

          JOptionPane.showMessageDialog(null, "This tutorial will work in the following manner: \n\n"
                  + "When you choose to option 2 for start tutorial, you will enter a command line based "
                  + "tutorial on binary search trees implemented by the java programming language.\n"
                  + "You will have the option of choosing between several options, which will instruct "
                  + "you on how binary trees work. If you choose to exit, without completing the entire "
                  + "tutorial, you will be given a summary on the completetion of the tutorial.\n\n"
                  + "YOU MUST CREATE A TREE FIRST BEFORE TRYING TO RUN OPERATIONS ON THE TREE\n\n"
                  + "Please select 2 to start the tutorial, or 3 to quit.\n\n");
        }
        else if (mainMenuSelection == 2)
        {
          do
          {


            select = JOptionPane.showInputDialog(null, "Select what would you like to learn:\n"
                    + "1) Learn what a binary tree is.\n"
                    + "2) Create a binary tree and learn how it was created.\n"
                    + "3) Learn the differences between a right and wrong and  and "
                    + "balanced vs unbalanced trees.\n"
                    + "4) Learn about tree terminology.\n"
                    + "5) Learn how to determine a node level.\n"
                    + "6) Learn how to determine the tree height.\n"
                    + "7) Learn how to determine sub trees of a binary tree.\n"
                    + "8) Learn about parent anc child relationships.\n"
                    + "9) Learn how to determine if a particular node on a tree is a leaf.\n"
                    + "10) Learn how to traverse a tree using pre-order traversal.\n"
                    + "11) Learn how to traverse a tree using in-order traversal.\n"
                    + "12) Learn how to traverse a tree using post-order traversal.\n"
                    + "13) Learn how to insert a node into the tree.\n"
                    + "14) Learn how find a minimum value in the tree.\n"
                    + "15) Learn how to find a maximum value in the tree.\n"
                    + "16) Learn how to delete a node from the tree.\n"
                    + "17) Print the Binary tree with the values you entered.\n"
                    + "18) Exit to main menu.");


            tutorialMenuSelection = Integer.parseInt(select);
            switch (tutorialMenuSelection)
            {
              case 1:
              {
                JOptionPane.showMessageDialog(null, "\nYou have chosen to learn what a binary tree is.\n"
                        + "Are you ready? Then click OK!");
                tutorialUtility.explainBinaryTree();
                break;
              }
              case 2:
              {
                String treeNumbers = "";

                JOptionPane.showMessageDialog(null, "You have chosen to create a binary tree.\n");

                treeNumbers = JOptionPane.showInputDialog(null, "First, enter a series of numbers"
                        + " separated by a comma.\n" + "Example: (1,2,3,4,5).\n\n");

                tutorialUtility.createTree(treeNumbers);// calll method to create tree

                //tutorialUtility.printTree();

                break;
              }
              case 3:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn the differences between a right and wrong tree.\n");
                tutorialUtility.showBallencesVsUnbalanced();
                tutorialUtility.printRightNWrongTree();
                break;
              }
              case 4:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn tree terminology.\n");
                tutorialUtility.explainTreeTerminology();
                break;
              }
              case 5:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn how to determine a node level.\n");


                tutorialUtility.explainHowToDetermienNodeLevel();;

                break;
              }
              case 6:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to determine the tree height.\n");

                JOptionPane.showMessageDialog(null, "\n This is the tree you entered: .\n");

                tutorialUtility.determineTreeHeight();;
                break;
              }
              case 7:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn about sub trees.\n");

                tutorialUtility.determineSubTrees();
                break;
              }
              case 8:
              {
                JOptionPane.showMessageDialog(null, "You have chosen learn about anscentry relationships\n");
                tutorialUtility.showParentNdChildRelationships();
                break;
              }
              case 9:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn about tree leafs.\n");
                tutorialUtility.determineLeafNodes();

                break;
              }
              case 10:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn about pre order traversal.\n");
                tutorialUtility.traverseWithPreOrder();
                break;
              }
              case 11:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn about in order traversal.\n");
                tutorialUtility.traverseWithInOrder();
                break;
              }
              case 12:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to learn about post order traversal.\n");
                tutorialUtility.traverseWithPostOrder();
                break;
              }
              case 13:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to insert a node into the binary tryy.\n");
                int numberToInsert;
                String input2;

                input2 = JOptionPane.showInputDialog(null, "Enter the number for the node you would like to insert.\n");
                numberToInsert = Integer.parseInt(input2);

                tutorialUtility.insertNode(numberToInsert);

                break;
              }
              case 14:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to find the minimum value of the tree.\n");

                tutorialUtility.findMin();

                break;
              }
              case 15:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to find the maximum value of the tree.\n");

                tutorialUtility.findMax();
                break;
              }
              case 16:
              {
                JOptionPane.showMessageDialog(null, "You have chosen to delete a node from the tree.\n");

                String blur = JOptionPane.showInputDialog(null, "Enter the value of the node you would like to delete from the tree");

                Integer blar = Integer.parseInt(blur);


                tutorialUtility.deleteN(blar);

                break;
              }
              case 17:
              {
                JOptionPane.showMessageDialog(null, "This is what your binary tree looks like: \n\n");
                tutorialUtility.printTree();
                break;
              }
              case 18:
              {
                JOptionPane.showMessageDialog(null, "Thank you for learning about binary trees!");

                tutorialUtility.printSummary();

                break;
              }

              default:
              {
                JOptionPane.showMessageDialog(null, "Invalid input. Please enter a number between 1-18 inclusive.");
              }
            }

          }
          while (tutorialMenuSelection != 18);

        }
        else if (mainMenuSelection == 3)
        {
          JOptionPane.showMessageDialog(null, "Goodbye.");
        }
      }
      while (mainMenuSelection != 3);
      if (mainMenuSelection != 1 && mainMenuSelection != 2 && mainMenuSelection != 3)
      {
        JOptionPane.showMessageDialog(null, "Invalid input. Please enter a number between 1-3 inclusive.");
      }
    }
    catch (NumberFormatException | NullPointerException d)
    {
      System.out.println("The Selection you made ether returned a null value \n");
      System.out.println("Or you tried to click okay without actually entering a value ");
    }
  }


}
