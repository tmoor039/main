
package poly;

/**
 * Created by Tiago Moore on Apr 3, 2014. 
 * Updated 6 June 2018
  *Linked list class polynomia 
 */



/**
 * Implements a polynomial to be used with the Term class
 * @author tmoore
 */
public class Polynomial
{ 

  private Node head;       // the first node on the list 

/**
 * Constructor
 * creates an empty polynomial
 */
  public Polynomial()
  {
    head = null;
  }


  /**
   * Creates a new polynomial from an existing one
   * @param p the existing polynomial
   */
  public Polynomial(Polynomial p)
  {    
    this.head = null;
    
    Node copy = p.head; // sets the temporary node to the one passed in the constructor 
    
     while(copy!= null)// copy the entire linked list into the temporary one 
     {
       Term temp = copy.Data;
       this.addTerm(temp.getCoefficient(), temp.getExponent());
       copy = copy.next;
     }
   
  }


  /**
   * Creates a term and places it in its proper position in the linked list
   * @param coefficient
   * @param exponent
   */
  public void addTerm(int coefficient, int exponent)
  {
    //create a term with a new node
    Node toAdd = new Node(new Term(coefficient, exponent));

    // special case for empty list 
    if (head == null) // list is empty
    {
      head = toAdd;
    }
    else if (head != null)
    {

      Node lastnode = lastNode(); // get the last node

      int greatestExponent = lastnode.Data.getExponent(); // get the value of the highest exponent 

      // if the coefficient is greater than or equal to the greatest
      if (exponent >= greatestExponent)
      {
        lastnode.next = toAdd; // add node to end of list  
      }
      //if exponent is smaller than head , insert before head  
      else if (exponent < head.Data.getExponent())
      {
        // insert the node before the head 
        toAdd.next = head;
        head = toAdd;// update the head
      }
      else
      {
        Node leader = head; //pointer to the next term
        Node trailer = head;// pointer to the previous term

        while (leader != null)// while its not the last term
        {
          // if the exponent is higher than the one to be adde
          if (leader.Data.getExponent() > exponent)
          {
           // instert the node after the trailer 
            trailer.next = toAdd;
            toAdd.next = leader;
            break;
          }
          else
          {
            // advance the pointers
            trailer = leader;
            leader = leader.next;
          }// once it has reached the highest exponent, trailers will stop updating 
        }
      }
    }
  }


  /**
   * Adds this to the current polynomial
   * @returns the final polynomial after addition
   */
  public Polynomial polyAdd(Polynomial p)
  {
    int currentExpo1 = 0;// the current expoent for this polynomial
    int currentCoe1 = 0;// the current coefficient for this polynomial
    int currentExpo2 = 0; // current exp for p
    int currentCoe2 = 0;// current coe for p
    int finalCoe = 0;// the one to be added 
    Polynomial p1 = new Polynomial();
    Polynomial p2 = new Polynomial();
    Polynomial p3 = new Polynomial();
    // add like terms of both polys
    p1 = combineTerms(this); // combine terms of 1 poly
    p2 = combineTerms(p);   // combine terms of second poly

    Node p1Pointer = p1.head;
    Node p2Pointer = p2.head;

    // check if either polynomial is empty(or null)
    if (p1Pointer == null)
    {
      return p2;
    }
    else if (p2Pointer == null)
    {
      return p1;
    }
    else // if there are polynomials to add
    {
      // traverse lists  and get the  exponent
      while (p1Pointer != null && p2Pointer != null)
      {
        currentExpo1 = p1Pointer.Data.getExponent();
        currentExpo2 = p2Pointer.Data.getExponent();

        // if the first exponent of list 1 is the same as list two
        if (currentExpo1 == currentExpo2)
        {
          // get the coefficient of p1 and of p2
          currentCoe1 = p1Pointer.Data.getCoefficient();
          currentCoe2 = p2Pointer.Data.getCoefficient();
          // add p1 and p2 coefficients
          finalCoe = currentCoe1 + currentCoe2;
          // add that  sum of coeeficients to p3 with the current exponent
          p3.addTerm(finalCoe, currentExpo1);
          p1Pointer = p1Pointer.next;
          p2Pointer = p2Pointer.next;
          // check if that was the last term in either polynomial 
          if (p1Pointer == null || p2Pointer == null)
          {
            // if its the end of term 1, \
            if (p1Pointer == null)
            {
              // add the remaning terms of p2 to p3
              while (p2Pointer != null)
              {
                currentCoe2 = p2Pointer.Data.getCoefficient();
                currentExpo2 = p2Pointer.Data.getExponent();
                p3.addTerm(currentCoe2, currentExpo1);
                p2Pointer = p2Pointer.next;
              }
            }
            // if its the end of term 2
            else if (p2Pointer == null)
            {
              while (p1Pointer != null)
              {// add the remaining terms of p1 into the final polynomial
                currentCoe1 = p1Pointer.Data.getCoefficient();
                currentExpo1 = p1Pointer.Data.getExponent();
                p3.addTerm(currentCoe2, currentExpo1);
                p1Pointer = p1Pointer.next;
              }
            }
          }
        }
        // else if the exp of p1 is not the same as exp of p2
        else if (currentExpo1 != currentExpo2)
        {
          // if the exp of p1 is > than exp of p2
          if (currentExpo1 > currentExpo2)
          {
            // add the term  of p2 to p3
            currentCoe2 = p2Pointer.Data.getCoefficient();
            p3.addTerm(currentCoe2, currentExpo2);
            p2Pointer = p2Pointer.next;
            if (p2Pointer == null)
            {
              while (p1Pointer != null)
              {// add the remaining terms of p2 into a final polynomial
                currentCoe1 = p1Pointer.Data.getCoefficient();
                currentExpo1 = p1Pointer.Data.getExponent();
                p3.addTerm(currentCoe1, currentExpo1);
                p1Pointer = p1Pointer.next;
              }
            }
          }
          // else if the exp of p1 < than exp of 2
          else if (currentExpo1 < currentExpo2)
          {
            //add the term of p1 to p3
            currentCoe1 = p1Pointer.Data.getCoefficient();
            p3.addTerm(currentCoe1, currentExpo1);
            p1Pointer = p1Pointer.next;
            // add th rest of p2 to p3 if its the last term 
            if (p1Pointer == null)
            {
              // add the remaning terms of p2 to p3
              while (p2Pointer != null)
              {
                currentCoe2 = p2Pointer.Data.getCoefficient();
                currentExpo2 = p2Pointer.Data.getExponent();
                p3.addTerm(currentCoe2, currentExpo2);
                p2Pointer = p2Pointer.next;
              }
            }
          }
        }
      }
    }
    return p3;
  }

