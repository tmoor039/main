/*I understand that this homework assignment cannot be joint work with another student in the class or whoever previously took this class.
																				
Name: Tiago Moore 

Date: 1/24/2015
Revision Date: 4/3/2018
// Program needs input validation. Menu prevents from exiting but - what if user inputs a character? 
// are there any other inputs that would cause the program to be exploitable? Can executable code in inputted? 

*/

#include <stdio.h>

int main()
{
	float  fahr= 0, celsius = 0, input= 0;
	int  menu = 0; 


	do{	

	printf("Choose the type of temperature conversion you would like to do: \n");

	printf("1. Celcius to Fahrenheit.\n");
	printf("2. Fahrenheit  to Celcius.\n");
	printf("3. Exit.\n" ); 

	scanf("%d",&menu); // this input leaves room for error. What if user inputs a character? 
	
	switch(menu)
	{
	case 1:
	{

		printf("Enter the temperature you would like to convert: ");
		scanf("%f",&input);
		
		fahr = (input*(5.0/9.0)+32);

		printf(" %.0f in Celcius is %.1f in Fahrenheit\n",input,fahr);
	break;
	} 

	case 2:
	{
	
	printf("Enter the temperature you would like to convert: ");

	scanf("%f",&fahr);
	
		celsius = (fahr-32)*(5.0/9.0);
		  
		printf(" %.0f in Fahrenheit is %.0f in Celcius\n",fahr,celsius);

	break; 
	 }
  
	default:
		break;
	}

	}	
	while( menu !=3);	

	
return 0;
}

