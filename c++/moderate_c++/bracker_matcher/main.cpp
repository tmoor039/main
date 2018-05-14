//
//  main.cpp
//  practicestacks
//  Created on 10/6/12.
// Reviewed 30 April 2018 - test case for  stack data structure 
//

#include <iostream>
#include "Header.h"
#include<string>
#include<cstdlib>

using namespace std;


int main()
{
    
    string expression ;
    cout<<"Enter the expression that you would like to count parenthesis:"<<endl;
    getline(cin,expression);

    
    //create an object
 characterStack *p = new characterStack(expression.length());
    

    size_t length = expression.length();
    
    char toptempchar;
    
    for ( int i = 0; i < length; i ++)
    {
        if (expression.at(i) == '(' ) 
        {
            p->push(expression.at(i));
        }
        
        else if( expression.at(i) == ')')
        {
            if(p->isEmpty()) 
            {
                cout<<"Error  there is not a matching right brace. The Stack is empty."<<endl;
                   exit( EXIT_SUCCESS);
            }
            else {
        
            p->pop(toptempchar);
            cout<<"The braces match."<<endl;
            }     
                
        
        }
        
    }
    
    if (p->isEmpty()) {
        cout<<"Expression is balanced"<<endl;
        
    }
    else {
        cout<<"Expression is not balanced, there is no correspoding right parenthesis"<<endl;
    }
    
    
    
    return 0 ;
}
