//
//  ArrayIndexEception.h
//  Lab5 Exeptions
//  Created by T Moore on 12/8/12.
//  Reviewed 13 June 18 

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
