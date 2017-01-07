//
//  HourlyEmployee.cpp
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "HourlyEmployee.h"


HourlyEmployee::HourlyEmployee(string n, string ssc,double hours,double rate) : Employee( n,ssc)
{
    cout<<"\nCreating a Hourly worker object...\n";
    this ->hours = hours ;
    this -> hourlyPayRate = rate;
    
    
}

HourlyEmployee::~HourlyEmployee()
{
    cout<<"\nDestroying a Hourly worker object..."<<endl;
}

double HourlyEmployee::getHours()
{
    return hours;
}

double HourlyEmployee::getHourlyPayRate()
{
    
    return hourlyPayRate;
}


void HourlyEmployee::setHourlyPayRate(double payRate)
{
    hourlyPayRate = payRate;
}

void HourlyEmployee::SetHours(double h)
{
    hours = h;
}


void HourlyEmployee::calculateWeeklyPay()
{
    double weekpay = 0;
    
    weekpay = (hours * hourlyPayRate);
    
    cout<<"The weekly pay is : "<<weekpay<<endl;
    
    
}

void HourlyEmployee::displayInfo()
{
    cout<<"Hourly Employees Name:"<<name<<endl;
    cout<<"Social Security Number: "<<ssn<<endl;
    cout<<"Hourly Pay Rate: $"<<hourlyPayRate<<endl;
    cout<<"Hours worked for a week : "<<hours<<endl<<endl;
    
}