import java.util.Map;
import java.util.Iterator;
import javafx.animation.KeyValue;


/**
 * A class that implements a hashMap. 
 * This class will work as follows. Two hash functions will hash to the same array
 * the hash functions will hash to the smaller list index given by the hash functions.
 * @author tmoore
 * @param <KeyType>
 * @param <ValueType> 
 */
public class MyHashMap<KeyType, ValueType> implements Iterable<Map.Entry<KeyType, ValueType>>
{

  private HashFunction<KeyType> hash1; // assume this is the standard %mod hash function 
  private HashFunction<KeyType> hash2;

  private static final int DEFAULT_ARRAY_SIZE = 11;

  private Node<KeyType, ValueType>[] arr = null;
  private int theSize = 0; // size of the array 

  public MyHashMap(HashFunction<KeyType> h1, HashFunction<KeyType> h2)
  {
    hash1 = h1;
    hash2 = h2;
    theSize = 0;
    arr = new Node[DEFAULT_ARRAY_SIZE];
    // populate the array with empty nodes // initialize if 
    for (int i = 0; i < DEFAULT_ARRAY_SIZE; i++)
    {
      arr[i] = new Node<KeyType, ValueType>(null, null, null);
    }
  }

  /**
   * A method to get the lengths of each list in the has table
   * @return an array of the length of each list
   */
  public int[] getLengths()
  {
    int sum = 0;
    int lengthArray[] = new int[arr.length];// create an array to be returuned(size 11) 

    Node<KeyType, ValueType> current = new Node();

    for (int i = 0; i < arr.length; i++)
    {
      // check to see if there is a node, if there is add one to the count and cound preceding nodes
      if (arr[i] instanceof Node)
      {
        sum++; // found one 
        current = arr[i];// now find more 
        while (current.next != null)
        {
          sum++;// add to sum
          current = current.next; // move node using to traverse the linked list  
        }
        lengthArray[i] = sum; // set sum to that position
        sum = 0;// reset sum 
      }
      else
      {
        lengthArray[i] = sum; // else there is no node there and its zero so return zero to position
      }

    }

    return lengthArray;
  }

  public int size()
  {
    return theSize;
  }

  /**
   * Clears the hashtable
   */
  public void clear()
  {
    theSize = 0;
    arr = new Node[DEFAULT_ARRAY_SIZE];
    // populate the array with empty nodes // initialize if 
    for (int i = 0; i < DEFAULT_ARRAY_SIZE; i++)
    {
      arr[i] = new Node<KeyType, ValueType>(null, null, null);
    }
  }

  /**
   * Helper method to determine which list is smaller. Will return the array index of the smaller
   * list
   * @param x the first hash functions hash value
   * @param y the second hash functions hash value
   * @return the smaller of the two hash values
   */
  private int smallerList(int x, int y)
  {
    int temparray[] = getLengths();
    int smallerIndex = -1;
    int firstListCounter = 0;
    int secondListCounter = 0;

    Node temp = arr[x];
    if (temp.key == null)
    {
      smallerIndex = x;
      return smallerIndex;
    }
    else if (temp.key != null)
    {
      firstListCounter++;
      while (temp.next != null)// count the number of nodes in that list 
      {
        temp = temp.next;
        firstListCounter++;
      }

      // do the same for the second list 
      temp = arr[y];
      if (temp.key == null)
      {
        smallerIndex = y;
        return smallerIndex;
      }
      else if (temp.key != null)
      {
        secondListCounter++;
        while (temp.next != null)// count the number of nodes in that list 
        {
          temp = temp.next;
          secondListCounter++;
        }
      }

      if (secondListCounter < firstListCounter) // if the second is smaller than the first
      {
        return y; // the second is smaller, return the smaller index
      }
    }

    return x; // otherwise return the  first list 
  }

  /**
   * Method to insert a key in the hash table and return the vallue
   * @param k
   * @param v
   * @return the value of the old key in the table, or null if it was nothing there
   */
  public ValueType put(KeyType k, ValueType v)
  {
    Node temp = new Node(k, v, null);
    ValueType put = null;
    int smallestListIndex = smallerList(hash1.hashCode(k), hash2.hashCode(k));
    // if list is empty make it the first node
    if (arr[smallestListIndex].key == null)
    {
      put = arr[smallestListIndex].value;
      arr[smallestListIndex] = temp;
      theSize++;
    }
    else // there is a collision; append it to that list 
    {
      temp = arr[smallestListIndex];
      //check if it already exists and set put 
      if (temp.key.equals(k))
      {
        put = (ValueType) temp.value; // get value to return ( previous value)
        temp.value = v; // set the new value 
        theSize++;
        return put;
      }
      else
      {
        //traverse to the end of the list and insert there
        while (temp.next != null)
        {
          temp = temp.next;
          //check if it already exists and set put 
          if (temp.key.equals(k))
          {
            put = (ValueType) temp.value; // get value to return ( previous value)
            temp.value = v; // set the new value 
            theSize++;
            return put;
          }
          else
          {
            put = (ValueType) temp.value; //make put null because it is first intance of key
          }
        }

      }

      //insert a new node at the end of that list 
      temp.next = new Node(k, v, null);
      theSize++;// add to the total size 

    }
    return put;
  }

