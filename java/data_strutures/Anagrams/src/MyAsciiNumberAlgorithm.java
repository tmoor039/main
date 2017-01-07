
/**
 * Created by Tiago Moore on Sep 13, 2014. Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 *
 */
import java.util.ArrayList;
import java.io.*;
import java.util.Scanner;
import java.math.*;


/**
 * This class solves the anagram problem by adding up my personal ascii values that I
 * assigned to the alphabet letters A-Z, and then it compares to see if the words are the same.
 * Note: This algorithm will solve the problem based on the parameters of the assignment, and the 
 * test file which we are using. For a larger text file with more anagrams, the ascii values that I
 * assigned will need to have even more decimals, to decrease the probability of two anagrams having the same
 * ascii value.By adding more decimals to each ascii character, the probability of the floats becoming 
 * the exact same number can be as low as the programmer intends it to be. 
 * It is all done with the time complexity of O(n)
 * @author Tiago
 */
public class MyAsciiNumberAlgorithm
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
   * This algorithm has a worst case run time of O(n) since the .get() method from the arrayList has
   * a constant run time of O(1), therefore the only critical parameter to note for worst case time
   * is the size of the word,which is the size of the list, and ultimatl, n.
   * @param wordOne The first word being compared
   * @param wordTwo The second word being compared
   * @return True if anagram, false otherwise
   */
  private static Boolean runAlgorithm(String s1, String s2)
  {

    float firstWordAsciiTotal = 0;
    float secondWordAsciiTotal = 0;

    // declare a data structure to be used
    ArrayList<Character> firstList = new ArrayList<Character>();
    ArrayList<Character> secondList = new ArrayList<Character>();

    char tempchar = ' ';

    //populate the first list 
    for (int i = 0; i < s1.length(); i++) //runs s1.length or n times
    {
      tempchar = s1.charAt(i);
      firstList.add(tempchar); // O(n) worst case complexivity since array must be resized n times
      tempchar = s2.charAt(i); // O(n)(n)worst case compelxivity since array must be resized n times
      secondList.add(tempchar);
    }

    // add sum of each ascii character value in the first arraylist
    for (int i = 0; i < s1.length(); i++)// loop executs O(n) times
    {
      //Math.round is used to cut off the decimals( not necessary)
      firstWordAsciiTotal += Math.round(myAscIIValue(firstList.get(i))*10000); // constact time O(1)
    }

    for (int i = 0; i < s2.length(); i++)// loop executs O(n) times
    {
      secondWordAsciiTotal += Math.round(myAscIIValue(secondList.get(i))*10000); // constact time O(1)
    }

    // if the sum of both lists ascii values are the same, it is an anagram
    if (firstWordAsciiTotal == secondWordAsciiTotal)
    {
      return true;
    }
    // otherwise return true

    return false;
  }


  /**
   * Writes an output File and prints the run time to the console
   * @param numAnagrams total number of anagrams in the file
   * @param numNonAnagrams total number of non anagrams in the file
   * @param executionTime total execution time it took to run program with this algorithm
   */
  private static void writeOutputFile(int numAnagrams, int numNonAnagrams, double executionTime)
  {
    File outputFile = new File("MyAscIINumberAlgorithmOutput.txt");
    try
    {
      outputFile.createNewFile();
      FileWriter writer = new FileWriter(outputFile);


      writer.write("Algorithm Name: MyAsciiNumber\n"
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
  private static void checkSize(String s1, String s2)
  {
    // if the words are the same length return true
    if (s1.length() == s2.length())
    {
      sameSize = true;
    }
    // otherwise return false
    else
    {
      sameSize = false;

    }
  }

  /**
   * This method will modify the ASCII value of the integers A-Z for precision
   * Lowers the probability of two words having the same total. If I wanted to, i could make
   * this probability as low as one in a duotrigintillion(10^99), which is an unimaginable number,
   * Another way to implement this would be to assign prime numbers to each letter excluding one and
   * multiply every number in the list then compare, there would be no probability of failure with that implementation.
   * @param alphabetLetter
   * @return my ascII value for the specified character
   */
  private static double myAscIIValue(char alphabetLetter)
  {
    //declare and initialize local variables
    double myAsciiValue = 0;

    if (alphabetLetter == 'a')
    {
      myAsciiValue = alphabetLetter + .20343;
    }
    else if (alphabetLetter == 'b')
    {
      myAsciiValue = alphabetLetter + .30231;
    }
    else if (alphabetLetter == 'c')
    {
      myAsciiValue = alphabetLetter + .11340;
    }
    else if (alphabetLetter == 'd')
    {
      myAsciiValue = alphabetLetter + .05278;
    }
    else if (alphabetLetter == 'e')
    {
      myAsciiValue = alphabetLetter + .03086;
    }
    else if (alphabetLetter == 'f')
    {
      myAsciiValue = alphabetLetter + .01306;
    }
    else if (alphabetLetter == 'g')
    {
      myAsciiValue = alphabetLetter + .00143;
    }
    else if (alphabetLetter == 'h')
    {
      myAsciiValue = alphabetLetter + .61231;
    }
    else if (alphabetLetter == 'i')
    {
      myAsciiValue = alphabetLetter + .90342;

    }
    else if (alphabetLetter == 'j')
    {
      myAsciiValue = alphabetLetter + .70343;

    }
    else if (alphabetLetter == 'k')
    {
      myAsciiValue = alphabetLetter + .10348;
    }
    else if (alphabetLetter == 'l')
    {
      myAsciiValue = alphabetLetter + .00347;
    }
    else if (alphabetLetter == 'm')
    {
      myAsciiValue = alphabetLetter + .36356;
    }
    else if (alphabetLetter == 'n')
    {
      myAsciiValue = alphabetLetter + .86079;
    }
    else if (alphabetLetter == 'o')
    {
      myAsciiValue = alphabetLetter + .23403;
    }
    else if (alphabetLetter == 'p')
    {
      myAsciiValue = alphabetLetter + .05678;
    }
    else if (alphabetLetter == 'q')
    {
      myAsciiValue = alphabetLetter + .17897;
    }
    else if (alphabetLetter == 'r')
    {
      myAsciiValue = alphabetLetter + .45456;
    }
    else if (alphabetLetter == 's')
    {
      myAsciiValue = alphabetLetter + .25346;
    }
    else if (alphabetLetter == 't')
    {
      myAsciiValue = alphabetLetter + .40634;
    }
    else if (alphabetLetter == 'u')
    {
      myAsciiValue = alphabetLetter + .53604;
    }
    else if (alphabetLetter == 'v')
    {
      myAsciiValue = alphabetLetter + .34647;
    }
    else if (alphabetLetter == 'w')
    {
      myAsciiValue = alphabetLetter + .45346;
    }
    else if (alphabetLetter == 'x')
    {
      myAsciiValue = alphabetLetter + .94693;
    }
    else if (alphabetLetter == 'y')
    {
      myAsciiValue = alphabetLetter + .82529;
    }
    else if (alphabetLetter == 'z')
    {
      myAsciiValue = alphabetLetter + .12336;
    }
    
    return myAsciiValue;
    
  }


}
