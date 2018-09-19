// This program will calculate  the users vehicle gas milage
//Tiago Moore
// Reviewed 5 Feb 2018	
//Jan,28, 2012

#include<iostream>
#include<iomanip>
using namespace std;

int main()

{
	int day = 0 ;


	float miles = 0.00 , gallon = 0.00, total = 0.00, gallonprice = 0.0, gasprice = 0.0 , mileprice = 0.0,dayprice = 0.0, weekprice = 0.0;

cout<<"##################################################################\n\n";
	cout<<"\tWelcome to my gas mileage calculator!!"<<endl<<endl;


	cout<<"How many gallons of gas can your car's tank hold?:  ";
	cin>>gallon;

	cout<<"With "<<gallon<<" gallons of gas, how many miles can your car be driven?  ";
	cin>>miles;

	total = miles / gallon;
	
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"Your car will drive :"<<setw(23)<<total<<" miles on every gallon!"<<endl;


	cout<<"Enter the price of gas per gallon: ";
	cin>>gallonprice;

	gasprice = gallonprice * gallon;

	cout<<"It will cost you "<<gasprice<<" dollars to fill up your car with gas!\n\n"<<endl;



	mileprice = gallonprice/total;

	cout<<"For every mile you drive you spend $ "<<mileprice<< " cents\n\n"<<endl;
	
	
	cout<<"How many miles do you drive everyday? ";
	cin>>day;

	dayprice = mileprice *day;

	cout<<"You spend "<<dayprice<<" dollars on transportation daily!\n\n"<<endl;
	
	weekprice = dayprice*7;

	cout<<"This means that you spend "<<weekprice<<" every week on gas!"<<endl;


return 0;

}



