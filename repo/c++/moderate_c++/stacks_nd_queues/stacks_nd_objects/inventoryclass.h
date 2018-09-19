//
//  Header.h
//  pg1099 problem # 12
//
//  Created by James Moore on 10/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef pg1099_problem___12_Header_h
#define pg1099_problem___12_Header_h
#include "inventoryclass.h"



class Inventory
{
    
    private :
            
    int serialnumber;
    int manufacturedate;
    int lotnumber;
    
    
public:
    
    //constructors
    Inventory();
    Inventory(int,int,int);
    
    
    int getserialnumber() const;
    int getmanufacturedate() const;
    int getlotnumber() const;

    void setserialnumber(int snum);
    void setmanufacutredate(int mandate);
    void setlotnumber(int lotnum);
    
    
    void displayfunctions() const;
    
        
};

#endif
