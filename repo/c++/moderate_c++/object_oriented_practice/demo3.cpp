// file name: demo3.cpp --- version 3 using pointers 
// pointing to an array of students
// for demonstration purpose
// JC
// 9/27/2012

#include "student.h"
#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

int main() {
	int howMany;
	cout <<"How many students you want to create?"<<endl;
	cin >> howMany;
	cin.ignore(INT_MAX, '\n'); // get rid of the trailing newline character left by cin. so that it will not mess up my getline() later


	Student * p = new Student[howMany];
	string s;
	double gpa;
	if (p != NULL) {
		// get info from user for all the students
		for (int i=0; i<howMany; i++) {
			cout <<"student " << i+1 << " first name: "<<endl;
			getline(cin, s); 
			p[i].setFn(s);

			cout <<"student " << i+1 << " last name: "<<endl;
			getline(cin, s); 
			p[i].setLn(s);

			cout <<"student " << i+1 << " student ID: "<<endl;
			getline(cin, s); 
			p[i].setSid(s);

			cout <<"student " << i+1 << " gpa: "<<endl;
			cin>>gpa;	
			cin.ignore(INT_MAX, '\n');
			p[i].setGpa(gpa);
		}

		for (int i=0; i<howMany; i++) {
			p[i].displayInfo();
		}
		delete [] p;
	} else {
		cout <<"Error: cannot allocate memory dynamically."<<endl;
	}

	return 0;
}
