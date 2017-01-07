import javax.swing.JOptionPane;

/**
 * Binary tree class is to be used with the TreeNode, will have all the basic methods of any generic
 * binary search tree
 *
 */
public class BinaryTree
{

  public BinaryTreeNode<Integer> root;
  private int count;
  private String output = "";


  /**
   * Constructor
   */
  public BinaryTree()
  {
    root = null;
  }


  /**
   * Empties the tree
   */
  public void makeEmpty()
  {
    root = null;
  }


  /**
   * THis method has a problem comparing the primitive to the object, needs to fix
   * @return `
   */
  public Boolean contains(int x)
  {
    try
    {
      BinaryTreeNode<Integer> temp = root;
      if (temp == null)
      {
        return false;
      }
      else if (temp.data == x)
      {
        return true;
      }
      else
      {
        BinaryTreeNode Parent;
        while (true)
        {
          Parent = temp;
          if (x < temp.data)
          {
            temp = temp.leftNode;
            if (temp.data == x)
            {
              return true;
            }
          }
          else if (x > temp.data)
          {
            temp = temp.rightNode;
            if (temp.data == x)
            {
              return true;
            }
          }
        }
      }
    }
    catch (NullPointerException e)
    {
      /*
       the above statments return null if the value is not found
       Hence the catch statement so we can output false if the value is 
       Not found? 
       */
      return false;
    }
  }

/**
 * Looks for  sub stree
 * @param x the node the user enters
 * @return the subtree
 */
  public String subtreeSearch(int x)
  {
    try
    {
      BinaryTreeNode<Integer> temp = root;
      if (temp == null)
      {
        return "Empty Tree";
      }
      else if (temp.data == x)
      {
        String s = inOrderTraversal(temp);
        clearOutput();
        return s;
      }
      else
      {
        BinaryTreeNode<Integer> Parent;
        while (true)
        {
          Parent = temp;
          if (x < temp.data)
          {
            temp = temp.leftNode;
            if (temp.data == x)
            {
              String s = inOrderTraversal(temp);
              clearOutput();
              return s;
            }
          }
          else if (x > temp.data)
          {
            temp = temp.rightNode;
            if (temp.data == x)
            {
              String s = inOrderTraversal(temp);
              clearOutput();
              return s;
            }
          }
        }
      }
    }
    catch (NullPointerException e)
    {
      /*
       the above statments return null if the value is not found
       Hence the catch statement so we can output false if the value is 
       Not found? 
       */
      return "Number Not Found";
    }
  }


  /**
   * Displays the smallest node, should call from tree class
   *
   * Jose Ulloa
   */
  public Integer findMin()
  {
    BinaryTreeNode temp = root;
    if (root == null)
    {
      return null;
    }
    else if (root.leftNode == null)
    {
      return root.data;
    }
    else
    {
      while (true)
      {
        if (temp.leftNode != null)
        {
          temp = temp.leftNode;
        }
        else
        {
          return (Integer) temp.data;
        }
      }
    }
  }


  /**
   * Displays the maximum node, should just call method from tree class
   *
   * Jose Ulloa
   */
  public Integer findMax()
  {
    BinaryTreeNode temp = root;
    if (root == null)
    {
      return null;
    }
    else if (root.leftNode == null)
    {
      return root.data;
    }
    else
    {
      while (true)
      {
        if (temp.rightNode != null)
        {
          temp = temp.rightNode;
        }
        else
        {
          return (Integer) temp.data;
        }
      }
    }

  }


  /**
   * Inserts a value into a specific node Done by Xavier, Assuming it works, it will add a node with
   * an integer to the tree
   */
  public void insert(Integer x)
  {

    BinaryTreeNode<Integer> Node = new BinaryTreeNode();

    Node.setNodeData(x);

    if (root == null)
    {
      root = Node;
    }
    else
    {
      BinaryTreeNode<Integer> focusNode = root;
      BinaryTreeNode<Integer> parentNode;
      while (true)
      {
        parentNode = focusNode;
        if (x < focusNode.data)
        {
          focusNode = focusNode.leftNode;
          if (focusNode == null)
          {
            parentNode.leftNode = Node;
            break;
          }
        }
        else
        {
          focusNode = focusNode.rightNode;
          if (focusNode == null)
          {
            parentNode.rightNode = Node;
            break;
          }
        }
      }
    }
    count++;
  }


  /**
   * Patrick Cherisol, Tiago Moore       
   * Big O Is O(n)
   * @param root
   * @return a string of integers in the order specified. Might need to change toString method to
   * return the value and not the node itself
   */
  public String preOrderTraversal(BinaryTreeNode r)
  {
    if (r != null)
    {
      this.output += r + " ";
      preOrderTraversal(r.leftNode);
      preOrderTraversal(r.rightNode);
    }
    return this.output;
  }


  /**
   * Tiago Moore Uses method above to return the order to the utility class
   * @return the string in pre order format
   */
  public String preOrderString()
  {
    String temp = preOrderTraversal(root);
    clearOutput();
    return temp;
  }


