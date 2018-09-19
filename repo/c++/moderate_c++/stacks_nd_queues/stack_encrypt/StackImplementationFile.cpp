//
//  StackImplementationFile.cpp
//  Project1
//
//  Created by James Moore on 10/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CharStack.h"

using namespace std;

CharStack::CharStack(int size)
{
    stack = new char[size];
    
    stacksize = size;
    
    stacktop = -1;
    
    
}

CharStack::CharStack( const CharStack  &object )
{
    
    if(object.stacksize > 0)
    {
        stack = new char[object.stacksize];
        
        
    }
    else {
        stack = NULL;

    }
    stacksize = object.stacksize;
    
    
    //copy contents of stack
    for ( int i = 0 ; i < stacksize; i ++)
    {
        stack[i] = object.stack[i];
        
    }
    
    stacktop = object.stacktop;
        
    
}

CharStack::~CharStack()
{
    delete []stack;
}


void CharStack::push(char number)
{
    if (isFull()) {
        cout<<"The stack is full"<<endl;
    }
    
    else {
        stacktop++;
        stack[stacktop] = number;
    }
    
}

void CharStack::pop(char &number)
{
    if (isEmpty()) {
        cout<<"The stack is empty"<<endl;
    }
    else {
        
        number = stack[stacktop];
        stacktop--;
        
    }
}

bool CharStack:: isFull() const
{
    bool value;
    
    if (stacktop ==  stacksize -1)
    {
        value = true;
    }
    else
    {
        value = false;
    }
    
    return value;
}

bool CharStack::isEmpty()const
{
    bool status;
    
    if( stacktop ==  -1)
    {
        status = true;
    }
    
    else 
    {
        status = false;
    }
    
    return status;
}


char CharStack::getbottom()
{
   
    return stack[0];
    
}


