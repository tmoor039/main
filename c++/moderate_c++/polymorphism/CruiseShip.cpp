//
//  CruiseShip.cpp
//  Lab4 Ships
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "CruiseShip.h"


CruiseShip::CruiseShip(int m, string name, string year) : Ship(name,year)
{
    cout<<"creating a cruisehip..."<<endl;
    maxPassengers = m;
    
}

CruiseShip::~CruiseShip()
{
    cout<<"\nDestroying a cruiseship object...";
}

void CruiseShip::setMax(int number)
{
    maxPassengers = number;
}


int CruiseShip::getMax()
{
    return  maxPassengers;
}

void CruiseShip::printInfo()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Capacity: "<<maxPassengers<<endl;
}