import java.util.Comparator;

/**
 * Created by Tiago Moore on Oct 19, 2014.
 *
 */


/**
 * Class to be used with the BinaryTree class The node is of generic type
 */
public class BinaryTreeNode<Integer> 
{
  // private members of each node in the tree

  public int data; // the data of the tree (should be an integer for the tutorial)
  public BinaryTreeNode<Integer> leftNode; // a reference to the left child of the node
  public BinaryTreeNode<Integer> rightNode; // a reference to the right child of the node

  /**
   * Constructor that initializes all the private members of the Node to null
   */
  public BinaryTreeNode()
  {
    // You must initialize a node as being null fir`st!
    leftNode = rightNode = null;
  }

  /**
   * Constructor initializes the node of a tree with specific child
   * @param lN the left child
   * @param rN the right child
   * @param data the data to of the Node
   */
  public BinaryTreeNode(BinaryTreeNode<Integer> lN, BinaryTreeNode<Integer> rN, int data)
  {
    this.leftNode = lN;
    this.rightNode = rN;
    this.data = data;
  }
  
    /**
   * Mutator method to set the data to a specific value
   * @param x data being set
   */
  public void setNodeData(int x)
  {
    this.data = x;
  }
  
  // returns this string whenever a call to the object is invoked
  public String toString()
{
     return "" + this.data;
 }
  
  public boolean remove(int val, BinaryTreeNode<Integer> parent)
  {
      if(val < this.data){
          if(this.leftNode != null){
              return this.leftNode.remove(val, this);
          }else{
              return false;
          }
      }else if (val > this.data){
          if (rightNode != null)
              return this.rightNode.remove(val, this);
          else
              return false;
      }else {
          if(this.leftNode != null && this.rightNode != null){
              this.data = this.rightNode.minValue();
              this.rightNode.remove(this.data, this);
          }else if (parent.leftNode == this){
//                below is a turnuary operator it basically evalutes the statement 
//                and if the value is true then it returns the left not else it 
//                returns the right node 
                parent.leftNode = (leftNode != null) ? leftNode :  rightNode;
          }else if (parent.rightNode == this){
              parent.rightNode = (leftNode != null) ? leftNode : rightNode;
          }
          return true;
      }
    }
  
  public int minValue()
  {
     return  (leftNode == null ) ? this.data : leftNode.minValue();
   }


}
