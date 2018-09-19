// classwork6.cpp
// Tiago Moore
// April 20, 2012
// Reviewed 25 Feb 2018


#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//declare a struct names Car

struct Car
{
	//fields// attributes
	string make, model;
	int year ;
	float cost;

	//constructor
	Car()
	{
		year = 0;
		cost = 0.0;
	}
};// end of struct always with a semi colin


//function prototypes


// return type: void
// parameters : one array of cars and int  size of array
// purpose: promt for data  for cars
void GetCars(Car[], int);

//return type :void
// parameters : one car
// displays data of one car
void DisplayCar(Car);


//return type : float
//arameters: one array of cars and one int size of cars
//purpose: to calculate and return the acverage cost of the cars
float AverageCost(const Car[], int );


//return type: Car
// parameters :  one array of cars and size of array of cars
// purpose: function searches and returns the newest car by year
Car Newest (const Car[], int );

// return type: void
// parameters: one array of cars and size of array
// purpose modifies the cost of each car so it is discouted by 10 %
void DiscountCars(Car[], int );


const int SIZE = 3;
int main()
{
	//declare variables
	float average = 0.0;
	Car newest;


//declare array of cars called mycars
Car myCars[SIZE];	

// declare a car called newestcar
	Car newestCar;

// call function to get cars

	GetCars(myCars,SIZE);

//call function to display cars 

cout<<fixed<<showpoint<<setprecision(2);

cout<<"Make \tModel \tYear \tCost"<<endl;
cout<<"--------------------------------"<<endl;
for (int i = 0 ; i < SIZE ; i++)
{
 DisplayCar(myCars[i]);
}

cout<<endl<<endl;

	
average = AverageCost(myCars,SIZE);

cout<<"Average Cost: "<<average<<endl;

newest = Newest(myCars,SIZE);

cout<<"Newest Car: "<<newest.make<<" "<<newest.model<<endl;

cout<<endl<<endl;

DiscountCars(myCars,SIZE);

cout<<"Discounted Prices :"<<endl;

for (int i = 0; i < SIZE; i ++)
{
	cout<<myCars[i].model<<"\t$"<<myCars[i].cost<<endl;
}


return 0;
}


// function defenitions


 void GetCars(Car carro[], int size)
{

	// for loop to promt for each peice of data in the arrayf cars 
		for (int i = 0; i < size; i ++)
	{
		
		cout<<"Enter make of car: ";
		cin>>carro[i].make;
		cout<<"Enter model of car: ";
		cin>>carro[i].model;
		cout<<"Enter the year: ";
		cin>>carro[i].year;
		cout<<"Enter the cost: ";
		cin>>carro[i].cost;
	}


}



// create a function to display o the data of one car 

void DisplayCar(Car whip)
{

	cout<<whip.make<<"\t"<<whip.model<<"\t"<<whip.year<<"\t$"<<whip.cost<<endl;
}



float AverageCost(const Car MyCar[], int size)
{
 	// local variable
	float total = 0.0 ;
	float average = 0.0;
	
	for ( int  i = 0;  i < size ; i ++)
	{

	total += MyCar[i].cost;
	
	}

	average = total/size;

	return average;
}


Car Newest(const Car whip[], int size)
{
	//local variable highest year
	Car newest = whip[0];

	for (int i = 1 ; i < size; i ++)
	{
		if (whip[i].year > newest.year)
		newest = whip[i];
	}

return newest;

}


void DiscountCars(Car Array[], int size)
{
	for (int i = 0; i < size; i ++)
	{
		Array[i].cost * .90;
	}
}




