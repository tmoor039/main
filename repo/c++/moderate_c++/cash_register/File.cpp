//
//  File.cpp
//  CashReg
//
//  Created by James Moore on 10/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<iomanip>
#include "Inventory.h"

// Constructor #1
InventoryItem::InventoryItem()
{ // Initialize description, cost, and units.
    description = "";
    cost = 0.0;
    units = 0; }

// Constructor #2
InventoryItem::InventoryItem(string desc)
{ // Assign the value to description.
    description = desc;
    
    // Initialize cost and units.
    cost = 0.0;
    units = 0; }

// Constructor #3
InventoryItem::InventoryItem(string desc, double c, int u)
{ // Assign values to description, cost, and units.
    description = desc;
    cost = c;
    units = u; }

// Mutator functions
//setters
void InventoryItem::setDescription(string d) 
{ description = d; }

void InventoryItem::setCost(double c)
{ cost = c; }

void InventoryItem::setUnits(int u)
{ units = u; }

// Accessor functions
//getters
string InventoryItem::getDescription() const
{ return description; }

double InventoryItem::getCost() const
{ return cost; }

int InventoryItem::getUnits() const
{ return units; }


//Display Function

void InventoryItem::display() const
{
    cout<<endl;
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Item Description: "<< description<<endl;
    cout<<"Item Cost : $"<<cost<<endl;
    cout<<"Number of Units: "<<units<<endl<<endl;
}