  /**
   * Multiplies this polynomial with the one in parameter
   * @param p polynomial to be multiplied
   * @return  the final product of the two
   */
  public Polynomial polyMultiply(Polynomial p)
  {
    // create a p1 set it for this
    Node p1 = this.head;
    // create a p2 set it for p
    Node p2 = p.head;
    // create a p3 to add all terms to
    Polynomial p3 = new Polynomial();
    // create a final polynomial 
    Polynomial finalP = new Polynomial();

    // declare variables needed for keeping track of arthmmatic
    int coe1 = 0;// for coefficient 1
    int exp1 = 0; // for exponent 1
    int coe2 = 0;// for coefficient 2
    int exp2 = 0; // for exponent 2 
    int totalCoe = 0;// for coefficient 2
    int totalExp = 0; // for exponent 2 


    // check if there is a polynomial to multiply to
    // if not, return the existing one 
    if (p1 == null)
    {
      return null;
    }
    else if (p2 == null)
    {
      return null;
    }
    else
    {
      // traverse list 1
      while (p1 != null)
      {
        // get the coefficient and exponents
        coe1 = p1.Data.getCoefficient();
        exp1 = p1.Data.getExponent();
        //reset the pointer to P2
        p2 = p.head;

        while (p2 != null)
        {
          coe2 = p2.Data.getCoefficient();
          exp2 = p2.Data.getExponent();
          // calculate the polynomial
          totalCoe = coe1 * coe2;
          totalExp = exp1 + exp2;
          // add a term to a temporary list
          p3.addTerm(totalCoe, totalExp);
          // move to the next term on the list 
          p2 = p2.next;

        }
        // move to the next term on the first polynomial;
        p1 = p1.next;
      }
    }
    // combine like terms of p3 and return the final result 
    finalP = combineTerms(p3);

    return finalP;
  }


  /**
   * Overide the toString method to return a polynomial
   * @return
   */
  public String toString()
  {
    String theString = "";

    Node x = head; // create a temporary node to traverse the list 
    //special case
    if (head == null)
    {
      theString = "null";
    }
    else
    {
      while (x != null)// while its not the last node 
      {
        if (x.Data.getExponent() == 0)
        {
          theString += (x.Data).getCoefficient();
          if (x.next != null)
          {
            theString += " + "; // only print the + when its not the last term 
          }
          x = x.next; // 
        }
        else if (x.Data.getExponent() == 1)
        {
          theString += (x.Data).getCoefficient() + "x";
          if (x.next != null)
          {
            theString += " + "; // only print the + when its not the last term 
          }

          x = x.next; // 
        }
        else
        {
          theString += (x.Data).getCoefficient() + "x^" + (x.Data).getExponent();
          if (x.next != null)
          {
            theString += " + "; // only print the + when its not the last term 
          }

          x = x.next; //     
        }
      }
    }
    return theString;
  }

  /**
   * utility method  to get the last node
   * @returns temp the pointer to the last node
   */
  private Node lastNode()
  {
    if (head == null)       // if list empty...
    {
      return null;        // ...return null pointer
    }
    else                    // else, get pointer to last node
    {
      Node temp = head;           // ...start at head of list
      while (temp.next != null)   // ...while not at last node...
      {
        temp = temp.next;	// ......move to next node
      }
      return temp;		// ...return pointer to last node
    }

  }

/**
 * Method to combine all like terms in a given polynomial
 * @param p the given polynomial to combine terms
 * @return a final polynomial with all like terms combined
 */
  private Polynomial combineTerms(Polynomial p)
  {
    Polynomial finalP = new Polynomial();// the final term 
    
    int currentexp = 0, coefficientToAdd = 0;
    Node temp = p.head; //pointer to travese the polynomial

    //  if no polynomial , return nothing
    if (temp == null)
    {
      return p;
    }

    currentexp = temp.Data.getExponent();
    while (temp != null)// while the pointer does not point to null 
    {
      // if the current exponent is the same as the next one
      if (currentexp == temp.Data.getExponent())
      {
        // add to a counter
        coefficientToAdd += temp.Data.getCoefficient();
        temp = temp.next;// point to next node
        if (temp == null)
        {// if its the last term on the polynomial,add it the term
          finalP.addTerm(coefficientToAdd, currentexp);
        }
      }
      else
      {
        // if there are no like terms
        finalP.addTerm(coefficientToAdd, currentexp);// add term to final
        currentexp = temp.Data.getExponent();
        coefficientToAdd = 0;// reset the coefficient
      }
    }
    return finalP;
  }
 class Node<E extends Term>
  {

    E Data;     //contains object specified by a type paramenter 
    Node next;   // stores reference to a node (for traversing)

 
    /**
     * creates a node
     * @param term The term to be added 
     */
    Node(E term)
    {
      Data = term;
      next = null;
    }


  }

}
