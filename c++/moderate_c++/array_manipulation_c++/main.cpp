//
//  main.cpp
//  Lab2
//
//  Created by T Moore on 9/30/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int test;
    cout<<"Enter number ";
    cin>>test;
    
    
 NumberArray array(test);
    
    for ( int i = 0 ; i < test ; i ++)
    {
    array.fillScores();
       if (i !=test-1) 
       {
            cout<<"There are still elements to be populated. Choose an empty spot to populate."<<endl;
       }
    }
    int retreivednumber = 0 ;
    cout<<"What position of the array would you retrieve a number from  ? ";
    cin>>retreivednumber;
    
    float numbergot = 0 ;
    numbergot = array.getretreiveNumber(retreivednumber);
   
    cout<<"The number from position # "<<retreivednumber<<" is "<<numbergot<<endl;
 
    cout<<"The minimum value is "<<array.getminvalue()<<endl;
    
    cout<<"The maximum value is "<<array.getmaxvalue()<<endl;
    
    cout<<"the average is "<<array.getaverage()<<endl;

    return 0;
    
  
}
