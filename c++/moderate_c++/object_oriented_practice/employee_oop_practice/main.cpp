//
//  main.cpp
//  sample
//
//  Created by James Moore on 9/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "employee.h"
#include <iostream>

using namespace std;

int main()
{
    //declare an employee
    Employee e1 ;
    
    // use the setters or ( Mutators ) set values
    e1.setname("Tiago Moore");
    e1.setidNumber("T10001881");
    e1.setdepartment("Computer Science");
    e1.setposition("Lab Tech");
    
    //Display Values
    
    e1.displayInfo();
    
// Now use the getters 
    
    Employee *p;
    
    p = new Employee;
    
    if ( p != NULL )
    {
        p->setname("Brent Lewis");
        p->setidNumber("B04959605");
        p->setdepartment("Computer Science");
        p->setposition("Lab Tech");
        
        
        p->displayInfo();
        
        delete p;
        
    }
    else {
        cout<<"Unable to Allocate Memory"<<endl;
    }
    

        
    // Now create a separate dynamic array to promt for these values and display
    
    int size = 0 ;
    string people;

    
    cout<<"How many Employees information would you like to enter? ";
    cin>>size;
    
    cin.ignore(5,'\n');
    
    
    Employee * k = new Employee[size];
    
    if (k != NULL)
    {
        for ( int i = 0 ; i < size; i ++)
        {
            cout<<"Employee's " <<i+1<<" first name";
            getline(cin,people);
            k[i].setname(people);
        
            cout<<"Employee's " <<i+1<<" Id Number";
            getline(cin,people);
            k[i].setidNumber(people);
        

       
            cout<<"Employee's " <<i+1<<" department";
            getline(cin,people);
            k[i].setdepartment(people);
        
        
       
            cout<<"Employee's " <<i+1<<" first name";
            getline(cin,people);
            k[i].setposition(people);
        }

    //display all the values with the function
        
        for ( int i = 0 ; i < size ; i ++ ) 
        {
            k[i].displayInfo();
        }
    
        delete [] k;
        
        
    }
    
    else {
        cout<<"Did not properly allocate memory ";
    }
    
    
    
    
    
    

    
    
    
    
    
    
    return 0;
}


