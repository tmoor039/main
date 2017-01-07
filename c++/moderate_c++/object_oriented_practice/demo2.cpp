// file name: demo2.cpp --- version 2 using pointers
// for demonstration purpose
// JC
// 9/27/2012

#include "student.h"
#include <iostream>
using namespace std;

int main() {
	Student * p;
	p = new Student;
	if (p != NULL) {
		p->setFn("JC");
		p->setLn("Yang");
		p->setSid("B123456789");
		p->setGpa(3.50);

		p->displayInfo();

		delete p;
	} else {
		cout <<"Error: cannot allocate memory dynamically."<<endl;
	}

	return 0;
}
