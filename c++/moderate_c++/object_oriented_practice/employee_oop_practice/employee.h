// program number two 



#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
	private: 
		string name;
		string idNumber;
		string department;
		string position;

	public:
		// accessors are const: accessors can access members' value;
		// they can never modify members' value.

    
        //constructors
        Employee();
        //two parameters
        Employee(string department ,string position );
    
    
        //getters
		string getname() const;
		string getidNumber() const;
		string getdepartment() const;
		string getposition() const;
    
    
        //setters
    
		// mutators: can modify members' value
		void setname(string EmployeesName);
		void setidNumber(string EmployeedIdNumber);
		void setdepartment(string EmployeeDepartment);
		void setposition (string EmployeesPosition);

		// display function for demo
		void displayInfo() const;
}; // the semicolon is required
#endif
