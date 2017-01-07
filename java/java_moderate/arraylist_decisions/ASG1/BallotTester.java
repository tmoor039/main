/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *Created by Tiago Moore on Jan 25, 2014.
 * Copyright (c) 2013 __TiagoMoore__. All rights reserved.
 * Section 4
 *I affirm that this program is entirely my own work and none of it is the work
 *any other person.
 *
 *
 *
 *____________________________________________________________________________
 *
 */


import java.io.*;
import java.util.*;

public class BallotTester 
{
  
  public static void main(String[] args) throws IOException
  {
    //open file for input
    File candidates = new File("candidates.txt");
    // create a ballots file 
    File votersChoice = new File("ballots2.txt");
    //create scanner object to read from file candidates
    Scanner reader = new Scanner(candidates);
    //create an arraylist to store all current candidates
    ArrayList<String> currentCandidateList = new ArrayList<String>() ;
 
    while(reader.hasNextLine())//while there are still lines in the file 
    {
      currentCandidateList.add(reader.nextLine());// read all candidates into a list
    }
      reader.close();
      
  //create a scanner object associated with ballots1.txt
  Scanner infile = new Scanner(votersChoice);
 
  //create a votersBallots object 
  VoterBallots allBallots = new VoterBallots();
   
        // while there are still lines in the file ( or ballots )
        while(infile.hasNextLine())
       {
    // reset the ballot so it can be put into the ballotList again
    Ballot vote = new Ballot();
    
   // for the  amount of candidates, read them into a ballot
   for( int i = 0 ; i < currentCandidateList.size(); i ++)
      {
   //add the names to the  a ballot object
   vote.addNameToBallot(infile.next());
      }
 
    //add the ballot to a list of ballots 
       allBallots.addBallotToList(vote);
         }
        // close 
        infile.close();
        
      // create an decision object and call method will all ballots and candidate list  
    ImmediateDecision decision = new ImmediateDecision(currentCandidateList, allBallots);
        
        
      // print result   
    System.out.println(decision.finalDecision());
        
        
        
        
        
        
        
        
        
        
        
        
        
        
  }
  }


  


