//
//  Circle.h
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Extra_Credit__Circle__
#define __Extra_Credit__Circle__

#include "BasicShape.h"



class Circle :public BasicShape
{
    
    private :
    
    int centerx, centery , radius;
    const float PI = 3.1415926535;
    
public:
    
    //constructors
    
	Circle(double);
	
	Circle(int, int, int,double);
    
	//deconstructor
	virtual ~Circle();
	//mutators
    
	void setx(int);
	void sety(int);
	void setradius(int);
	
	//accessors
	int getx();
	int gety();
	int getradius();
    
	//virtual functions
	virtual void calcArea();
	virtual void print();
	virtual void draw ();
	
};



#endif /* defined(__Extra_Credit__Circle__) */
