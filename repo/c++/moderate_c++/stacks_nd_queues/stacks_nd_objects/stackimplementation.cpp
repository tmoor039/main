//
//  File.cpp
//  pg1099 problem # 12
//
//  Created by James Moore on 10/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "stackheader.h"

using namespace std;

InventoryStack::InventoryStack(int size)
{
    list = new Inventory[size];
    
    listsize = size;
    
    topoflist = -1;
}

//copy constructor
InventoryStack::InventoryStack( const InventoryStack & temp)
{
    //create the stack array (list)
    
    if(temp.listsize > 0)
    {
        list = new Inventory[temp.listsize];
    
    }
    else 
    {
        list = NULL;
    }
        //copy the size of the stack attribute
        
        listsize = temp.listsize;
        
       //set the top of the list
        
        topoflist = temp.topoflist;
        
}


InventoryStack::~InventoryStack()
{
    delete [] list;
}


void InventoryStack::push(Inventory tmp)
{
    if (isFull())
    {
        cout<<"The stack is full."<<endl;
    }
    else {
        cout<<"Pushing into stack."<<endl;
        topoflist++;
        
        list[topoflist] = tmp;
       
    }
}

void InventoryStack::pop(Inventory &tmp)
{
    if (isEmpty()) {
        cout<<"Stack is empty.";
        
    }
    else 
    {
            cout<<"Popping from stack."<<endl;
            
        tmp = list[topoflist];
        topoflist--;
        
    }
    
}

bool InventoryStack::isEmpty()
{
    bool value;
    
    if (topoflist == -1) 
    {
        value = true;
    }


    else
    {
        value = false ; 
    }
    
    return value;
}

bool InventoryStack::isFull()
{
    bool status;
    
    if( topoflist ==listsize -1 )
    {
        status = true;
    }
    else   
    {
    status = false;
    }

return status;
}
