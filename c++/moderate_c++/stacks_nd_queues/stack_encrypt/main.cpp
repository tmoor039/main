//  main.cpp
//  Project1
//
//  Created by James Moore on 10/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include"CharStack.h"
#include<cstdlib>
#include<cassert>
#include<string>

using namespace std;

void PrintIntro();


int main()
{
    //initialize the strings
    string CCCC,XXXX,sentence;
    
    // char to hold popped character
    char remainingchars;
    
    
    //print the rules
    PrintIntro();
    
    
    //do while loop for promt
    do
    {
        
        //promt for firt four letter word
        cout<<"Enter the  first 4 letter word 'CCCC': ";
        getline(cin,CCCC);
        
        //input validation to make sure that word enter is for letters
        
        if ( CCCC.length() != 4)
        {
            cout<<"Invalid word. First word must be no less or greater than 4 letters."<<endl;
            
        }
    }
    while(CCCC.length() != 4);
    
    
    //do while loop for second four  letter word
    do
    {
        //promt for second four letter word
        cout<<"Enter the second 4 letter word. 'XXXX'";
        getline(cin,XXXX);
        
        
        //input validation to make sure that word enter is for letters
        
        if ( XXXX.length() != 4)
        {
            cout<<"Invalid word. First word must be no less or greater than 4 letters."<<endl;
            
        }
    }
    while(XXXX.length() != 4);
    
    
    
    //promt for message to encrypt 
    cout<<"Enter the message that you would like to encrypt: "; 
    getline(cin,sentence);
    
    
    //set size for the length of the encrypted message
    size_t sentencelenght = sentence.length();
    
    
    
    //create a stack for the letters to be popped into. 
    CharStack TheStack(sentencelenght);
    
    //initial loop to  compare each word in the sentence to CCCC
    for (int  i = 0; i < sentencelenght; i ++)
    {
        
        //set flags so loop can end
        bool match = false;
        bool match2 = false;
        char temp;
        
        //loop with different variable to compare two words
        for (int j = 0; j < 4; j++) 
        {
           //if staments, if true stop loop 
            if(sentence.at(i) == CCCC.at(j))
            {
                   match = true;
                   break;
            }
        
        }
        // when match is found 
        if (match) 
        {
            //display it
            cout<<sentence.at(i);
            
            //while loop if the to run while the stack isint empty and letters match
            while (!TheStack.isEmpty()&& !match2) 
            {
                //pop character from the stack
                TheStack.pop(temp);
                
                //compare popped character in each letter of XXXX
                for (int a = 0; a < 4; a++)
                {
                    //if popped character matches
                    if (temp == XXXX.at(a))
                    {
                        match2 = true;
                        
                        TheStack.push(temp);
                        break;
                        
                    }
                    
                                       
                }
                // no match the display character
                if (!match2) 
                {
                    cout<<temp;
                }

                
                
            }     
            
          
            
        } 
        // if no match is found  between CCCC and sentence push
        else 
        {
            TheStack.push(sentence.at(i));
        }
        
  
    }
    
    
    
    // pop and print remaining contents of the stack after no matches
    while (!TheStack.isEmpty())
    {
        TheStack.pop(remainingchars);
        cout<<remainingchars;
    }
    
    
    return 0;
    
} 


void PrintIntro()
{
    
    
    cout<<"WELCOME TO MY ENCRYPTION PROJECT #1"<<endl;
    
    cout<<"Here all the rules\n\n"<<endl;
    
    cout<<"*****************************************************************\n\n\n"<<endl;
    cout<<"Step 1) You will  first enter  four letter word followed by a second four letter word.\n"<<endl;
    
    cout<<"Step 2) You will  enter the sentence that you wish the program to encrypt.\n"<<endl;
    
    cout<<"Step 3) The program will scan the message until it finds a letter that is in the first word CCCC, or until the end of the message.\n"<<endl;
    
    cout<<"Step 4) When the letter in the word CCCC matches a word in the sentence to be encrypted, it will be popped out of the stack and printed. "<<endl<<endl;
    
    cout<<"Step 5) The letters will continiue to be  popped  and displayed from the stack until it is empty or it is found in the XXXX stack, which is the second letter word. "<<endl<<endl;
    
    
    cout<<"Step 6) The program will pop the rest of the stack  and display until the stack is empty.\n\n\n\n\n\n"<<endl;
    
    
    cout<<"**************LETS BEGIN******************"<<endl<<endl;
}
