
import java.util.*;
import javax.swing.JOptionPane;



/**
 * Created by Tiago Moore, Xavier Thomas, Jacob Leschen, Jose Ulloa, Patrick Cherisol on Oct 21,
 * 2014. findMin and findMax - Jose Ulloa TraverseWithPreOrder, Inorder, & PostOrder done by Patrick
 * Cherisol
 */
/**
 * This class will implement all the required assigment parameters for our tutorial Class will be
 * used directly by turorial.
 */
public class BinaryTreeUtility
{

  private BinaryTree tree; // Uses integer because of assignment requirements
  private String summary;// this will be the summary of everything the user has done


  public BinaryTreeUtility()
  {
    tree = new BinaryTree();
    summary = "You have learned the following concepts about a binary tree:";
  }


  /**
   * This method will explain what a binary tree is. - TMoore
   */
  public void explainBinaryTree()
  {
    JOptionPane.showMessageDialog(null, "A binary tree is a data structure that circumvents the prohibitive acess"
            + "time of linked lists.\n On average, the cost for most operations in a binary tree is "
            + "O(log N).\n A binary search tree is a collection of nodes, which have links to "
            + "de nodes.An example of a binary tree is printed below: \n\n");
    String input = JOptionPane.showInputDialog(null, "Select the best answer:\nWhat is a binary tree?\n"
            + "A) something that has children and parents\n"
            + "B) a data structures used for efficency\n"
            + "C) a data structure that circumvents the prohibitive access time of linked lists\n"
            + "D) a data struture that can be used in an actual garden\n");
    if (input.equalsIgnoreCase("c"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"a data structure that circumvents "
              + "the prohibitive access time of linked lists");
    }
    input = JOptionPane.showInputDialog(null, "Select the best answer:\nWhat is a binary search tree?\n"
            + "A) something that has children and parents\n"
            + "B) collection of nodes which have links to nodes\n"
            + "C) I have no clue\n"
            + "D) a data struture that can be used in an actual garden\n");
    if (input.equalsIgnoreCase("b"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer is\"collection of nodes which have links to nodes ");
    }
    input = JOptionPane.showInputDialog(null, "Select the best answer:\n"
            + "What is the average cost for most operations in a binary tree?\n"
            + "A) O(log n)\n"
            + "B) O(n^3)\n"
            + "C) O(n)\n"
            + "D) O(n^2)\n");
    if (input.equalsIgnoreCase("a"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer is\"O(log n) ");
    }



    // print a binary tree example


    summary += "\n*What a binary search tree is."; // add to the summary what the user has learned

  }


  /**
   * This method will explain binary tree terminology. -TMoore
   */
  public void explainTreeTerminology()
  {
    JOptionPane.showMessageDialog(null, "A generic tree sturcture will consist of a node called a ROOT."
            + "each root as zero or more non empty subtree(other nodes) each of these subtrees"
            + "roots are connected by a directed EDGE.A tree with N nodes will always have N-1 edges."
            + "\n\n The root of each subtree is said to be" + "a CHILD of the one preceding it, and "
            + "the root is also  a PARENT o each subtree " + "following it.\n\n"
            + "Each node can have any random numbet of children, even zero, but a Node with zero"
            + "children is called a LEAF. \nNodes that share the same parent are called SIBLINGS.\n"
            + "GRANDPARENT and GRANDCHILD relationships are determined in the same fashion as parent"
            + "and chils relationships.\nThe LENGTH of a path is equal to th enumber of edges of a path."
            + "\nThe DEPTH of a tree is unique to the path from root to whichever node we are"
            + "interested in.For instance, the root has depth 0.\nThe height of a node is the legth"
            + "of the longest path from the node to the deepest leaf. If there exists a path from"
            + "node1 to node2, then node 1 is a ANCESTOR of n2 and n2 is a DESCENDANT of n1. If"
            + "the nodes are the same, then the title changes to PROPER ancestor and descendant.\n");

    String input = JOptionPane.showInputDialog(null, "Fill in the blank:\n"
            + "A generic tree sturcture will consist of a node called a ROOT."
            + "each root as zero or more non empty subtree(other nodes) each of these subtrees"
            + "roots are connected by a directed______________?\n");
    if (input.equalsIgnoreCase("edge"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"edge");
    }
    input = JOptionPane.showInputDialog(null, "Fill in the blank:\nA tree with N nodes will always have ________ edges");

    if (input.equalsIgnoreCase("n-1"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"n-1");
    }
    input = JOptionPane.showInputDialog(null, "Fill in the blank: (Sepearate with a comma, no spaces)\nThe root of each subtree is "
            + "said to be a__________ of the one preceding it, and the root "
            + "is also  a _______ of each subtree following it.");

    if (input.equalsIgnoreCase("child,parent"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"child and parent");
    }
    input = JOptionPane.showInputDialog(null, "Fill in blank. Separate with comma, no spaces!\n"
            + "Each node can have any random numbet of children, even zero, but a Node with zero"
            + "children is called a ________. \nNodes that share the same parent are called ________.\n");
    if (input.equalsIgnoreCase("leaf,siblings"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"leaf and siblings");
    }
    input = JOptionPane.showInputDialog(null, "GRANDPARENT and GRANDCHILD relationships are determined in the same fashion as parent"
            + "and child relationships.\nThe LENGTH of a path is equal to the number of __________ of a path."
            + "\nThe DEPTH of a tree is unique to the path from __________ to whichever node we are interested in.\n"
            + "A) nodes, parent\nB) shortcuts, ancestors\nC) edges, root\nD) edges, tree");
    if (input.equalsIgnoreCase("c"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"edges, root");
    }
    input = JOptionPane.showInputDialog(null, "If there exists a path from node1 to node2, then node 1 is a ________ of n2 "
            + "and n2 is a __________ of n1. If the nodes are the same, then the title changes to PROPER ancestor and descendant.\n");
    if (input.equalsIgnoreCase("ancestor,descendant"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"ancestor,descendant");
    }

    summary += "\n*Basic tree terminology.";
  }


