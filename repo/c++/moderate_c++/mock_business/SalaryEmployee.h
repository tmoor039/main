//
//  SalaryEmployee.h
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Final__SalaryEmployee__
#define __Final__SalaryEmployee__

#include <iostream>
#include "Employee.h"


class SalaryEmployee : public Employee
{
    
private:
    
    double annualSalary;
    
    
public:
    
    //constructors
    SalaryEmployee(string,string,double);
    virtual ~SalaryEmployee();
    
    //getters or accessors
    
    double getAnnualSalary();
    
    //setters or mutators
    void SetAnnualSalary(double);
    
   virtual void calculateWeeklyPay();
    
   virtual  void displayInfo();
   
    
    
    
};



#endif /* defined(__Final__SalaryEmployee__) */
