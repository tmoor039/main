/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *Created by Tiago Moore on Jan 25, 2014.
 *  Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * 
 */
import java.util.*;


public class ImmediateDecision 
{
   //instance variables
  private ArrayList<String> decisionList = new ArrayList<String>();
  private VoterBallots finalBallot = new VoterBallots() ;
  private  ArrayList<String> deleteList = new ArrayList<String>();
  
 
 /**
  * Constructor creates an immediate decision list 
  * @param listOfCandidates the current candidate list
  * @param listOfVotes all the ballots from all the voters
  */
  public ImmediateDecision(ArrayList<String> listOfCandidates, VoterBallots listOfVotes)
  {
     decisionList= listOfCandidates;
     finalBallot = listOfVotes;
  }

  /**
   * makes the final decision on who is the winner of the election
   * @return the name of a winner, or if election is not decisive the appropriate error message. 
   */
  public String finalDecision()
  {

    while (decisionList.size()>1)// while there is more than one person on the list
    {
      
    deleteList= finalBallot.candidatesWithFewest(decisionList);// add candidates that lost to alist
      
    String deletedName ="";
  
    for (int i = 0; i < deleteList.size(); i++ )
    {
      deletedName = deleteList.get(i);
      decisionList.remove(deletedName);// remove the candidate that lost from the current list
    }
    
    }
    
 
    if( decisionList.isEmpty())// if there are no names on the list, then there was a tie for
                                // min and max votes, and the election was not decisive. 
    {
      return "Election is not decisive.";
    }
    
    else
    {

      return decisionList.get(0) + " is the winner.";// return the winner
    }
    
    
    
  }
  
  
  
  
  
  
  
  //selects a winner by repeatedly applying candidatesWithFewest to a list of candidates
  // that is reduced until only the winner reamins
  
  // do it in a method that returns the name of the winning candidate or an appropriate message
  // if the election is not decisive
  
  //constructor that takes two parameters- initial list of candidates , and a voterballots object

}