  /**
   * Jose Ulloa This method will simply print a tree correctly, and print an improper tree all will
   * just be done with print statements.
   */
  public void printRightNWrongTree()
  {

    JOptionPane.showMessageDialog(null, "Right vs. Wrong Tree: ");

    JOptionPane.showMessageDialog(null, "A tree is defined as a directed,acyclic structure of linked nodes."
            + "This means there are only one way links between nodes and no node wrap around to same node.\n\n");


    JOptionPane.showMessageDialog(null, "\"Examine this correct tree: \\n\"\t\t    5\n" + "\t\t   /" + " " + "\\\n"
            + "\t" + "   " + "3" + "   " + "7\n" + "\t" + "  " + "/" + " \\   " + "\\\n"
            + "\t" + " " + "2" + "   " + "4" + "   " + "8\n\n"
            + "There is only one path to each node.\n" + "Examine this incorrect tree: \n"
            + "\t\t 5\n" + "\t\t/" + " " + "\\" + "\n\t" + "3" + "   " + "7\n"
            + "\t" + "/" + " \\ " + "/" + "\t" + " " + "\n2" + "   " + "4"
            + "\nThere are two paths to the node containing 4\n");

    summary += "\n*How to determined right from wrong trees.";
  }


  /**
   * This method creates a tree based on the list of numbers the user inputs assuming its a string
   * can also be modified to take it as a text file
   * @param listofNumbers
   */
  public void createTree(String listOfNumbers)
  {
    tree = new BinaryTree();

    // this creates a string tokenizer and sets the deliminator to ","
    // so when we ask the user to enter a list of number each number
    // is seperated by a ","
    StringTokenizer str = new StringTokenizer(listOfNumbers, ",");
    Scanner parser = new Scanner(listOfNumbers);
    /*
     This loop just itterates through the list and then if there are more
     tokens it changes the string into an int stores it in a variable
     which is then passed into the insertNode method
     */
    while (str.hasMoreTokens())
    {
      int num = Integer.parseInt(str.nextToken());
      tree.insert(num);
    }




    // must add comments on how the tree was created internally



    // print the tree that was created




    summary += "\n*The process of creating a tree.";

  }


  /**
   * Jose Ulloa This method explains how to determine the node level
   */
  public void explainHowToDetermienNodeLevel()
  {

    JOptionPane.showMessageDialog(null, "Determining the level of a node: ");

    JOptionPane.showMessageDialog(null, "The level of a node is the length of the path "
            + "from the root to that node\n" + "Examine this tree: \n" + "\t\t    5\n"
            + "   \t\t/" + " " + "\\\n" + "\t" + "   " + "3" + "   " + "7\n"
            + "\t" + "  " + "/" + " \\   " + "\\\n" + "\t" + " " + "2" + "   " + "4" + "   " + "8\n\n"
            + "The level of the nodes containing 3,7 is level 1\n" + "The level of "
            + "nodes containing 2,4,8 is level 2\n\n");

    JOptionPane.showMessageDialog(null, "Determining the level of a node: \n"
            + "The level of a node is the length of the path from the root to that node\n"
            + "" + "Examine this tree: \n\n" + "\t\t 5\n" + "\t\t/" + " " + "\\"
            + "\t" + "   " + "\n 3" + "   " + "7\n" + "\t" + "/" + " \\   " + "\\"
            + "\t" + " " + "\n2" + "   " + "4" + "   " + "8\n" + "The level of the nodes containing 3,7 is level 1"
            + "The level of nodes containing 2,4,8 is level 2\n");

    summary += "\n*How to determine the level of a node.";

  }


