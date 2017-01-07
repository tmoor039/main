//
//  File.cpp
//  practicestacks
//
//  Created by James Moore on 10/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;


characterStack::characterStack(int size)
{
    stacks = new char[size];
    arraysize = size;
    
    arraytop = -1 ;
    
}

characterStack::characterStack( const characterStack &object )
{
    // create array
    if (object.arraysize > 0) {
        stacks = new char [object.arraysize];
    }
        else 
        {
            stacks = NULL;
    }
    
    arraysize = object.arraysize;
    
    //copy contents of stack
    for ( int i = 0 ; i < arraysize; i ++)
    {
        stacks[i] = object.stacks[i];
        
    }

    //set top of stack 
    arraytop = object.arraytop;
}

//deconstrucor


characterStack::~characterStack()
{
    delete []stacks;
}


void characterStack::push(char number)
{
    if (isFull()) {
        cout<<"The stack is full"<<endl;
    }
    
    else {
        arraytop++;
        stacks[arraytop] = number;
    }
    
}

void characterStack::pop(char &number)
{
    if (isEmpty()) {
        cout<<"The stack is empty"<<endl;
    }
    else {
        
        number = stacks[arraytop];
        arraytop--;
        
    }
}

bool characterStack:: isFull() const
{
    bool value;
    
    if (arraytop ==  arraysize -1)
    {
        value = true;
    }
    else
    {
       value = false;
    }
    
    return value;
}

bool characterStack::isEmpty()const
{
    bool status;
    
    if( arraytop ==  -1)
    {
        status = true;
    }
    
    else 
    {
        status = false;
    }
    
    return status;
}


