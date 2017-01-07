/**
 *Created by Tiago Moore on Nov 17, 2014.
 *  Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * 
 */
public class HashFunction1 implements HashFunction <String>
{
  private int hashValue;
  /**
   * THis is a standard mod hash function. it will simply att up the ascii value and mod it by 11
   * @param x
   * @return 
   */
  public int hashCode(String x)
  {
   int hashval = 0;
   
   for(int i = 0; i < x.length(); i++)
   {
     hashval += x.charAt(i);
   }
   hashValue = hashval %11;
    return  hashValue;
  }


  @Override
  public String toString()
  {
    return ""+ hashValue;
  }
  
  

}
