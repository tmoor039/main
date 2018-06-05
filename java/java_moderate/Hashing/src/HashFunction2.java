/**
 *Created by Tiago Moore on Nov 17, 2014.
 *Reviewed 27 March 2018 
 */

import java.lang.Math;
public class HashFunction2 implements HashFunction<String>
{
  private int hashValue;
/**
 *This hash function squares each character in the string and adds it to a sum then mods by 11
 * @param x the string to be calculated 
 * @return the hash value of the string 
 */
  public int hashCode(String x) 
  {
    int multipleSum = 0;
    
    for(int i = 0 ; i < x.length(); i++)
    {
      multipleSum += Math.pow(x.charAt(i), 2); // what is the Big O of this opeartion? What is the runtime of Math.pow? 
    }
      hashValue= multipleSum%11;
    return hashValue;
    
    // Difference from hash function 1 is that the probabity of a collision has decreased by a factor. since the number is being squared 
    // we can no longer have 10 + 8 = 18 . We would then hav 100 + 64 = 164.. then result would be now different then 81+81... 162. The 
    // possibility of a collision still exists.. its just lower due to the bigger range of numbers. 
  }

}
