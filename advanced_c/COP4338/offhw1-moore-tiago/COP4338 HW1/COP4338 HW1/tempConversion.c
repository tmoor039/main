/*I understand that this homework assignment cannot be joint work with another student in the class or whoever previously took this class.
 I hereby certify that I worked on this homework assignment by myself.
 I did not share any part of my code with my classmates and I did not copy any part of the code from anyone else or from Internet.

During the assignment, I only consulted the following book or online sources: (Please list your sources here.)
																				
By putting my name below, I understand that the course adopts a zero tolerance policy for cheating. I cannot give code to or receive code from other students.
I cannot pull code from the internet.
I understand any ethical violation will be reported to the university academic affairs and will result in an F grade for this course.

Name: Tiago Moore 

Date: 1/24/2015
*/

#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower = 0, upper = 300, step = 20;

	fahr = lower;
	do
	{
		celsius = (5.0/9.0)*(fahr-32.0);
		printf("%3.0f %6.1f\n",fahr, celsius);
		fahr = fahr + step;
    }
        while (fahr<= upper);
    

return 0;
}

