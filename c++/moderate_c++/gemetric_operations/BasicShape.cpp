//
//  BasicShape.cpp
//  Extra Credit
//
//  Created by TJ Moore on 12/2/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "BasicShape.h"
#include  <iostream>

using namespace std;

//constructor
BasicShape::BasicShape(double a)
{
    cout<<"creating a Basic Shape...\n";
	this-> area = a;
}

//destructor

BasicShape::~BasicShape()
{
	cout<<"Destroying a basic shape."<<endl;
}

void  BasicShape::calcArea()
{
	cout<<"Area : "<<area<<endl;
}
