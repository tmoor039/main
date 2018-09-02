//
//  CashRegImplenmentation.cpp
//  CashReg
//
//  Created 10/25/12 .
//  Latest review 1 May 2018
//

#include <iostream>
#include"CashRegister.h"

using namespace std;

CashRegister::CashRegister(InventoryItem tmp)
{
    item = tmp;
}

CashRegister::CashRegister(InventoryItem tmp, int size)
{
    item  = tmp;
    
    quantity = size;
}

void CashRegister::setquantity(int qty)
{
    quantity = qty;

}

double CashRegister::getprofitcost(InventoryItem tmp)
{
    double profitcost = 0 ;
  
    profitcost = tmp.getCost() * .30;
    
    return profitcost;
}

double CashRegister::addprofitforunitprice(InventoryItem tmp , double proficost)
{
    return tmp.getCost() + proficost;
}


