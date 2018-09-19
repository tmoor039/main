//
//  main.cpp
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include <iostream>
#include<iomanip>
#include "Employee.h"
#include "SalaryEmployee.h"
#include "CommissionEmployee.h"
#include "HourlyEmployee.h"


using namespace std;

void timesTen(double);
void getNumber(int &);
void showValue ( int quantity);

int main()
{

    int number = 0;
    
   cout<<"the produdt of 3 x 10 is ";
    timesTen(3.0);
    
    
    getNumber(number);
    
    cout<<"Number = "<<number<<endl;
    
    showValue(5);
    
    Employee * Workers[3];
    
    Workers[0] = new SalaryEmployee ("JC Yang","123-45-6789",10000.00);
    Workers[1] = new HourlyEmployee("Sam John","111-11-1111",40.00,10.50);
    Workers[2] = new CommissionEmployee("Mark Doe","222-22-2222",10000.00,0.10);
    
    
    for ( int i = 0 ; i < 3 ; i ++)
    {
        cout<<fixed<<showpoint<<setprecision(2);
        Workers[i]->displayInfo();
        
        Workers[i]->calculateWeeklyPay();
        
    }
    
    
    for ( int i = 0 ; i < 3 ; i ++)
    {
        
        delete Workers[i];
    }

        
    
    return 0;
}
void timesTen(double arg)
{
    cout<<arg*10<<endl;
}

void getNumber(int& num)
{
    do
    {
        cout<<"Enter an integer (1-100):  ";
        cin>>num;
        
        if (num < 1 || num > 100)
        {
            cout<<"Invalid. Numbe must be between 1 and 100";
        }
        
        
        
    }while( num <1 || num > 100);
    

    
}


void showValue(int quantity)

{
    
    cout<<"\nthe value is :"<<quantity<<"\n"<<endl;
    
}

