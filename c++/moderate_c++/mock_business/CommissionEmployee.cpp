//
//  CommissionEmployee.cpp
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include "CommissionEmployee.h"



CommissionEmployee::CommissionEmployee(string n, string ssc,double sales ,double rate) : Employee( n,ssc)
{
    cout<<"\nCreating a Commision worker object...\n\n";
    this ->weeklySales = sales ;
    this -> commissionRate = rate;
    
    
}

CommissionEmployee::~CommissionEmployee()
{
    cout<<"\nDestroying a Commission worker object..."<<endl;
}

double CommissionEmployee::getWeeklySales()
{
    return weeklySales;
}

double CommissionEmployee::getCommissionRate()
{
    
    return commissionRate;
}


void CommissionEmployee::setCommissionRate(double payRate)
{
    commissionRate = payRate;
}

void CommissionEmployee::setWeeklySales(double sales)
{
    weeklySales = sales;
}


void CommissionEmployee::calculateWeeklyPay()
{
    double weekpay = 0.0;
    
    weekpay = (weeklySales * commissionRate);
    
    cout<<"The weekly pay is : $"<<weekpay<<endl<<endl;
    
    
}

void CommissionEmployee::displayInfo()
{
    cout<<" Commission Employees Name:"<<name<<endl;
    cout<<"Social Security Number: "<<ssn<<endl;
    cout<<"Weekly Sales:"<<weeklySales<<endl;
    cout<<"Commission Rate : $"<<commissionRate<<endl<<endl;
    
}