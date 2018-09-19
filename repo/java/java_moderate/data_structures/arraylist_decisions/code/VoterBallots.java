/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import  java.util.*;
public class VoterBallots 
{
    // instance variables
	private ArrayList<Ballot> ballotList ; 	// each entry represents one voter’s ballot 

/**
 * @constructor creates a new list of ballots
 */
        public VoterBallots()
       { 
         ballotList = new ArrayList<Ballot>();
       }
        /**
         * mutator method that adds a new ballot to the list
         * @param votes the ballot being added to the list of ballots
         */
        public void addBallotToList(Ballot votes)
       {
         ballotList.add(votes);
       }
        
        
	/** 
	 * Returns the number of times a given candidate appears first, among those elements that are 
	* on candidateList, among all elements of ballotList (i.e., among all ballots)	 
	* @param candidate the name of a candidate 
	* @param candidateList a list of candidate names 
	* Precondition: candidate appears in candidateList 
	* @return the number of times that candidate is first among those in candidateList for all
	* elements of ballotList
	*/ 
	private int numFirstVotes(String candidate,  ArrayList<String> candidateList)
	{ 
     
         int count = 0 ;// initailize a counter

        for( int i = 0; i <ballotList.size(); i ++)// for the amout of ballots
        {
          // if the first choice from ballot is equal to candidate
          if(ballotList.get(i).firstChoiceFrom(candidateList).equals(candidate))
          {
            //increment counter
            count++;
          }
          
        }

         return count;
	}

	/** 
	* Returns a list of one or more candidates tied with the fewest first choice votes
	* @param candidateList a list of candidate names 
	* Precondition: each String in candidateList appears exactly once in each Ballot in ballotList 
	* @return a list of those candidates tied with the fewest first choice votes 
	*/ 
	public  ArrayList<String> candidatesWithFewest ( ArrayList<String> candidateList )
	{ 
         ArrayList<String> loserList = new ArrayList<String>();// create a list to hold names with
                                                               // fewest votes
         int minNumOfVotes = numFirstVotes(candidateList.get(0), candidateList);
         int currentVotes = 0;//keep track of the current number
       
         for( int i = 0; i < candidateList.size(); i++)// for the amount of candidates
         {
           currentVotes = numFirstVotes(candidateList.get(i), candidateList);
           if(currentVotes < minNumOfVotes)// get the minimum amount of votes
           {
             minNumOfVotes = currentVotes;
            
           }
    
         }
         
        for( int i = 0; i < candidateList.size(); i++)
         {
           currentVotes = numFirstVotes(candidateList.get(i), candidateList);
           if(currentVotes == minNumOfVotes)// get the name with the least number of votes
           {
             loserList.add(candidateList.get(i));// add to a list to be removed from the CL
            
           }
    
         }
         
 
		return loserList;
	}
       
       
       
       
       
       
       
       
}
