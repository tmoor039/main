//
//  main.cpp
//  Lab5 Exeptions
//
//  Created by TJ Moore on 12/8/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include <iostream>
#include "IntArray.h"
#include "ArrayIndexEception.h"

int main()
{
   

    

    int index, size, value, again;
    
        cout<<"Trying to assign values..\n\n";
        
    
    cout<<"Enter the size of the interger array you want to create: " ;
    cin>>size;
    
    
    
    IntArray numbers(size);
        
    
    try {
        do
        {
        cout<<"Enter the index of an array element (between 0 and "<<size<<"):";
        cin>>index;
        
        cout<<"Enter the value of the array element : ";
        cin>>value;
        
        numbers[index] = value;
        
        cout<<"\n"<<value<< " is assigned to the crresponding element of the array sucessflly.\n ";
        cout<<"\nHere is the value accessed by the non constant function: "<<numbers[index]<<endl<<endl;
        
        
        cout<<"assign values again?( enter 1 for yes, 2 for no)"<<endl;
        
        cin>>again;
            
        }while (again!=2);
        
        
        
    }catch (ArrayIndexExeption &e) {
        
            cout<<e.getErrorMsg()<<"the value "<<e.getIndex()<<" is not an available posisition"<<endl;
    }
    
   
    
    return 0;
    
}

