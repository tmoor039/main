//This program will promt the use for the value of a property  then calculate and  display the property value and tax amount.
//Tiago Moore
//Feb 4, 2012

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{

	 float land = 0.00 , assessmentValue = 0.00 , tax = 0.00;
	 const float TAXVALUE = 0.0064;

	cout<<"Enter the total amount of the property you wish to buy: $ ";
	cin>>land;
	
	assessmentValue = land * 0.6;

	cout<<showpoint<<fixed<<setprecision(2);

	cout<<"The assessment value for the property is $"<<assessmentValue<<endl;

	tax = assessmentValue * TAXVALUE;

	cout<<"The total property tax for this land is $"<<tax<<endl;

return 0;

}
