//
//  ArrayIndexEception.h
//  Lab5 Exeptions
//
//  Created by TJ Moore on 12/8/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Lab5_Exeptions__ArrayIndexEception__
#define __Lab5_Exeptions__ArrayIndexEception__

#include <iostream>
#include <string>
using namespace std;

class ArrayIndexExeption
{
    private :
    int index;
    string errorMSG;

public:
    
    ArrayIndexExeption(int i)    {
        cout<<"\nCreating an array index exeption object..."<<endl;
        errorMSG = " Invalid index : out of range \n\n";
        index = i;
    }
    ~ArrayIndexExeption()
        {
            cout<<"Destroying an array index exeption object...\n"<<endl;
        }
    
    int getIndex()
    {
        return index;
    }
    
    string getErrorMsg()
    {
        return errorMSG;
    }
    
    
    
};

#endif /* defined(__Lab5_Exeptions__ArrayIndexEception__) */
