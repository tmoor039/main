//
//  Intentory.h
//  CashReg
//
//  Created by James Moore on 10/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef CashReg_Inventory_h
#define CashReg_Inventory_h
#include <string>
using namespace std;

class InventoryItem
{
private:
    string description; // The item description
    double cost;        // The item cost
    int units;          // Number of units on hand
public:
    
    InventoryItem();
    InventoryItem(string);
    InventoryItem(string, double, int);
    
    //Setters
    //Mutators
    
    void setDescription(string desc);
    void setCost(double price);
    void setUnits(int quantity);
    
    //Getters
    //Accessors
    
    string getDescription() const ;
    double getCost() const;
    int getUnits() const ;
    
    
    //Display Function
    void display() const;
    
    
    
};
#endif

