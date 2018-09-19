//
//  IntArray.cpp
//  Lab5 Exeptions
//
//  Created by TJ Moore on 12/8/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

// Implementation file for the IntArray class
#include <iostream>
#include <cstdlib>   // For the exit function
#include "IntArray.h"
#include "ArrayIndexEception.h"

using namespace std;

//*******************************************************
// Constructor for IntArray class. Sets the size of the *
// array and allocates memory for it.                   *
//*******************************************************

IntArray::IntArray(int s)
{
    arraySize = s;
    aptr = new int [s];
    //polulate arrray with 0's
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//******************************************************
// Copy Constructor for IntArray class.                *
//******************************************************

IntArray::IntArray(const IntArray &obj)
{
    arraySize = obj.arraySize;
    aptr = new int [arraySize];
    //make a copy
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//******************************************************
// Destructor for IntArray class.                      *
//******************************************************

IntArray::~IntArray()
{
    if (arraySize > 0)
        delete [] aptr;
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

int &IntArray::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
    {
        throw ArrayIndexExeption(sub);
	}
    return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a copy of the element          *
// in the array indexed by the subscript.               *
//*******************************************************
int IntArray::operator[](const int &sub) const
{
    if (sub < 0 || sub >= arraySize)
    {
		throw ArrayIndexExeption(sub);
	}
    return aptr[sub];
}
