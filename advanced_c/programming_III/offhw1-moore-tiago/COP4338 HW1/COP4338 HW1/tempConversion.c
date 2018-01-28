/*I understand that this homework assignment cannot be joint work with another student in the class or whoever previously took this class.
																				
Name: Tiago Moore 

Date: 1/24/2015
*/

#include <stdio.h>

int main()
{
 	float  fahr, celsius;
	int lower = 0, upper = 300, step = 20;
	int menu = 0, input = 0 ; 


	do{	

	printf("Choose the type of temperature conversion you would like to do: \n");

	printf("1. Celcius to Fahrenheit.\n");
	printf("2. Fahrenheit  to Celcius.\n");
	printf("3. Exit.\n" ); 

	scanf("%d",&menu);

	switch(menu)
	{
	case 1:
	{

		printf("Enter the temperature you would like to convert: ");
		scanf("%d",&input);
		
		fahr = (input +32)/.55;

		printf(" %d in Celcius is %f in Fahrenheit",input,fahr);
	break;
	} 

	case 2:
	{
	
	printf("Enter the temperature you would like to convert: ");

	scanf("%d",&fahr);
	
		celsius = 0;	
		celsius = (5.0/9.0)*(fahr-32.0);
		  
		printf(" %d in Fahrenheit is %d in Celcius",fahr,celsius);

	break; 
	 }
  
	default:
		input = 0; 	
	}
	}
	while( menu != 1 || menu != 2 || menu !=3);	

	
return 0;
}

