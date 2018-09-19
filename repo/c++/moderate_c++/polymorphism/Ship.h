//
//  Ship.h
//  Lab4 Ships
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Lab4_Ships__Ship__
#define __Lab4_Ships__Ship__

#include <iostream>
#include<string>

using namespace std;

class Ship
{
protected:
    string name , year ;
    
public:
    
    Ship();
    Ship(string,string);
    virtual ~Ship(); // virtual desctuctor?
    
    //mutators
    
    void setName(string );
    void setYear(string);
    
    //accessors
    
    string getName();
    string getYear();
    
    virtual void printInfo()  ;
    
    
    
};




#endif /* defined(__Lab4_Ships__Ship__) */
