//This is my program will calculate  the users restaurant bill
//Tiago Moore
// Jan 24,2012

#include<iostream>
#include<iomanip>

 using namespace std; 

int main()
{
	float  meal = 0.00, tax = 0.00;
	float tip = 0.00, totalCost= 0.00;
	const float TIPRATE = .20;
	
	
	
	cout<<"Welcome to Tiagos Restaurant!!"<<endl;

	cout<<"Please enter the Total Cost of the Meal:$  ";
	cin>>meal;
	
	tax = .06 * meal;

	tip = TIPRATE * meal;
	
	totalCost = meal + tax + tip;
	
	
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"Meal:\t\t$"<<meal<<endl;

	cout<<"Tax:\t\t$"<<tax<<endl;
	

	cout<<"Tip:\t\t$"<<tip<<endl;
	

	cout<<"Total Cost:\t$"<<totalCost<<endl;





return 0;
}
