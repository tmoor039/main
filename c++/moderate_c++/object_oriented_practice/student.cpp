// file name: student.cpp --- implementation file
// JC
// 9/27/2012

#include "student.h"
#include <iostream>

using namespace std;

string Student::getname() const
{
	return fn;
}
string Student::getidNumber() const
{
	return ln;
}
string Student::getdepartment() const
{
	return department;
}
string Student::getposition() const {
	return position;
}




// mutators: can modify members' value
void Student::setname(string firstName) 
{
	this->fn = firstName;
}
void Student::setLn(string lastName)
{
	this->ln = lastName;
}

void Student::setSid(string studentID)
{
	this->sid = studentID;
}
void Student::setGpa(double gpa)
{
	this->gpa = gpa;
}

// display function for demo
void Student::displayInfo() const 
{
	cout << "student INFO: "<<endl;
	cout << "first name: " << fn << endl;
	cout << "last name: " << ln << endl;
	cout << "student id: " << sid << endl;
	cout << "gpa: " << gpa << endl;
}


