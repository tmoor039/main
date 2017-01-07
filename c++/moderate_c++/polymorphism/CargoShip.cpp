//
//  CargoShip.cpp
//  Lab4 Ships
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "CargoShip.h"


CargoShip::CargoShip(int w, string name, string year) : Ship(name,year)
{
    cout<<"creating a cargoship...."<<endl;
    weight = w;
    
}

CargoShip::~CargoShip()
{
    cout<<"\nDestroying a cargoship object...";
}

void CargoShip::setWeight(int tonnage)
{
    weight = tonnage;
}


int CargoShip::getWeight()
{
    return  weight;
}

void CargoShip::printInfo()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Tonnage: "<<getWeight()<<endl<<endl;
}