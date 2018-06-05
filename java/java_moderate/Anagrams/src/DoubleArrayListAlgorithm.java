
/**
 * Created by Tiago Moore on Sep 13, 2014. Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *
 */
import java.util.ArrayList;
import java.io.*;
import java.util.Scanner;



public class DoubleArrayListAlgorithm
{

  // declare global variables
  static int anagramCount = 0;
  static int nonAnagramCount = 0;
  static double executionTime = 0.0;
  static Boolean sameSize = false;
  static Boolean anagram = false; 


  public static void main(String[] args) throws IOException
  {

    //declare and initialize variables
    String firstWord = "";
    String secondWord = "";
  
    long start = System.currentTimeMillis();

    // create a File object associated with the list of anagrams   
    File anagramTextFile = new File("anagrams-large.txt");

      // create a scanner Object associated with the anagram text file
    Scanner fileScanner = new Scanner(anagramTextFile);

    //read file and check if anagram until there are no more words to be read
    while (fileScanner.hasNextLine())
    {
      // read in first word in line
      firstWord = fileScanner.next();
      //read in second word in line
      secondWord = fileScanner.next();
      // check if the words are the same length, if not it cant be an anagram
      checkSize(firstWord, secondWord);

      // convert both words to lower case 
      firstWord = firstWord.toLowerCase();
      secondWord = secondWord.toLowerCase();

      if (sameSize) // if anagrams are found 
      {
        if (runAlgorithm(firstWord, secondWord)) // and they are an anagram
        {
          anagramCount++; // add to the anagram count
        }
        else
        {
          nonAnagramCount++; //add to the non anagram count 
        }
      }
      else if (!sameSize)
      {
        nonAnagramCount++;
      }
    }
    // Write the formateed output to console/textfile
    long end = System.currentTimeMillis();// record time for end of task
    executionTime = end - start;
    writeOutputFile(anagramCount, nonAnagramCount, executionTime);
  }


  /**
   * An algorithm for determining if two words are anagrams, the for loop has a complexivity of O(n)
   * times since the array list add operation has O(n) worst case run time, therefore the loop is
   * running n times for the for loop , n times for the first list, and n times for the second list
   * therefore n*n*n = n^2 worst case total time
   * @param wordOne The first word being compared
   * @param wordTwo The second word being compared
   * @return True if anagram, false otherwise
   */
  private static Boolean runAlgorithm(String s1, String s2)
  {
    // declare a data structure to be used
    ArrayList<Character> firstList = new ArrayList<Character>();
    ArrayList<Character> secondList = new ArrayList<Character>();

    char tempchar = ' ';

    //populate the first list 
    for (int i = 0; i < s1.length(); i++) //runs s1.length or n times
    {
      tempchar = s1.charAt(i); // constant time O(1)
      firstList.add(tempchar); // constant time O(1)
      tempchar = s2.charAt(i); // constant time O(1)
      secondList.add(tempchar);// constant time O(1)
    }

    for (int i = 0; i < s1.length(); i++)
    {
      // this will run O(2) because contains runs O(n) times and loop runs O(n) worst case
      if (!firstList.contains(secondList.get(i)) || !secondList.contains(firstList.get(i)))
      {
        return false; 
      }
    }
      return true; 
  
  }


  /**
   * Writes an output File and prints the run time to the console
   * @param numAnagrams total number of anagrams in the file
   * @param numNonAnagrams total number of non anagrams in the file
   * @param executionTime total execution time it took to run program with this algorithm
   */
  private static void writeOutputFile(int numAnagrams, int numNonAnagrams, double executionTime)
  {
    File outputFile = new File("DoubleArrayListAlgorithmOutput.txt");
    try
    {
      outputFile.createNewFile();
      FileWriter writer = new FileWriter(outputFile);


      writer.write("Algorithm Name: DoubleLinkedList\n"
              + "Number of anagrams: " + numAnagrams + "\nNumber of non-anagrams: " + numNonAnagrams + "\n"
              + "Execution Time: " + executionTime + "ms\n");
      writer.flush();
      writer.close();
    }
    catch (IOException E)
    {
      System.err.println(E.getMessage());
    }

    System.out.println("Execution Time: " + executionTime + "ms\n");

  }


  /**
   * Helper method to see if words are the same size
   * @param s1 the first word in the text file line
   * @param s2 the second word in the text file line
   * @return True if words are same size, false otherwise
   */
  private static Boolean checkSize(String s1, String s2)
  {
    // if the words are the same length return true
    if (s1.length() == s2.length())
    {
      sameSize = true;
    }
    else
    {
      sameSize = false;
    }

    return sameSize;
  }


}