  public void clearOutput()
  {
    this.output = "";
  }


  ; // clears the output

  /**
   * Patrick Cherisol, Tiago Moore 
   * Big O Is O(n)
   * @param root
   * @return a string of integers in the order specified. Might need to change toString method to
   * return the value and not the node itself
   */
  public String postOrderTraversal(BinaryTreeNode r)
  {
    if (r != null)
    {
      postOrderTraversal(r.leftNode);
      postOrderTraversal(r.rightNode);
      this.output += r + " ";
    }
    return this.output;
  }


  /**
   * Tiago Moore Uses method above to return the order to the utility class
   * @return the string in post order format
   */
  public String postOrderString()
  {
    String temp = postOrderTraversal(root);
    clearOutput();
    return temp;
  }


  /**
   * Xavier
   * Big O Is O(n)
   * @param root
   * @return a string of integers in the order specified. Might need to change toString method to
   * return the value and not the node itself
   */
  public String inOrderTraversal(BinaryTreeNode r)
  {
    if (r != null)
    {
      inOrderTraversal(r.leftNode);
      this.output += r + " ";
      inOrderTraversal(r.rightNode);
    }
    return this.output;
  }


  /**
   * Tiago Moore Uses method above to return the order to the utility class
   * @return the string in in order format
   */
  public String inOrderString()
  {
    String temp = inOrderTraversal(root);
    clearOutput();
    return temp;
  }

/**
 * Group effort
 * @param r the node the user is looking for 
 * @return true if leaf
 */
  private String leafNodes(BinaryTreeNode r)
  {
    if (r != null)
    {
      leafNodes(r.leftNode);
      if (r.leftNode == null && r.rightNode == null)
      {
        this.output += r + " ";
      }
      leafNodes(r.rightNode);
    }
    return this.output;
  }

/**
 * method to be called in utility
 * @return 
 */
  public String leafNodeString()
  {
    String temp = leafNodes(root);
    clearOutput();
    return temp;
  }
  /*
   * Mathod done by Patrick Cherisol
   * This method will traverse the tree and find all the parent nodes
   *@param is the root
   */

/**
 * Group Effort
 * the node the user is looking for 
 * @param node
 * @return the parent node 
 */
  private String parentNode(BinaryTreeNode node)
  {
    if (node != null)
    {
      parentNode(node.leftNode);
      if (node.leftNode != null || node.rightNode != null)
      {
//                System.out.println(node + " is a parent node");
        this.output += node + " ";
        //System.out.println(focusNode.leftChild.data);
      }
      else
      {
        System.out.println(node + " ");
      }


      parentNode(node.rightNode);
    }
    return this.output;
  }

/**
 * method to be called in utility
 * @return 
 */
  public String ParentNodeString()
  {
    String temp = parentNode(root);
    clearOutput();
    return temp;
  }


  /**
   * Removes a node from the tree
   */
  public boolean remove(Integer x)
  {
    if (!contains(x))
    {
      return false;
    }
    else
    {
      if (root.data == x)
      {
        BinaryTreeNode node = new BinaryTreeNode();
        node.leftNode = root;
        boolean result = root.remove(x, node);
        root = node.leftNode;
        return result;
      }
      else
      {
        return root.remove(x, null);
      }
    }
  }


  /**
   *  Worked on by Jacob Leschen, method takes an argument node and displays the path taken to
   * reach
   * @param n the value in the node being requested runs in time O(logN)
   */
  public void printPathToNode(Integer n)
  {
    if (root == null || !contains(n))
    {
      System.out.println("ERROR, tree is empty");
      return;
    }
    String path = "{ ";
    path = path + printPathToNode(root, "", n);
    path = path + "}";
    System.out.println("Path to node " + n + ": " + path);
  }


  /**
   * recursive method for printing out the path to an argument node
   * @param r the root
   * @param path the string that will be updated with each iteration
   * @param n the value requested by the user
   * @return the path string after the update runs in time O(logN)
   */
  private String printPathToNode(BinaryTreeNode r, String path, int n)
  {
    path = path + r.data + " ";
    if (r.data != n)
    {
      if ((n < (Integer) r.data) && (r.leftNode != null))
      {
        path = printPathToNode(r.leftNode, path, n);
      }
      else if ((n > (Integer) r.data) && (r.rightNode != null))
      {
        path = printPathToNode(r.rightNode, path, n);
      }
    }

    return path;
  }


  /**
   * Jose Ulloa Uses method to return the height of the tree recursevily
   * @return the height of the tree as a int
   */
  private int getHeight(BinaryTreeNode n)
  {
    if (n == null)
    {
      return - 1; //Will actually return zero since your adding one in the recursive call before it
    }
    else
    {
      return Math.max(getHeight(n.leftNode), getHeight(n.rightNode)) + 1; //returns the height of the bigger subtree plus one
    }

  }


