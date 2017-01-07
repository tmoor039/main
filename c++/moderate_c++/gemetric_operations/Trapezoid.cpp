//
//  Trapezoid.cpp
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "Trapezoid.h"
#include<iostream>


using namespace std;


Trapezoid::Trapezoid(double area):BasicShape(area)
{
    
    cout<<"Creating a trapezoid...\n"<<endl;
    //initalize other values to  0 and area to the basic shape
	topbase = 0;
	bottombase = 0;
	height =  0;
	
}

Trapezoid::Trapezoid ( int t , int b, int h , double area) : BasicShape(area)
{
    cout<<"Creating a trapazoid...\n"<<endl;
    topbase= t;
    bottombase = b;
    height = h;
    
}

Trapezoid::~Trapezoid()
{
	cout<<"\nDestroying a trapezoid.."<<endl;
}

void Trapezoid:: setTopbase(int t)
{
	topbase = t;
}

void Trapezoid :: setBottombase ( int b )
{
	bottombase = b ;
}

void Trapezoid :: setheight( int h )
{
	height = h;
	
}


int Trapezoid:: getHeight()
{
    
	return height;
}


int Trapezoid:: getTopBase() 
{
	return topbase ;
}

int Trapezoid :: getBottomBase()
{
	return bottombase;
}


void  Trapezoid:: calcArea()
{
    
	area = ((bottombase+topbase)/2.0)* height;
	
	cout<<"The area of the trapezoid is : " <<area<<endl;
}

void Trapezoid:: print()
{
    
	cout<<"The dimentions of the trapezoid is as follows: \n"<<endl;
	cout<<"Top Base : "<<getTopBase()<<endl;
	cout<<"Bottom Base  : " <<getBottomBase()<<endl;
	cout<<"Height : "<<getHeight()<<endl;
}

void Trapezoid:: draw()
{
    
    cout<<"\nDrawing a Trapezoid.... "<<endl;
    
}
