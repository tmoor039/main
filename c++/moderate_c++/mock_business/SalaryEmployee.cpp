//
//  SalaryEmployee.cpp
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "SalaryEmployee.h"


SalaryEmployee::SalaryEmployee(string n, string ssc,double pay) : Employee( n,ssc)
{
    cout<<"\nCreating a SalaryWorker object...\n";
    annualSalary = pay ;

}

SalaryEmployee::~SalaryEmployee()
{
    cout<<"\nDestroying a Salary worker..."<<endl;
}

double SalaryEmployee::getAnnualSalary()
{
    return annualSalary;
}

void SalaryEmployee::SetAnnualSalary(double salary)
{
    
    annualSalary = salary;
}

void SalaryEmployee::calculateWeeklyPay()
{
    double weekpay = 0;
    
    weekpay = annualSalary/52.0;
    
    cout<<"The weekly pay is : "<<weekpay<<endl;

    
}

void SalaryEmployee::displayInfo()
{
    cout<<"Salary Worker Name:"<<name<<endl;
    cout<<"Social Security Number: "<<ssn<<endl;
    cout<<"Annual Salary $:"<<annualSalary<<endl<<endl;

}