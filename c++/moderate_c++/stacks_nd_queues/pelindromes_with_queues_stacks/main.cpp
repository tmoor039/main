//
//  main.cpp
//  Queue+Stack
//
//  Created by James Moore on 10/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<string>
#include"TestStack.h"
#include"CharQueue.h"

using namespace std;

int main()
{

    CharStack word1(15);
    CharQueue word2(15);
    
    string theword;
    char tmp1, tmp2;
   
    bool pelindrome = true;
    
    do
    {
        

    
    cout<<"Enter a word to test is it is a palindrome or not : ";
        getline(cin,theword);
    
    
    size_t length = theword.length();
    
    
    //pop  and push all the words in to  the stack and into the queue
    for (int i = 0 ; i < length ; i ++)
    {
      
            word1.push(theword.at(i));
            word2.enqueue(theword.at(i));
    
      
    }
    
       int  count = 0 ;
   
        for (int i = 0 ; i < length; i ++)
    {
     
        if (theword.at(i) != ' '  )
        {
        word1.pop(tmp1);
        }
        
        if (theword.at(i) != ' '  )
        {
             word2.dequeue(tmp2);
        }       
        
      
        
        if (tmp1 != tmp2)
        {
            cout<<"Negative Match."<<endl;
            pelindrome = false;
            
            
        }
        
        else 
        {
            
            cout<<"Match."<<endl;
        
            count ++;
        }
             }  
        
        if (count == length) 
        {
            cout<<"The word is a pelindrome."<<endl;
        }
        
        else {
            cout<<"The word is not a pelindrome."<<endl;
        }
        
        
    }while(pelindrome!=true); 
    
    
    
    
    
    
    return 0;
}