  /**
   * tmoore
   * @param x node user is looking for
   * @return level of the node
   */
  private int findNodeLevel(BinaryTreeNode x)
  {
    int count = 0;
    if (root == null)
    {
      return 0;// level is 0
    }
    else if (root == x)
    {
      count++;
      return count;
    }
    else
    {
      count++;
      findNodeLevel(root.leftNode);
      findNodeLevel(root.rightNode);
      return count;
    }
  }

/**
 * 
 * @param x the node of the node the user entered
 * @return the node level
 */
  public int getNodeLevel(Integer x)
  {
    BinaryTreeNode y = new BinaryTreeNode();
    y.data = x;

    return findNodeLevel(y);
  }


  /**
   * Helper method for the height - tMoore
   * @param x
   * @return
   */
  public int getTreeHeight()
  {

    int height = getHeight(root);

    return height + 1;

  }

  /**
   * Being worked on by Jacob Leschen Prints out the tree to the output,
   * Unfortunatly, this method has a bug and will not work. So we are commenting out
   * everywhere the tree was supposed to be printed with the values the user inputted 
   * spaced and formatted for easy viewing
   * Runs in time O(n)
   */
  public void printTree()
  {
    String out = "";
    int h = getTreeHeight();
    switch (h)
    {
      case (0):
        JOptionPane.showMessageDialog(null,"ERROR: Tree is emtpy");
        break;
      case (1):
        JOptionPane.showMessageDialog(null,root.data);
        break;
      case (2):
        out = "  " + root.data + "\n" + root.leftNode.data;
        if (root.rightNode != null)
        {
          out += "  " + root.rightNode.data;
        }
        JOptionPane.showMessageDialog(null, out);
        break;
      case (3):
        out = "        " + root.data + "\n    " + root.leftNode.data
                + "       " + root.rightNode.data + "\n" + root.leftNode.leftNode.data;
        
        if (root.leftNode.rightNode != null)
        {
          out += "  " + root.leftNode.rightNode.data;
          if (root.rightNode.leftNode != null)
          {
            out += "      " + root.rightNode.leftNode.data;
            if (root.rightNode.rightNode != null)
            {
              out += "  " + root.rightNode.rightNode.data;
            }
          }
        }
        JOptionPane.showMessageDialog(null, out);
        break;
      case (4):
        out = "                 " + root.data + "\n      "
                + root.leftNode.data + "                   " + root.rightNode.data
                + "\n  " + root.leftNode.leftNode.data + "       "
                + root.leftNode.rightNode.data + "         "
                + root.rightNode.leftNode.data + "       "
                + root.rightNode.rightNode.data + "\n"
                + root.leftNode.leftNode.leftNode.data;
        if (root.leftNode.leftNode.rightNode != null)
        {
          out += "  " + root.leftNode.leftNode.rightNode.data;
          if (root.leftNode.rightNode.leftNode != null)
          {
            out += "   " + root.leftNode.rightNode.leftNode.data;
            if (root.leftNode.rightNode.rightNode != null)
            {
              out += "  " + root.leftNode.rightNode.rightNode.data;
              if (root.rightNode.leftNode.leftNode != null)
              {
                out += "   " + root.rightNode.leftNode.leftNode.data;  
                if (root.rightNode.leftNode.rightNode != null)
                {
                  out += "  " + root.rightNode.leftNode.rightNode.data;  
                  if (root.rightNode.rightNode.leftNode != null)
                  {
                    out += "   " + root.rightNode.rightNode.leftNode.data;
                    if (root.rightNode.rightNode.rightNode != null)
                    {
                      out += "  " + root.rightNode.rightNode.rightNode.data;
                    }
                  }
                }
              }
            }
          }
        }
        JOptionPane.showMessageDialog(null, out);
        break;
      case (5):
        out = "                        " + root.data + "\n          "
                + root.leftNode.data + "                          " + root.rightNode.data
                + "\n     " + root.leftNode.leftNode.data + "          "
                + root.leftNode.rightNode.data + "            "
                + root.rightNode.leftNode.data + "          "
                + root.rightNode.rightNode.data + "\n"
                + "  " + root.leftNode.leftNode.leftNode.data
                + "    " + root.leftNode.leftNode.rightNode.data
                + "     " + root.leftNode.rightNode.leftNode.data
                + "    " + root.leftNode.rightNode.rightNode.data
                + "     " + root.rightNode.leftNode.leftNode.data
                + "    " + root.rightNode.leftNode.rightNode.data
                + "    " + root.rightNode.rightNode.leftNode.data
                + "    " + root.rightNode.rightNode.rightNode.data
                + "\n" + root.leftNode.leftNode.leftNode.leftNode.data;
        if (root.leftNode.leftNode.leftNode.rightNode != null)
        {
          out += "  " + root.leftNode.leftNode.leftNode.rightNode.data;
        }
        JOptionPane.showMessageDialog(null,out);
        break;
      default:
        System.out.println("ERROR: the tree in question does not fit the required"
                + "parameters, or is not a binary search tree. P again");
    }

  }



}
