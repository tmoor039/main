//
//  CashRegister.h
//  CashReg
//
//  Created by James Moore on 10/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef CashReg_CashRegister_h
#define CashReg_CashRegister_h

#include "Inventory.h"

 
class CashRegister
{
    
private:
    
    InventoryItem item;
    int quantity;
    
    
public:
    
    //constructor
    CashRegister(InventoryItem);
    CashRegister(InventoryItem,int );
    
    double getprofitcost(InventoryItem tmp);
    
    void setquantity(int);
 
    double getSubTotal();
    double getTotal();
    double getTax();
    double getCost();
    double addprofitforunitprice(InventoryItem, double);
    
    int subtractquantities();
    
    void displaytotaltax();
    
    
};



#endif
