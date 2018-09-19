//
//  Ship.cpp
//  Lab4 Ships
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "Ship.h"


Ship::Ship()
{
    name = " ";
    year = " ";
}

Ship::Ship(string n, string y)
{
    
    name = n;
    year  = y;
    
    cout<<"Creating a ship....\n\n";
}

Ship::~Ship()
{
    cout<<"\nDestroying a ship object...";
}

void Ship::setName(string n)
{
    name = n;
}

void Ship::setYear(string y)
{
    year = y;
}

void Ship::printInfo() 
{
    cout<<"Name: "<<name<<endl;
    cout<<"Year: "<<year<<endl;
}