/*This program will calculate amount of rainfall over years
Tiago Moore
Reviewed 5 Feb 2018
Feb 22, 2012*/

//Declare and initialize variables

#include<iostream>
using namespace std;

int main()

{

int numYears = 0 , numMonths = 0 ;
float inches = 0.0 , avarage = 0.0 , totalInches = 0.0;

//Intro
	cout<<"------------------------------------------------------------"<<endl;


do
{
//promt numYears
	cout<<"How many years  of rainfall do you want to calculate? ";
	cin>>numYears;

if (numYears<1)
//display invalid
	{
	cout<<"Years cannot be negative!\n";
	}
}
while (numYears<1);

//for numYears

for (int i = 1; i <= numYears; i++)
{//begin main loop

	
		for( int j = 1; j <= 12; j++)
		{//begin inner loop
	
do
{
	//promt 
	cout<<"Enter the amount of inches for year # "<<i<<" and month #"<<j<<" : ";
  	//user input inches
	cin>>inches;

//input validation

if (inches < 0)
	{
	//display invalid.
	cout<<"Invalid number.Inches must be a positive.\n";
	}
}
while (inches < 0 );


totalInches = totalInches + inches;

}//end outer for loop

		}//end inner for loop

	//calculate months
	numMonths = numYears * 12;


	//calculate avarage
	avarage = totalInches/numMonths;

	//display total months, inches, and avarage.
	cout<<"\nThe amount of inches for "<<numMonths<<" months is "<<totalInches<<" inches of rain.\n"<<endl;
	cout<<"The avarage amount of rainfall is for "<<numYears<<" years is "<<avarage<<" inches."<<endl<<endl;
	
return 0;

}


