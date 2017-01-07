//
//  main.cpp
//  Time
//
//  Created by James Moore on 10/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<iostream>
#include "Time.h"

using namespace std;


int main()
{
    
    Time t1;
    
    Time t2(20);
    
    Time t3(8,30);
    
    t1.getHour();
    
    t1.setHour(21);
    t1.setMinute(22);
    
    if (t1.getHour() > 12) 
    {
        cout<<"The Time for the Time1 object is "<<t1.getHour()-12<<":"<<t1.getMinute()<<"pm"<<endl;
    }
    else {
        cout<<"The Time for the Time1 object is "<<t1.getHour()<<":"<<t1.getMinute()<<"am"<<endl;
    }

    cout<<endl;
    
    
    cout<<"Object Two"<<endl;
    
    t2.setMinute(20);
    t2.PrintTime();
    

    cout<<endl;
    
    cout<<"Object Three"<<endl;
    
    t3.PrintTime();
    
    cout<<endl;
    
    
    
    cout<<"The difference in minutes of time two and time one is "<<t2.difference(t1)<<" minutes."<<endl;
    
    
    
    
    
    
    
    
    
    
    
return 0;
}