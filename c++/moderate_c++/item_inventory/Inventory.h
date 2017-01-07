// This class has overloaded constructors.
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
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