//This program will calculate the users monlthy and yearly car expences. 
//Tiago Moore
// Reviewd 5 Feb 2018
//Jan 28,2012

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{

 	float loan = 0.00 , insurance = 0.00 , gas = 0.00 , changecost = 0.00, yearoil= 0.00, oil = 0.00 , tires = 0.00, maint = 0.00 , total = 0.00 , yearly = 0.00;

  	int oilchanges = 0;

	cout<<"\t Welcome to my vehicle expence calculator!\n\n";

	cout<<"How much do you spend each month on your loan payment? $ ";
	cin>>loan;

	cout<<"How much  do you spend montly on insurance? $ ";
	cin>>insurance;
	
	cout<<"How much do you spend every month on gas? $ " ;
	cin>>gas;

	cout<<"How many times a year do you change your vehicles oil? $ ";
	cin>>oilchanges;


	cout<<"How much does each oil change cost? $ ";
	cin>>changecost;

	yearoil= changecost*oilchanges;
	oil= yearoil/12;

	cout<<"How much do you spend with new tires monthly? $ ";
	cin>>tires;


	cout<<"How much do you spend each month on car maintenance? $ ";
	cin>>maint;

 
	 total = loan + insurance + gas + oil + tires + maint;

	 yearly = total*12;

	cout<<fixed<<showpoint<<setprecision(2);		

	cout<<"You spend $"<<total<<"  every month,and $"<<yearly<<" every year on car expences!"<<endl;

return 0 ;

}

