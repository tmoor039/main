/**
 *
 *Created by Tiago Moore on Nov 17, 2014.
 *Reviewed 27 Mar 2018 
 * This file contains the tester function for the other classes. It tests the hashers and sees if the code works without any collisions. 
 * _______________________________
 */

import java.util.*;
import java.io.*;

public class Hasher {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException

   {
     String putOutPut = "";
     
     HashFunction1 hf1 = new HashFunction1();
     HashFunction2 hf2 = new HashFunction2();
     MyHashMap<String,String> myMap = new MyHashMap<String, String>(hf1, hf2);
     
     // create a File object associated with the list of anagrams   
    File anagramTextFile = new File("data_file.txt");

    // create a scanner Object associated with the anagram text file
    Scanner fileScanner = new Scanner(anagramTextFile);

    //read file and check if anagram until there are no more words to be read
    while (fileScanner.hasNextLine())
    {
       putOutPut +=  myMap.put(fileScanner.next(), fileScanner.next())+ " ";
    }
 
       // testing methods
     System.out.print(myMap.toString()+"\n\n"+"Put Output: " + putOutPut+"\n The size of the hash "
     + "table before removal is : "+ myMap.size()+"\n\n ");
     
     
     
     myMap.remove("tiffany");
     
     System.out.println("Now lets remove 'tiffany' for the table.\n"
             + "The new size of the hash table is : "+myMap.size()+"\n\n");
     
        System.out.println("Now lets get the value with the key  'ray' from the table.\n"
             + "The value of the key ray is  : "+myMap.get("ray")+"\n\n");
     
        
   }

}
