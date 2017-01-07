//
//  File.cpp
//  pg1099 problem # 12
//
//  Created by James Moore on 10/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "inventoryclass.h"

using namespace std;


Inventory::Inventory()
{
    serialnumber = 0;
    manufacturedate = 0;
    lotnumber = 0;
    
}

Inventory::Inventory(int snum, int mandate,int lotnum) 
{

    this->serialnumber = snum;
    this->manufacturedate= mandate;
    this->lotnumber = lotnum;
    
}


int Inventory::getserialnumber() const
{
    return this->serialnumber;
}

int Inventory::getmanufacturedate() const
{
    return this->manufacturedate;
}

int Inventory::getlotnumber() const
{
    return this-> lotnumber;
}


void Inventory::setlotnumber(int lotnum)
{
    this -> lotnumber = lotnum;
}

void Inventory::setmanufacutredate(int mandate)
{
    this -> manufacturedate = mandate;
}

void Inventory::setserialnumber(int snum)
{
    this-> serialnumber = snum;
}



void Inventory::displayfunctions() const
{
    cout<<"Serial: "<<serialnumber<<endl;
    cout<<"Manufacturing Date : "<<manufacturedate<<endl;
    cout<<"Lot Number: "<<lotnumber<<endl;
    cout<<endl<<endl;
}