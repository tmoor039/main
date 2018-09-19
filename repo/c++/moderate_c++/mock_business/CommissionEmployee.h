//
//  CommissionEmployee.h
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Final__CommissionEmployee__
#define __Final__CommissionEmployee__

#include "Employee.h"

class CommissionEmployee : public Employee
{
    
private:
    
    double weeklySales;
    double commissionRate;
    
    
public:
    
    //constructors
    CommissionEmployee(string,string,double,double);
    virtual ~CommissionEmployee();
    
    //getters or accessors
    
    double getWeeklySales();
    double getCommissionRate();
    
    //setters or mutators
    void setWeeklySales(double);
    void setCommissionRate(double);
    
    virtual void calculateWeeklyPay();
    
    virtual  void displayInfo();
    
    
    
    
};

#endif /* defined(__Final__CommissionEmployee__) */
