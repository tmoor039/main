// This program will will display the use of carious different functions
//Tiago Moore
//March , 18 2012

#include<iostream>
#include<cmath>
using namespace std;




//function prototytpes

// return type:void
// parameters :3 ints (day, month, year)
//This function will promt the user for a date, and display in the following format x/xx/xxxx
void PrintDate(int,int,int);

//return type: float
//parameters: 2 floats (b and h)
//This function calculates the area of a circle given two values and displays it 
float CircleArea(float);

// return type : float
// parameters: 1 temperature
// This function promts the user for a temperature and converts it form celsius to degrees Fahrenheit
float Fahrenheit (float);

//return type : int
//parameters: 1 int
// This function  returnt he value of any number n factorial
int Factorial(int);


// return type : bool
// parameters :1 int(k)
// This function determines wether a given number is perfect square 
bool IsSquared(int); 

int main()
{

//declare variables 
	int day = 0 , month = 0, year = 0, number = 0  ,square = 0 ,obama = 0, factorTen = 0, factor = 0 ;
	float radius = 0.0, area = 0.0, temperature = 0.0, areaCircle = 0.0 , outside = 0.0 ;
	
//promt for date
	cout<<"Please enter today date\n\n";

	cout<<"Month: ";
	cin>>month;
	
	cout<<"Day: ";
	cin>>day;

	cout<<"Year: ";
	cin>>year;

// call function to display date entered
	PrintDate(month,day,year);

	cout<<"President Obamas birthdate is ";PrintDate(06,04,1961);


//call function to calculate area of circle
	cout<<"Enter the radius of the circle: ";
	cin>>radius;

	cout<<"The area of the circle is "<<CircleArea(radius)<<endl<<endl;
	
	
//Call function to convert temperature
	cout<<"Enter a temperature in Celcius to be converted to Fahrenheit: ";
	cin>>temperature;
	
	cout<<endl;

	cout<<"The temperature in Fahrenheit is "<<Fahrenheit(temperature)<<" degrees. "<<endl<<endl;

	outside =  Fahrenheit(0);


	cout<<"0 degrees celcius is "<<outside<<" degrees farenheit."<<endl<<endl;

//call function to display number factorial

	cout<<"Enter a number : ";
	cin>>factor;
	cout<<"the factorial of "<<factor<<" is"<<Factorial(factor)<<endl;

	factorTen = Factorial(10);


	cout<<"The factorial of 10 is "<<factor<<endl;



// call function to prove number is square root

 

	cout<<"Enter a number again:";
	cin>>square;

	if (IsSquared(square))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;


return 0;
}

void PrintDate(int m ,int d,int y)
{

	cout<<m<<"/"<<d<<"/"<<y<<"\n\n";


}

float CircleArea(float r)
{
	float PI = 3.14;

	return PI * r * r;
}

float  Fahrenheit(float t)
{
	return t*9.0/5.0 + 32;
}

int Factorial(int n)
{
	  int total = 0;

	for (int i = 1; i <= n ; i++)
	{
		total *= i;
	
	}

	return total;
}

bool IsSquared(int s)
	{

		int answer = 0;
	
		answer = sqrt(s);

	if((answer*answer) == s)

		return true;
	else

		return false;

	}




