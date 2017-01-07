//
//  File.cpp
//  Lab2
//
//  Created by James Moore on 9/30/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<cassert>
#include "Header.h"
#include<cstdlib>

using namespace std;


//deconstructor 

NumberArray::~NumberArray()
{
    if(numbers != NULL)
    {
        if (size==1)
        {
            delete numbers;
            cout<<"memory realeased"<<endl;
        }
        else if( size > 1)
        {
            delete []numbers;
            cout<<"memory released"<<endl;
        }
    
    }
}

// constructor

NumberArray::NumberArray(int size)
{
    assert( size > 0 );
    
    numbers = new float[size];
 
    assert(numbers != NULL);
    

    this -> size = size;
    
}


 void NumberArray::fillScores()
{
    int x = 0;
    
    cout<<"There are "<<size<<" slots in the array"<<endl;
    cout<<"What position of the array would you like to enter the number in ? ";
    cin>>x;
    
   
    cout<<"Enter the number you would like to place in position # "<<x<<"."<<endl;
    cin>>numbers[x-1];
    
        
    for ( int i = 0; i < size ; i ++)
    {
        cout<<*(numbers+i) << "\t";
    }
    cout<<endl<<endl<<endl;
    
   
    
}

float NumberArray::getretreiveNumber(int location)
{
 
    
    return numbers[location-1];

}


float NumberArray::getminvalue()
{
    
    int lowest = numbers[0];
    
    for (int i =1 ; i < size ; i ++)
    {
        if (lowest > *(numbers+i)) 
        {
           lowest = *(numbers+i);
        }
    }
    return lowest;
    
}


float NumberArray::getmaxvalue()
{
    
    int highest = numbers[0];
    
    for (int i =1 ; i < size ; i ++)
    {
        if (highest < *(numbers+i)) 
        {
            highest = *(numbers+i);
        }
    }
    return highest;

}

float NumberArray::getaverage()
{
    int total = 0 ;
    
    for (int i = 0; i < size ; i ++ )
        
    {
        total += *(numbers+i);
        
        average = total/(i+1);
    }
    
    return average;
    
    cout<<"The Average for the numbers entered by all the students is : "<<average<<endl<<endl;
    

}


