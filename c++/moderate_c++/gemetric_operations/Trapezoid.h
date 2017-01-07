//
//  Trapezoid.h
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Extra_Credit__Trapezoid__
#define __Extra_Credit__Trapezoid__

#include "BasicShape.h"


class Trapezoid :public BasicShape
{
    
    private :
    
    int topbase,bottombase, height ;
    
    
public:
    
    //constructors

    Trapezoid(double);
	
	Trapezoid(int, int, int,double);
    
	//deconstructor
	virtual ~Trapezoid();
	//mutators
    
	void setTopbase(int);
	void setBottombase(int);
	void setheight(int);
	
	//accessors
	int getTopBase();
	int getBottomBase();
	int getHeight();
    
	//virtual functions
	virtual void calcArea();
	virtual void print();
	virtual void draw ();

		
};





#endif /* defined(__Extra_Credit__Trapezoid__) */
