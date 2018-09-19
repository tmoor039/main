// file name: demo.cpp --- for demonstration purpose
// JC
// 9/27/2012

#include "student.h"
#include <iostream>
using namespace std;

int main() {
	Student s1;
	s1.setFn("JC");
	s1.setLn("Yang");
	s1.setSid("B123456789");
	s1.setGpa(3.50);

	s1.displayInfo();

	return 0;
}
