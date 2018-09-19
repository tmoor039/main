//
//  Triangle.h
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Extra_Credit__Triangle__
#define __Extra_Credit__Triangle__


#include "BasicShape.h"


class Triangle :public BasicShape
{
    
    private :
    
    int base, height ;
    
    
    
    //constructors
public:
    
	Triangle(double);
	
	Triangle(int, int, double);
    
	//deconstructor
	virtual ~Triangle();
	//mutators
    
	void setb(int);
	void seth(int);
	
	//accessors
	int getb();
	int geth();
    
	//virtual functions
	virtual void calcArea();
	virtual void print();
	virtual void draw ();
	
};


#endif /* defined(__Extra_Credit__Triangle__) */
