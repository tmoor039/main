//
//  main.cpp
//  Aug6 Classwork #2
//
//  Created by James Moore on 9/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include<iostream>

using namespace std;

//function protocol

//return type: void
//parameters : two doubles by reference, one pointer, and one int by value
// this function will fill an array with scores with the pointer, and find the minimum and maximum value entered by the user 

void findValues(const double *p, int amountofscores,  double &min , double & max);

int main()
{
    int scores = 0; 
    
    double min = 0, max = 0;
    
    do {
     
        cout<<"How many test scored do you wish to enter?";
        cin>>scores;
        
        if (scores<0) 
        {
  cout<<"Invalid. Numbers calculated must be more than 0 ";
      
        }
} while (scores <0);
    
    
    double *p = NULL;
    
    p = new double[scores];
    
    //promt for test scores
    
    for (int i = 0 ; i < scores; i ++)
    {
        cout<<"Enter test score number "<<i<<" : ";
        cin>>*(p + i );
        
    
    }
    
    
    cout<<" The test scores are: "<<endl;
    
    for ( int i =0 ; i < scores ; i ++)
    {
        cout<<*(p+i)<<" ";
    
    }
    
    cout<<"Now these are the maximum and minimum scores :"<<endl<<endl;
    
    findValues(p, scores, min, max);
    
    cout<<"The highest score is : "<<max<<endl;
    cout<<"The lowest score is : "<<min<<endl;

    return 0;
    
}

void findValues( const double *pointer, int size, double &min, double &max )
{
    
    min = *pointer;
    max = *pointer;
    
    for (int i =1 ; i < size ; i ++)
    {
        if (min > *(pointer+i)) 
        {
            min = *(pointer+i);
        }
    }
    
    for (int i = 1 ; i < size ; i ++)
    {
        if (max < *(pointer+i) ){
           
            max = *(pointer +i);
        }
    }
    

    
}
