//
//  Rectangle.h
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Extra_Credit__Rectangle__
#define __Extra_Credit__Rectangle__


#include "BasicShape.h"


class Rectangle :public BasicShape
{
    
    private :
    
    int length, width ;

    
    
    //constructors
public:
    
	Rectangle(double);
	
	Rectangle(int, int, double);
    
	//deconstructor
	virtual ~Rectangle();
	//mutators
    
	void setl(int);
	void setw(int);
	
	//accessors
	int getl();
	int getw();

	//virtual functions
	virtual void calcArea();
	virtual void print();
	virtual void draw ();
	
};




#endif /* defined(__Extra_Credit__Rectangle__) */
