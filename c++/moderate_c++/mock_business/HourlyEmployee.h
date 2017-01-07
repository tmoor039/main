//
//  HourlyEmployee.h
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Final__HourlyEmployee__
#define __Final__HourlyEmployee__


#include "Employee.h"


class HourlyEmployee : public Employee
{
    
private:
    
    double hours;
    double hourlyPayRate;
    
    
public:
    
    //constructors
    HourlyEmployee(string,string,double,double);
    virtual ~HourlyEmployee();
    
    //getters or accessors
    
    double getHours();
    double getHourlyPayRate();
    
    //setters or mutators
    void setHourlyPayRate(double);
    void SetHours(double);
    
    virtual void calculateWeeklyPay();
    
    virtual  void displayInfo();
    
    
    
    
};

#endif