//
//  employee.cpp
//  
//
//  Created by James Moore on 9/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "employee.h"
#include <iostream>

using namespace std;

//Constructor

Employee::Employee()
{
    name = " ";
    idNumber = " ";
    position = " ";
    department = " ";

}

Employee::Employee(string dpt, string pos)
{
    dpt = department;
    pos = position;
    
}


//getters
string Employee::getname()const 
{
    return name;
}

string Employee::getidNumber() const
{
    return idNumber;
}

string Employee::getdepartment() const
{
    return department;
}
string Employee::getposition()const
{
    return position;
}

//setters
void Employee::setname(string EmployeesName)
{
    this ->name = EmployeesName;
}

void Employee::setidNumber(string EmployeeIdNumber)
{
    this -> idNumber = EmployeeIdNumber;
}

void Employee::setdepartment(string EmployeeDepartment)
{
    this -> department = EmployeeDepartment;
}

void Employee::setposition(string EmployeesPosition)
{
    this -> position = EmployeesPosition;
}

//define function

void Employee::displayInfo()const
{
    cout<<"Employee Info: "<<endl<<endl;
    
    cout<<"Employee name : "<<name<<endl;
    cout<<"Employee ID Number : "<<idNumber<<endl;
    cout<<"Employees Department: "<< department<<endl;
    cout<<"Employees Position : : " <<position <<endl;
    
}





























