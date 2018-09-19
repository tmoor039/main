//
//  main.cpp
//  Reverse Program
//
//  Created by James Moore on 9/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

//function protocall 

//return type: pointer 
//parameters: one array and one int , the size of the array 
// puporse: this function  will make a copy of the array and change it to reverse order

int *reversefunction( const int *pointer, int size);

    
int main()
{
    
    int scores = 0;

    //promt for  number of test scores
    do {
        cout<<"How many test score do you have?";
        cin>>scores;
        if (scores<2) {
            cout<<"Invalid, you must enter a number greater than 2,so that we can test the program."<<endl;
        }
    } while (scores<2);
    
      int *p = NULL;
      p = new int[scores];

    // do while loop to make sure the values in p are not null
    do 
    {
        
        if (p == NULL) 
        {
            cout<<"WARNING. p = NULL."<<endl;
            p = new int[scores];
            
            
        }
    } while (p == NULL);
    
    //populate the new array
    
    for (int i = 0; i< scores;i ++) {
        cout<<"Enter you test score for test #"<<i<<" : ";
        cin>>*(p+i);
        
    }
    //display the current test scores not formatted.
    
    for (int i = 0 ; i <scores; i ++) {
        cout<<*(p+i)<<" ";
        
    }
    cout<<"\n\n\n";
    
    int * F = reversefunction(p, scores);
    
    //display the scores again to make sure they are reversed.
    
    
    cout<<"Here are the test scores that you entered in reverse order:\n\n";
    for (int i = 0 ; i <scores; i ++) {
        cout<<*(F+i)<<" ";
        
    }
    
    
    return 0;
    
}


int *reversefunction (const int *p, int size)
{
    int * K = NULL;

    K = new int[size];
    do 
    {
   
    if (K == NULL) 
        {
        cout<<"WARNING. K = NULL."<<endl;
        }
     } while (K == NULL);
    
    for (int i = 0; i < size; i ++)
    {
        *(K+i) = *(p+(size-1)-i);
        
    }
    return K;
    
    
}

