//
//  Header.h
//  Time
//
//  Created by James Moore on 10/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Time_Header_h
#define Time_Header_h

class Time
{
    
private:
    
    int hour;
    int minute;
    
public:
    
    
    //constructors
    
    Time();
    
    Time(int);
    Time(int,int);
    
    
    void setHour(int);
    void setMinute(int);
    
    int getHour() const;
    
    int getMinute() const;
    
    
    void PrintTime() const;
    
    int difference (Time & t) const;
    
};

#endif
