//
//  Employee.h
//  Final
//
//  Created by TJ Moore on 12/13/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef __Final__Employee__
#define __Final__Employee__

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string ssn;
    
public:
    // accessors are const: accessors can access members' value;
    // they can never modify members' value.

    //constructors
    Employee(string name  , string ssn );
    
    virtual ~Employee() = 0 ;
    
    //getters
    string getname() const;
    string getSSN() const;
  
    
    //setters
    
    // mutators: can modify members' value
    void setname(string EmployeesName);
    void setSSN(string EmployeesSocial);

    
    //virtual functions
    
    virtual void calculateWeeklyPay() = 0 ;
    virtual void displayInfo()  = 0 ;
    
    
};// the semicolon is required


#endif /* defined(__Final__Employee__) */
