//Tiago Moore
//April 1 2012
//homework8.cpp


#include<iostream>
using namespace std;
//function prototypes

//return type: float
//parameters: 1 string(division)
//purpose:Asks the user for the divisions quarterly sales  and validates it
float GetSales(string);

//return type: void
//parameters: 4 floats passed by value
//purpose: find the highest value and
void FindHighest(float,float,float,float);

int main()
{
	//declare variables for divisions
	string SW , NW , SE , NE;

	//declare variables for income

	float income1 = 0.0 ,income2= 0.0 , income3 = 0.0, income4 = 0.0;

 	//call GetSales to store value in income
	income1 = GetSales(SW);
	income2 = GetSales(NW);
	income3 = GetSales(SE);
	income4 = GetSales(NE);
	//call FindHighest to find highest income
	FindHighest(income1,income2,income3,income4);

return 0;
}

 float GetSales(string division)
{
	float sales = 0;
 
 do
{
	//Promt for Sales amount
	cout<<"Enter the amount of sales this division: ";
	//Read in sales
	cin>>sales;

	//input validation
		if (sales < 0)
	//display invalid
		cout<<"Dollar amounts cannot be less than 100."<<endl;


 }
 while (sales < 0);

return sales;
}

void FindHighest(float a, float b,float c,float d)
{
	//set local variable for highest

	float highest = a ;
	string division;
	
	if(b > highest)

	highest = b;
	
	if (c >highest)
	
	highest = c;

	if (d > highest)

	highest = d;

	// if statements to determine which division has had highest

	if (highest == a)
	{
		division = "SW";
	}
	else if (highest == b)
	{
		division = "NW";
	}
	else if (highest == c)
	{
		division = "SE";
	}
	else
	{
		division = "NE";

	}
 
	cout<<"The greatest amount of sales made this quarter is $"<<highest<<" made by the "<<division<<" division."<<endl;
}
