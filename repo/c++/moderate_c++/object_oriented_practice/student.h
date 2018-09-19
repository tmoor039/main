// File name: student.h --- specification file / definition file
// JC
// 9/27/2012
// header guard

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
	private: 
		string fn;
		string ln;
		string sid;
		double gpa;

	public:
		// accessors are const: accessors can access members' value;
		// they can never modify members' value.	
		string getFn() const;
		string getLn() const;
		string getSid() const;
		double getGpa() const;

		// mutators: can modify members' value
		void setFn(string firstName);
		void setLn(string lastName);
		void setSid(string studentID);
		void setGpa(double gpa);

		// display function for demo
		void displayInfo() const;
}; // the semicolon is required
#endif
