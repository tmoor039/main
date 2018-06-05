package poly;
/**
 *Created by Tiago Moore on Apr 2, 2014.
 *  Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * 
 */


/**
 * Creates a term to be used with the polynomial class
 * @author tmoore
 */
public class Term 
{
  private int coefficient; // the coefficient of the term
  private int exponent;// the exponent of the term
  
  /**
   * Constructor: creates a term with a given coefficient and exponent
   * @param c the coefficient of term to be created
   * @param e the exponent of the term to be created
   */
  public Term(int c, int e)
  {
    coefficient = c;
    exponent = e;
  }
  
  /**
   * Gets the coefficient of the current term
   * @return  coefficient 
   */
  public int  getCoefficient()
  {
   return coefficient;
  }
  /**
   * Gets the exponent of the current term
   * @return exponent 
   */
  public int getExponent()
  {
    return exponent;
  }
}
