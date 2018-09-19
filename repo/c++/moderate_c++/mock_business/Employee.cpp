//
//  Employee.cpp
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "Employee.h"

#include <iostream>

using namespace std;

//Constructor



Employee::Employee(string n, string Social)
{
    cout<<"\nCreating an employee object...."<<endl;
    
    name = n;
    ssn  = Social;
    
}

Employee::~Employee()
{
    cout<<"Destroying an Employee object...\n";
    
}



//getters
string Employee::getname()const
{
    return name;
}

string Employee::getSSN() const
{
    return ssn;
}

//setters
void Employee::setname(string EmployeesName)
{
    this ->name = EmployeesName;
}

void Employee::setSSN(string Social)
{
    this -> ssn = Social;
}

//define function

void Employee::calculateWeeklyPay()

{
    
    
}
void Employee::displayInfo()
{
}

