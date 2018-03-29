/**
 *Created by Tiago Moore on Nov 17, 2014.
 * Reviewed 27 March 2018
 */
public class HashFunction1 implements HashFunction <String>
{
  private int hashValue;
  /**
   * This is a standard mod hash function. it will simply add up the ascii value and mod it by 11
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
  
  // The problem with this hash function is that it will lead to a significant amount of colisions. 
  // The ASCII value of 10 + 8 might be = to 18 .. and those are two diferent letters; however, if we get a word with the 
  //ascii value of 9 +9 we will still get 18. hence we have two different words with the same hash value AKA a collision will happen. 

}
