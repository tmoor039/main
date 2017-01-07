// This program calculates the circumference of a circle.
#include <iostream>
using namespace std;

#define PI 3.14159
#define DIAMETER 10.0

int main()
{
	// Variable to hold the circumference
	double circumference;

	// Calculate the circumference.
	circumference = PI * DIAMETER;

	// Display the circumference.
	cout << "The circumference is: " << circumference << endl;
	return 0;
}