//this program calculates the avarage  days  a companys employee is absent.
//Tiago Moore
//Mar 25, 2012

#include<iostream>
#include<iomanip>
using namespace std;

//function prototypes

//return type: void
//parameters: 1 int(employees) passed by reference
//purpose:this function asks the user for the number of for number of employees
void GetNumEmployees(int&);

//return type: int
//parements: 1 int(number of employees)
//purpose: ask how many days each employee missed and add them to a total
int TotalDaysMissed(int);

//return type:float
//parameters:2 ints(days missed, and  number of employees)
//this function will calculate the average days the that the employees were absent
float AverageDaysMissed(float,float);


int main()
{
		int employeeNumber = 0  , average = 0;


//call first function  get number of employees
GetNumEmployees(employeeNumber);
//call second function to store average value in average 
average = TotalDaysMissed(employeeNumber);

	//call third function to calculate average
	cout<<"The average number of days missed  by an employee for this company is : "<<AverageDaysMissed(employeeNumber,average)<<endl;



return 0;
}


//function definitions
void GetNumEmployees(int &employees)
{

do
{
	cout<<"Enter the Number of employees in your company: ";
	cin>>employees;

//input validation


		if (employees < 1)
		cout<<"Invalid, the number of employees must be greater than one.\n"<<endl;
}
	while (employees < 1);

}


	
int TotalDaysMissed(int employees)
{
	int total = 0 , daysmissed = 0 ;

	for(int i = 1;i <= employees; i++)
	{
		do
		{
			cout<<"Enter the amount of days employee #"<<i<<" was absent: ";
			cin>>daysmissed;

			//input validation
			if (daysmissed < 0 )
	
			cout<<"The number of days missed cannot be less than 0 "<<endl;
		}	
		while (daysmissed < 0 );

		total += daysmissed;

		}

		cout<<fixed<<showpoint<<setprecision(1);
		cout<<"The total amount of days missed by all employees  in the past year was "<<total<<" days."<<endl;

	return total;
}
		

float AverageDaysMissed(float employees, float total)
{
	return total/employees;
}

