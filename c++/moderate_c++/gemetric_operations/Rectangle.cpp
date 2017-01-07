//
//  Rectangle.cpp
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "Rectangle.h"

#include <iostream>


using namespace std;

Rectangle::Rectangle(double a) : BasicShape(area)
{
    cout<<"Creating a rectangle...\n"<<endl;
    length = 0;
     width = 0;

}

Rectangle::Rectangle(int l,int w ,double a ) :BasicShape(area)
{
    cout<<"Creating a rectangle....\n"<<endl;
    
     length = l;
     width  = w;
    
}


Rectangle::~Rectangle()
{
    cout<<"\nDestroying a rectangle....\n";
}


void Rectangle::setl(int l)
{
    length = l;
}

void Rectangle::setw(int w)
{
    
    width  = w ;
}


int Rectangle::getl()
{
    return length;
}

int Rectangle::getw()
{
    return width;
}

void Rectangle::calcArea()
{
    area = length * width;
    
    cout<<"The rectangles area is : "<<area<<endl<<endl;
    
}

void Rectangle::draw()
{
    cout<<"Drwaing a rectangle...\n\n";
    cout<<  "+--------------+\n";
    cout<<  "|              |\n";
    cout<<  "|              |w="<<getw()<<"\n";
    cout<<  "|              |\n";
    cout<<  "+--------------+\n";
    cout<<"\t\tl="<<getl()<<"\n\n";
}

void Rectangle::print()
{
    cout<<"Rectangles information is as follows: \n";
    cout<<"The value of the rectangles lengh is "<<getl()<<endl;
    cout<<"The value os the rectangles width is "<<getw()<<endl;
}

