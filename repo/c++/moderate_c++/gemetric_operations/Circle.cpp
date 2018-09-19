//
//  Circle.cpp
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//


#include "Circle.h"
#include<iostream>
#include <cmath>

using namespace std;


Circle::Circle(double area):BasicShape(area)
{
    
    cout<<"Creating a circle...\n"<<endl;
    //initalize other values to  0 and area to the basic shape 
	centerx = 0;
	centery = 0;
	radius =  0;
	
}

Circle::Circle ( int x , int y, int r , double area) : BasicShape(area)
{
    cout<<"Creating a circle...\n"<<endl;
    centerx = x;
    centery = y;
    radius = r;
    
}

Circle::~Circle()
{
	cout<<"\nDestroying a circle.."<<endl;
}

void Circle :: setx(int x)
{
	centerx = x;
}

void Circle :: sety ( int y )
{
	centery = y ;
}

void Circle :: setradius ( int r )
{
	radius = r;
	
}


int Circle:: getx()
{
    
	return centerx;
}


int Circle:: gety ()
{
	return centery ;
}

int Circle :: getradius()
{
	return radius;
}


void  Circle:: calcArea()
{
  
	area =  PI * pow(radius,2);
	
	cout<<"The area is : " <<area<<endl<<endl;
}

void Circle:: print()
{
    
	cout<<"The circle is located at : \n"<<endl;
	cout<<"Center X : "<<getx()<<endl;
	cout<<"Center Y : " <<gety()<<endl;
	cout<<"Radius : "<<getradius()<<endl;
}

void Circle:: draw()
{
    
    cout<<"\nDrawing a circle.... \n"<<endl;
    
}
