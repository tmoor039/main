//
//  CargoShip.h
//  Lab4 Ships
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Lab4_Ships__CargoShip__
#define __Lab4_Ships__CargoShip__

#include <iostream>
#include "Ship.h"

class CargoShip :public Ship
{
    private:
    int weight;
    
public:
    
    CargoShip(int,string,string);
    ~CargoShip();
    
    //mutators
    
    void setWeight(int);

    
    //accessors
    
    int getWeight();
  
    virtual void printInfo();
    
};





#endif /* defined(__Lab4_Ships__CargoShip__) */
