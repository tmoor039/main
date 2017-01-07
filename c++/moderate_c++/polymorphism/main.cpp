//
//  main.cpp
//  Lab4 Ships
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include <iostream>
#include "Ship.h"
#include "CargoShip.h"
#include "CruiseShip.h"

using namespace std;

int main()
{
    Ship * Ships[3];
    
    Ships[0] = new Ship("Slice of Life", "  1968");
    Ships[1] = new CruiseShip(200, "Titanic", "1988");
    Ships[2] = new CargoShip(1000, "USS Enterprise", "2026");
    
    
    for (int i = 0; i < 3; i ++)
    {
        Ships[i]->printInfo();
    }
    
    for (int i = 0; i < 3; i ++)
    {
     
        delete Ships[i];
    }
    
    
    
    return 0;
}

