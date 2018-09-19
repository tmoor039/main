//
//  Triangle.cpp
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "Triangle.h"


#include <iostream>


using namespace std;

Triangle::Triangle(double a) : BasicShape(area)
{
    cout<<"Creating a triangle...\n"<<endl;
    base = 0;
    height = 0;
    
}

Triangle::Triangle(int b,int h ,double a ) :BasicShape(area)
{

    cout<<"Creating a triangle....\n"<<endl;
    
    base = b;
    height  = h;
    
}


Triangle::~Triangle()
{
    cout<<"\nDestroying a triangle....\n";
}


void Triangle::setb(int b)
{
    base = b;
}

void Triangle::seth(int h)
{
    
    height  = h ;
}


int Triangle::getb()
{
    return base;
}

int Triangle::geth()
{
    return height;
}

void Triangle::calcArea()
{
    area = 0.5*(base)*(height);
    
    cout<<"The triangle area is : "<<area<<endl<<endl;
    
}

void Triangle::draw()
{
    cout<<"Drawing a triangle...\n\n";
    
    cout<<"     **"<<endl;
    cout<<"    ****"<<endl;
    cout<<"   ******"<<endl;
    cout<<"  ********"<<endl;
    cout<<" **********"<<endl;
    cout<<"*************"<<endl<<endl;
 
}

void Triangle::print()
{
    cout<<"Triangle information is as follows: \n";
    cout<<"The value of the triagle height is: "<<getb()<<endl;
    cout<<"The value os the triangle height is :"<<geth()<<endl;
}

