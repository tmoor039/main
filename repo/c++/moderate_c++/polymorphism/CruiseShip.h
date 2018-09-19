//
//  CruiseShip.h
//  Lab4 Ships
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Lab4_Ships__CruiseShip__
#define __Lab4_Ships__CruiseShip__

#include <iostream>
#include "Ship.h"

class CruiseShip : public Ship
{
private:
    int maxPassengers;
    
public:
    
    CruiseShip(int,string,string);
    ~CruiseShip();
    
    //mutators
    
    void setMax(int);
    
    
    //accessors
    
    int getMax();
    
    virtual void printInfo();
    
};


#endif /* defined(__Lab4_Ships__CruiseShip__) */