  /**
   * Jose Ulloa,Tiago Moore This method will calculate and display the height of the tree to the
   * user with explanations
   */
  public void determineTreeHeight()
  {
    JOptionPane.showMessageDialog(null, "The tree height is :" + tree.getTreeHeight());

    JOptionPane.showMessageDialog(null, "The tree height is determined by determined by"
            + "the depth of the tree nodewise. Thefefore if the height of the tree will "
            + "be determined by the  level of the deepest leaf.");

    summary += "\n*Determining the height of a tree. ";
  }


  /**
   * This method will print each subtree individually and explain to the user why its a subtree
   * Method being worked on by Patrick Cherisol
   */
  public void determineSubTrees()
  {
    JOptionPane.showMessageDialog(null, "A subtree is a subset of the nodes of a binary tree that includes node R "
            + "of the tree as the subtree root along with all the descendants of R");
    JOptionPane.showMessageDialog(null, "Look at this binary tree. A binary tree will have a left subtree and a right subtree. "
            + "Click ok to see an example of a subtree\n               50\n              /     \\\n"
            + "            /        \\\n"
            + "         25         75\n"
            + "         /           /     \\\n    15           65      85\n"
            + "     /    \\                      \\\n  3     16                     100");

    JOptionPane.showMessageDialog(null, "This is a an example of a subtree of the binary tree. Click ok to see another example.\n         25\n"
            + "         /\n    15\n"
            + "     /    \\\n  3     16");
    JOptionPane.showMessageDialog(null, "This is a another example of a subtree of the same binary tree.\n"
            + "      15\n"
            + "     /    \\\n  3     16");

    String input = JOptionPane.showInputDialog(null, "Enter a node from the tree you created to see its subtree");
    int data = Integer.parseInt(input);
    if (!tree.contains(data))
    {
      JOptionPane.showMessageDialog(null, "The value entered is not in the tree");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "The subtree is printed using in-order traversal:\n" + tree.subtreeSearch(data));
    }
    summary += "\n*How to determine a SubTree";
  }


  /**
   * This method will display to the user all the parents and the users and explain why
   */
  public void showParentNdChildRelationships()
  {
    JOptionPane.showMessageDialog(null, "In a tree, the node P that directly links to a node A is the parent of A. A is the child of P.");

    JOptionPane.showMessageDialog(null, "Look at this binary tree. Which nodes do you think are the parent nodes?. "
            + "\n               50\n              /     \\\n"
            + "            /        \\\n"
            + "         25         75\n"
            + "         /           /     \\\n    15           65      85\n"
            + "     /    \\                      \\\n  3     16                     100"
            + "\n The parent nodes are: 15, 25, 50, 75, and 85");
    JOptionPane.showMessageDialog(null, "Lets now take a look at the leaf nodes of the tree that you created!");
    
    printTree();
    
    JOptionPane.showMessageDialog(null, " Below is a list of the parent nodes in the tree you created:"
            + "\n" + tree.ParentNodeString());
  }


  /**
   * This method will display all the leaf nodes in the tree and explain why they are leaf nodes
   * Method being worked on by Patrick Cherisol
   */
  public void determineLeafNodes()
  {
    String input = JOptionPane.showInputDialog(null, "What do you think a leaf node is?\n"
            + "A) any node that has children\n"
            + "B) any node that is directly pointed by another node\n"
            + "C) any node that has empty children\n"
            + "D) the topmost node of the tree");
    if (input.equalsIgnoreCase("c"))
    {
      JOptionPane.showMessageDialog(null, "You are correct!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "Sorry, incorrect answer."
              + "\nThe correct answer was \"A leaf node is any node that has two empty children");
    }
    JOptionPane.showMessageDialog(null, "In a binary tree, leaf node is any node that has "
            + "two empty children. \n(Note that a binary tree is defined so that every node has two "
            + "children, \nand that is why the leaf node has to have two empty children, rather than no\n "
            + "children.) In a general tree, any node is a leaf node if it has no children.");

    JOptionPane.showMessageDialog(null, "Look at this binary tree. Which nodes do you think are the leaf nodes?. "
            + "\n               50\n              /     \\\n"
            + "            /        \\\n"
            + "         25         75\n"
            + "         /           /     \\\n    15           65      85\n"
            + "     /    \\                      \\\n  3     16                     100");
    JOptionPane.showMessageDialog(null, "If you answered 3, 16, 65, 100, then you are correct!\nAll"
            + " of the nodes have children, but it is only these nodes that have empty children.\n\n"
            + "Lets take a look at the leaf nodes of the tree that you created!");
    
            printTree();

    JOptionPane.showMessageDialog(null, " Below is a list of the leaf nodes in the tree you created:"
            + "\n" + tree.leafNodeString());



    summary += "How to determine if a node is a leaf.";
  }


  /**
   * Jose Ulloa - Could be more efficient with loops and such but should still be running at O(n)
   * This method will illustrate the concept of balanced trees vs unblanaced trees
   */
  public void showBallencesVsUnbalanced()
  {

    JOptionPane.showMessageDialog(null, "Balanced and unbalanced trees: \n\n"
            + "A balanced tree is a tree that its left and right subtree only differ by a maximum height of one\n"
            + "An example of a balanced tree: \n\n" + "\t    5\n" + "\t\t /" + "    " + "\\\n"
            + "\t" + "   " + "3" + "   " + "7\n" + "\t" + "  " + "/" + " \\   " + "\\"
            + "\n\t" + " " + "2" + "   " + "4" + "   " + "8\n"
            + "Diffence of left subtree heigt and right subtree height is (1-1 = 0)\n"
            + "An example of a unbalanced tree: \n\n" + "\t  5\n" + "\t\t/" + " " + "\\"
            + "\t" + "   " + "\n 3" + "  " + "7" + "\n\t" + "   " + "/" + " \\   "
            + "\n\t" + " " + "2" + "   " + "4" + "\n  " + "/"
            + "   " + "\n 1\n\n" + "Diffence of left subtree heigt and right subtree height is (2-0 = 2)");

    summary += "\n*How to determine if a tree is balanced or unbalanced.";
  }


  /**
   * method done by Patrick Cherisol, Tiago Moore This method will traverse the tree in pre order
   * and print the result also with an explanation
   */
  public void traverseWithPreOrder()
  {
    // print the tree
    JOptionPane.showMessageDialog(null, "The pre-order traversal first vists the root\n"
            + " and then recursively visits the left child, and then recursively visits\n"
            + "the right child.");

    JOptionPane.showMessageDialog(null, "Look at this binary tree. Whats the pre-order traversal of this tree?. "
            + "\n               50\n              /     \\\n"
            + "            /        \\\n"
            + "         25         75\n"
            + "         /           /     \\\n    15           65      85\n"
            + "     /    \\                      \\\n  3     16                     100");

    JOptionPane.showMessageDialog(null, "The answer is: 50, 25, 15, 3, 16, 75, 65, 85, 100\nClick ok to continue");
    JOptionPane.showMessageDialog(null, " Using pre order traversal, the nodes of the tree"
            + " you created were visited in the following order:"
            + "\n" + tree.preOrderString());
    
    
    
    
    
    
    
    

    summary += "\n*Traversing the pre-order.";

  }


  /**
   * Method done by Patrick Cherisol,Tiago Moore This method will traverse the tree in Inorder and
   * print the result also with an explanation
   */
  public void traverseWithInOrder()
  {

    JOptionPane.showMessageDialog(null, "An inorder traversal first visits the left child (including its entire subtree)\n,"
            + " then visits the node, and finally visits the right child\n (including its entire subtree). The binary search \n"
            + "tree makes use of this traversal to print \nall nodes in ascending order of value.");

    JOptionPane.showMessageDialog(null, "Look at this binary tree. Whats the in-order traversal of this tree?. "
            + "\n               50\n              /     \\\n"
            + "            /        \\\n"
            + "         25         75\n"
            + "         /           /     \\\n    15           65      85\n"
            + "     /    \\                      \\\n  3     16                     100");

    JOptionPane.showMessageDialog(null, "The answer is: 3, 15, 16, 25, 50, 65, 75, 85, 100\nClick ok to continue");
    JOptionPane.showMessageDialog(null, " Using in order traversal, the nodes in the tree you created"
            + "\nwere visited in the following "
            + "order:\n " + tree.inOrderString());



    JOptionPane.showMessageDialog(null, " Using in order traversal, the nodes were visited in the following "
            + "order:\n " + tree.inOrderString());


    // add paragraph output to user explaining how it is being traversed
    summary += "\n*Traversing the in-order.";

  }


  /**
   * Method done by Patrick Cherisol,Tiago Moore This method will traverse the tree in post order
   * and print the result also with an explanation
   */
  public void traverseWithPostOrder()
  {
    JOptionPane.showMessageDialog(null, "The pre-order traversal first vists left child\n"
            + " and then recursively visits the right child, and then recursively visits\n"
            + "the root.");

    JOptionPane.showMessageDialog(null, "Look at this binary tree. Whats the post-order traversal of this tree?. "
            + "\n               50\n              /     \\\n"
            + "            /        \\\n"
            + "         25         75\n"
            + "         /           /     \\\n    15           65      85\n"
            + "     /    \\                      \\\n  3     16                     100");

    JOptionPane.showMessageDialog(null, "The answer is: 3, 16, 15, 25, 65, 100, 85, 75, 50\nClick ok to continue");


    JOptionPane.showMessageDialog(null, " Using post order traversal, the nodes were visited in the following order:\n"
            + tree.postOrderString());

    summary += "\n*Traversing the post-order.";

  }


  public void printTree()
  {
    tree.printTree();
  }


  /**
   * Inserts a node into the tree for all cases
   * @param x the number of the node the user would like to add Xavier Thomas, Tiago Moore
   */
  public void insertNode(int x)
  {
    // add the node to the tree
    tree.insert(x);
    JOptionPane.showMessageDialog(null, "A node with the value " + x + " has been added to the tree.");

    //print tree

    // a paragraph will be outputted to the user on how insterting is done
    // add a paragraph with a general algortihm to insert a node into a tree
    // add a paragrah with how we did it in this program and include code snippet

    summary += "\n* Inserting a node into a tree.";
  }


  /**
   * Displays the minimum value to the user Tiago Moore, Jose Ulloa
   */
  public void findMin()
  {

    if (tree.findMin() == Integer.MAX_VALUE)
    {
      JOptionPane.showMessageDialog(null, "The tree is empty!!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "The minimum value of the tree you created is: " + tree.findMin());
    }


    JOptionPane.showMessageDialog(null, "The following steps were taken to find the minimum value in the tree: \n"
            + "1)We must identify if the tree is empty, if it is then return that the tree is empty \n"
            + "2)If the tree is not empty, then we can assume that the binary tree has a minimum value \n"
            + "3)In a binary tree, the child to the left of the current node will always be less than that node, "
            + "anything to the right will be bigger than the current node. \n"
            + "4)Using a while loop, we traverse the tree until we get to the furthest left node and this will be our minimum value \n");

    summary += "\n*Finding the minimum value in a tree. ";
  }


  /**
   * Displays the maximum node, should just call method from tree class
   *
   * Tiago Moore, Jose Ulloa
   */
  public void findMax()
  {
    if (tree.findMax() == Integer.MIN_VALUE) // test to see if tree is empty
    {
      JOptionPane.showMessageDialog(null, "The tree is empty!!");
    }
    else
    {
      JOptionPane.showMessageDialog(null, "The maximum value of the tree you created is: " + tree.findMax());
    }



    JOptionPane.showMessageDialog(null, "The following steps were taken to find the maximum value in the tree: \n"
            + "1)We must identify if the tree is empty, if it is then return that the tree is empty \n"
            + "2)If the tree is not empty, then we can assume that the binary tree has a maximum value \n"
            + "3)In a binary tree, the child to the right of the current node will always be more than that node, "
            + "anything to the left will be smaller than the current node. \n"
            + "4)Using a while loop, we traverse the tree until we get to the furthest right node and this will be our maximum value \n");

    summary += "\n*Finding the maximum value of a tree. ";

  }


  /**
   * Being worked on by Jacob Leschen I am assuming that the remove method in BinaryTree implements
   * the correct repositioning of nodes after a deletion as such, this method as I am writing it now
   * is not much more than a specialized search Deletes a node for each instance of the data being
   * equal to the requested value Runs in O(logN)
   * @param x the value of the node the user wants to remove
   */
  public void deleteN(int n)
  {
    JOptionPane.showMessageDialog(null, "The Node To be deleted contains the data " + n);
    tree.remove(n);
  }


  /**
   * Being worked on by Jacob Leschen Prints the tree in a list format Works in an in-order
   * traversal Takes running time O(n)
   *
   */
  public void printSummary()
  {

    JOptionPane.showMessageDialog(null, summary);
  }


  
}