  /**
   * Methos to remove a key from the hash table, a key is given and a reference to its node is removed
   * @param k the key
   * @return true of false wether or nother node has been removed 
   */
  public boolean remove(KeyType k)
  {
    Node temp;

    // look for it using the first hash function
    int index = hash1.hashCode(k);
    // check first and if same remove
    if (arr[index].key.equals(k))
    {
      temp = arr[index].next; // get new list without first node 
      arr[index] = null; // wipe out list in that index
      arr[index] = temp; // put back new list 
      theSize--;
      return true;
    }
    else
    // traverse list find and remove 
    {
      while (arr[index].next != null && !arr[index].key.equals(k))
      {
        temp = arr[index].next;
        if (temp.key.equals(k)) // if it is found
        {
          temp = arr[index].next;
          arr[index] = arr[index].next.next;// remove reference to that node 
          temp.next = null; // remove reference of middle node 
          theSize--;
          return true;
        }

      }
    }

    // if nothing has been returned to this point, try second hash function 
    index = hash2.hashCode(k);
    // check first and if same remove
    if (arr[index].key.equals(k))
    {
      temp = arr[index].next; // get new list without first node 
      arr[index] = null; // wipe out list in that index
      arr[index] = temp; // put back new list 
      theSize--;
      return true;
    }
    else
    // traverse list find and remove 
    {
      while (arr[index].next != null && !arr[index].key.equals(k))
      {
        temp = arr[index].next;
        if (temp.key.equals(k)) // if it is found
        {
          temp = arr[index].next;
          arr[index] = arr[index].next.next;// remove reference to that node 
          temp.next = null; // remove reference of middle node 
          theSize--;
          return true;
        }

      }
    }

    // if it reached this point, the key is not in the hash table, return false
    return false;

  }

  /**
   * A method to return the value of an key
   * @param k key of the data
   * @return the value the the specific key,if not found will return null
   */
  public ValueType get(KeyType k)
  {
    // try finding it using first hash function
    int index = hash1.hashCode(k);

    if (arr[index].key.equals(k)) // see if the first node is it 
    {
      return arr[index].value;
    }
    else // look at the rest of the list 
    {
      while (arr[index].next != null)
      {
        arr[index] = arr[index].next;
        // if found 
        if (arr[index].key.equals(k))
        {
          return arr[index].value; // return the value 
        }
      }
    }

    // if code gets to this point, hash function one did not find node, try hash function 2 
    index = hash2.hashCode(k);
    if (arr[index].key.equals(k)) // see if the first node is it 
    {
      return arr[index].value;
    }
    else // look at the rest of the list 
    {
      while (arr[index].next != null)
      {
        arr[index] = arr[index].next;
        // if found 
        if (arr[index].key.equals(k))
        {
          return arr[index].value; // return the value 
        }
      }
    }

    // if code gets to this point, hasfuciton 1 and 2 did not find a node with that key value
    return null;

  }

  public String toString()
  {

    String toString = "";

    for (int i = 0; i < DEFAULT_ARRAY_SIZE; i++) // for every list 
    {
      Node temp = arr[i];
      toString += i + 1 + "]" + temp.key + " " + temp.value;
      // if there is a list print the rest of the list
      if (temp.next != null)
      {
        toString += " ->";
      }
      else
      {
        toString += "\n";
      }
      while (temp.next != null)
      {
        temp = temp.next;
        toString += " " + temp.key + " " + temp.value;
        if (temp.next != null)
        {
          toString += " -> ";
        }
        else
        {
          toString += "\n\n";
        }
      }

    }
    return toString;

  }

  public Iterator<Map.Entry<KeyType, ValueType>> iterator()
  {
    return new Iterator<Map.Entry<KeyType, ValueType>>()
    {
      Node<KeyType, ValueType> current;
      int listNum; // the number in the array 

      public boolean hasNext()
      {
        return current != null;
      }

      public Map.Entry<KeyType, ValueType> next()
      {
        final Node<KeyType, ValueType> theCurrent = current;

        Map.Entry<KeyType, ValueType> nextItem = new Map.Entry<KeyType, ValueType>()
        {

          public KeyType getKey()
          {
            return theCurrent.key;
          }

          public ValueType getValue()
          {
            return theCurrent.value;
          }

          public ValueType setValue(ValueType value)
          {
            theCurrent.value = value;
            return value;  // work really work 
          }

        };

        current = current.next;
        if (current != null)
        {
          listNum++;
          advanceToNewList();
        }
        return nextItem;
      }

      private void advanceToNewList()
      {
        while (listNum < arr.length && arr[listNum] == null)
        {
          listNum++;

          if (listNum != arr.length) // if there is nothing or its null
          {
            current = arr[listNum];// make current that position in the array 
          }
        }
        {  // instance initializer 
          advanceToNewList();
        }
      }

    };
  }

  /**
   * Node which will be used by each list in the array
   * @param <KeyType> the line key
   * @param <ValueType> line value
   */
  private static class Node<KeyType, ValueType>
  {

    /**
     * Empty Constructor
     */
    public Node()
    {
      key = null;
      value = null;
      next = null;
    }

    /**
     * Constructor
     * @param k key value
     * @param v value
     * @param n next
     */
    Node(KeyType k, ValueType v, Node<KeyType, ValueType> n)
    {
      key = k;
      value = v;
      next = n;
    }

    public String toString()
    {
      return key + "=" + value;
    }

    KeyType key;
    ValueType value;
    Node<KeyType, ValueType> next;

  }

}
