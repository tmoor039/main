/**
 *Created by Tiago Moore on Nov 17, 2014.
 *  Copyright (c) 2014 __TiagoMoore__. All rights reserved.
 * 
 */

import java.lang.Math;
public class HashFunction2 implements HashFunction<String>
{
  private int hashValue;
/**
 *This hash functions squares each character in the string and adds it to a sum then mods by 11
 * @param x the string to be calculated 
 * @return the hash value of the string 
 */
  public int hashCode(String x) 
  {
    int multipleSum = 0;
    
    for(int i = 0 ; i < x.length(); i++)
    {
      multipleSum += Math.pow(x.charAt(i), 2);
    }
      hashValue= multipleSum%11;
    return hashValue;
    
    
  }

}
