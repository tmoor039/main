//
//  BasicShape.h
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Extra_Credit__BasicShape__
#define __Extra_Credit__BasicShape__


class BasicShape
{
    
protected:
    
    double area;
    
public:
    
    //constructor
    BasicShape(double);
    
    //destructor
    virtual ~BasicShape() = 0;
    
    //mutator
    
    double getarea();
    
    virtual void calcArea() = 0;
    virtual void print() = 0;
    virtual void draw() = 0;
    
    
    
};









#endif /* defined(__Extra_Credit__BasicShape__) */
