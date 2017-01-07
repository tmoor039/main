//
//  stackheader.h
//  pg1099 problem # 12
//
//  Created by James Moore on 10/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef pg1099_problem___12_stackheader_h
#define pg1099_problem___12_stackheader_h

#include "inventoryclass.h"

class InventoryStack
{
    
private:
    Inventory *list;
    int listsize;
    int topoflist;

public:
    
    //constructor
    
    InventoryStack(int);// integer is the size
    
    InventoryStack( const InventoryStack &);
    
    //deconstructor
    
    ~InventoryStack();
    
    
    void push(Inventory);
    void pop(Inventory&);
    bool isFull();
    bool isEmpty();
    
    
    
    
    
};

#endif
