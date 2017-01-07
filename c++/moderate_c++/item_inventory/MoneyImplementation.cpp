//
//  File.cpp
//  Money
//
//  Created by James Moore on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include<iostream>
#include<iomanip>
#include"Money.h"

using namespace std;


//define constructors

Money::Money()
{
    amount = 0.0;
}

Money::Money(double amt) 
{
    amount = amt;
}
 

//define functions

double Money::getamount() const
{
    return amount;
}

void Money::setamount(double dinhero)
{
    amount  = dinhero;
}

void Money::addamount(const Money & object)
{
    amount += object.amount;
}

void Money::subtractamount(const Money & obj)
{
   this-> amount -= obj.amount;
}


void Money::displayamount()
{
    cout<<fixed<<showpoint<<setprecision(2);

    cout<<" Amount = $"<<amount<<endl;
}




