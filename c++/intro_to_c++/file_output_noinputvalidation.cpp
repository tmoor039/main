/*This program will calculate and display the persons tax rate and total taxes owed.
Tiago Moore
Reviewed 5 Feb 2018
Jan 15, 2012*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int main()
{

//Declare and initialize variables
float income = 0.0 , tax = 0.0 , rate = 0.0;
string name;

//declare fie pointer
	ofstream outfile;

//Promt for name 
	cout<<" What is your name? ";
	getline(cin, name);

//Promp for income 
	cout<<"What is your Annual income? ";
	cin>>income;
 

//Create if staments for tax rate
if (income<7825)
{
rate= .10;
}
else if (income<31850)
{
rate = .15;
}
else if (income<77100)
{
rate= .25;
}
else if (income<160850)
{
rate= .28;
}
else if (income<349700)
{
rate = .35;
}
else
{
rate = .38;
}
//calculate total taxed owed

tax = income * rate;

//display data
cout<<fixed<<showpoint<<setprecision(2);
cout<<setw(6)<<"Name\t\tAnnual Income\tTax Rate\tTotal Tax Owed\n";
cout<<"---------------------------------------------------------\n\n";

cout<<left<<setw(15)<<name<<"\t"<<"$"<<income<<"\t"<<rate*100<<"%\t\t"<<"$"<<tax<<endl;

//append file to result to taxes.txt

	outfile. open("taxes.txt", ios::app);
// write data to file


outfile<<fixed<<showpoint<<setprecision(2);
outfile<<left<<setw(15)<<name<<"\t"<<income<<"\t"<<rate<<"\t\t"<<tax<<endl;


//close file
outfile.close();



return 0;

}


