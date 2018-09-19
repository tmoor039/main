//
//  main.cpp
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include <iostream>
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Triangle.h"

using namespace std;


int main()
{
    const int SIZE = 4;
    
    //create an array of pointers to the abstract class Basic shapes
    BasicShape *Shapes [SIZE];
    
    Shapes[0] = new Circle (1,2,3,0);
    Shapes[1] = new Rectangle(4,5,0);
    Shapes[2] = new Triangle(6,7,0);
    Shapes[3] = new Trapezoid(8,9,10,0);
    
    
    for ( int i = 0 ; i < SIZE ; i ++)
    {
        
        Shapes[i]->print();
        Shapes[i]->draw();
        Shapes[i]->calcArea();
    }
        
    
    for ( int i = 0 ; i < SIZE ; i ++)
    {
        
        delete Shapes[i];
    }
    
    
    
    
    
    
    return 0;
}