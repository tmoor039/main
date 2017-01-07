//
//  IntArray.h
//  Lab5 Exeptions
//
//  Created by TJ Moore on 12/8/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Lab5_Exeptions__IntArray__
#define __Lab5_Exeptions__IntArray__

class IntArray
{
private:
    int *aptr;                     // Pointer to the array
    int arraySize;                 // Holds the array size
public:
    IntArray(int);                 // Constructor
    IntArray(const IntArray &);    // Copy constructor
    ~IntArray();                   // Destructor
    
    int getsize() const               // Returns the array size
    { return arraySize; }
    
	// subscript operator for non-const objects returns modifiable lvalue
    int &operator[](const int &);  // the non-const version
    
	// subscript operator for const objects returns rvalue
    int operator[](const int &) const;  // the const version
};

#endif /* defined(__Lab5_Exeptions__IntArray__) */
