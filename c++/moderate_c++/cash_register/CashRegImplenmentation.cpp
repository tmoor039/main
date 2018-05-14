//
//  CashRegImplenmentation.cpp
//  CashReg
//
//  Created by James Moore on 10/25/12.
//  Reviwed 1 May 2018
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


