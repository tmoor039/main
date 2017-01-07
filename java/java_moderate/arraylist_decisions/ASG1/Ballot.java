/**
 *Created by Tiago Moore on Jan 25, 2014.
 *  Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * 
 */
import java.util.*;

public class Ballot 
{

	// instance variables
	private ArrayList<String> ballot ; 	
/**
 * Constructor: creates a list of strings called ballot
 */
       public Ballot()
       {
         ballot = new ArrayList<String>();
       }
       
       
	/** 
	*  Examine a Ballot and return the voter’s first choice among the names on a list of candidates
	*  @param candidateList a list of candidate names 
	*  @return the name of the first choice candidate on this Ballot from those in candidateList 
	*/ 
	public String firstChoiceFrom (ArrayList<String> candidateList)
	{ 
          String firstName = "";// initialize a name
          
         
         for( int i = 0 ; i < ballot.size(); i ++)// for the size of the ballot
         {
           firstName = ballot.get(i);// get the name
           
           if(candidateList.contains(firstName))// if it exists in candidate
           {
            break;// exit for loop //stop the loop
           }
         }
         
        return firstName; //returns the first name on the ballot, that exist in cadidate list
         
	}
       /**
        * Adds a string to the ballot
        * @param name the name to be added
        */
       public void addNameToBallot(String name)
       {
         ballot.add(name);
       }
       
       /**
        * gets the ballot
        * @return a ballot
        */
       public ArrayList<String> getBallot()
       {
         return ballot;
       }
       
       /**
        * Removes all names on a current ballot and makes it empty
        */
       public void clearBallot()
       {
        ballot.clear();
       }
       
       
}  // end of Ballot class definition


