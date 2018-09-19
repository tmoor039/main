//
//  Header.h
//  Money
//
//  Created by James Moore on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Money_Header_h
#define Money_Header_h

class Money 
{
    
    private:
    
    double amount;
    
    
public:
    
   //define constructors
    Money();
    
    Money(double);
    
    //accessors
    
    double getamount() const;
    
    
    //mutators
    void setamount(double);
    void addamount( const  Money&) ;
    void subtractamount (const Money&) ;
    
    // display function
    
    void displayamount();

    
};


#endif
