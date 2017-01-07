//
//  main.cpp
//  Time
//
//  Created by James Moore on 10/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include<iostream>
#include<string>
#include<iomanip>
#include"Time.h"

using namespace std;

Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::Time(int hora)
{
    
    hour = hora;
    
}


Time::Time(int hora, int minutos)
{
    
    hour = hora;
    minute = minutos;
    
}


void Time::setHour(int hora)
{
    hour = hora;
}

void Time::setMinute(int minuto)
{
    minute = minuto;
}


int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}


void Time::PrintTime() const
{
    
    cout<<fixed<<setprecision(2);
    
    if( hour > 12)
    {
    
        
        cout<<"The time is "<<hour-12<<":"<<minute<<"pm"<<endl;
    }
    
    else
    {
        
        
        cout<<"The time is "<<hour<<":"<<minute<<"am"<<endl;
    }
    
    
}


int Time::difference (Time & t) const

{
    int object1 = 0 ,object2 = 0 ;
    
    object1 = hour *60 + minute;
    
    object2 = t.getHour() *60 +t.getMinute();
    
    return object2 - object1;
    
}


