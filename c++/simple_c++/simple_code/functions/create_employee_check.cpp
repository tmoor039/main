

#include<iostream>

#include<string>

#include<iomanip>

using namespace std;



//function prototypes:



//return type: string

//parameters: none

//This function prompts for and returns the user's name

string GetName();



//return type: void

//parameters: 1 string by reference(social)

//This function prompts for and returns a social security number

void GetSSN(string &social);



//return type: float

//parameters: none

//This function prompts for and returns the weekly hours worked.

//The number of hours worked must be between 0 and 168.

float GetWeeklyHours();



//return type: void

//parameters: 1 float by ref(payrate)

//This function prompts for the hourly pay rate.  

//The pay rate must be greater than $7.67.

void GetHourlyPay(float &payrate);



//return type: void

//parameters: 1 float by ref(ins)

//This function prompts for and returns the amount deducted for health insurance.

//The amount paid can not be negative.

void GetHealthInsurance(float &ins);



//return type: float

//parameters: 2 floats by value(hours, payrate)

//This function calculates and returns the weekly pay.

//Any hours over 40 are considered overtime and are paid time and a half.

float GrossPay(float hours, float payrate);



//return type: float

//parameters: 1 float by value(grosspay)

//This function calculates and returns the amount deducted for Medicare.

//Medicare is 1.5% of the gross pay. 

float Medicare(float grosspay);



//return type: float

//parameters: 1 float by value(grosspay)

//This function calculates and returns the amount deducted for Social Security.

//Social Security is 6.5% of the gross pay. 

float SocialSecurity(float grosspay);



//return type: float

//parameters: 1 float by value(grosspay)

//This function calculates and returns the amount deducted for federal taxes.

//Federal taxes are based on Annual Income and are calculated as follows:

/*

$0.00 to $8500.00		10%

$8500.01 to $34500		15%

$34500.01 to $83600		25%

$174400.00	to $379150.00	33%

Over $379150.00			35%

*/

float FederalTax(float grosspay);



//return type: float

//parameters: 5 floats by value(grosspay,health,med, ss, fed)

//This function calculates and returns the net pay after health insurance, medicare, ss, and fed taxes are deducted.

float NetPay(float grosspay, float health, float med, float ss, float fed);



//return type: void

//parameters: 2 strings and 8 floats by value(name, ssn, hours, payrate, gross, health, med, ss, fed, net)

//This function displays a paycheck as follows:

/*

********************************************************

Employee Name: John Doe		SSN#: 123-33-3334

********************************************************

Hours Worked: 			60

Hourly Pay:			$12.50

Regular Gross Pay:		$875.00

Health Insurance:		$62.00

Medicare: 			$13.13

Social Security:		$56.88

Federal Withholding Tax:	$218.75

Net Pay:			$524.24			

*/

void DisplayPaycheck(string name, string ssn, float hours, float payrate, float gross, float health, float med, float ss, float fed, float net);



int main()

{

//declare and initialize variables

string myname, myssn;



float myweeklyhours = 0.0, myhourlypay = 0.0, myhealth = 0.0;

float mygross = 0.0, mynet = 0.0, mymed = 0.0, myfed = 0.0, myss = 0.0;

int menuChoice = 0;



do

	{

	//display menu

	cout<<"\n1)Create Employee Pay check\n2)Exit\n\n";

	

	//prompt for menuChoice

	cout<<"Enter your choice: ";

	cin>>menuChoice;

	

	//if statements to determine course of game

	if(menuChoice == 1)

		{

		

		//Call the functions

		myname=GetName();



		GetSSN(myssn);



		myweeklyhours=GetWeeklyHours();

		

		GetHourlyPay(myhourlypay);



		GetHealthInsurance(myhealth);

		

		mygross=GrossPay(myweeklyhours, myhourlypay);

		

		mymed=Medicare(mygross);

		

		myss= SocialSecurity(mygross);

		

		myfed=FederalTax(mygross);



		mynet=NetPay(mygross, myhealth, mymed, myss, myfed);



		DisplayPaycheck(myname, myssn, myweeklyhours, myhourlypay, 			mygross, myhealth, mymed, myss, myfed, mynet);



		}

	else if(menuChoice ==2)

		{

			//exit 

			cout<<"Have a nice day\n\n";

	

		}

	}

	while (menuChoice!=2);

	









return 0;

}



//function definitions

string GetName()

{

	//declare variable

	string name;

	

	//Promt user for name

	cout<<"Enter your name here:";

	cin>>name;

	

	return name;



}

void GetSSN(string &social)

{

		

	//Promt user for social

	cout<<"Enter your Social Security Number here:";

	cin>>social;

}



float GetWeeklyHours()

{

	//declare variable

	float weekHours=0.0;

	

	do

	{

 	//Promt user for hours per week

	cout<<"Enter your Weekly hours here:";

	cin>>weekHours;



	if (weekHours<0 || weekHours>168)

	//display invalid

	cout<<"Invalid. Please enter hours between 0 and 168 !\n";



	}

	while (weekHours<0 || weekHours>168);

	

	

}



void GetHourlyPay(float &payrate)

{

	

	do

	{

 	//Promt user for how much paid per hour

	cout<<"Enter your Hourly rate here:";

	cin>>payrate;



	if (payrate<7.67)

	//display invalid

	cout<<"Invalid. Hourly rate must be greater than 7.67!\n";



	}

	while (payrate<7.67);

	

}

void GetHealthInsurance(float &ins)

{

	do

	{

 	//Promt user for how much paid for helth insurance

	cout<<"Enter your Health Insurance rate here:";

	cin>>ins;



	if (ins<0)

	//display invalid

	cout<<"Invalid. Please enter amount greater than 0!\n";



	}

	while (ins<0);	



}

float GrossPay(float hours, float payrate)

{

	//declare variable

	float weekPay=0.0, time=0.0;

	if (hours>40)

	{

	 time=((hours-40)*(payrate/2)+payrate);

	 }

	hours+=time;

	

		

	weekPay=hours*payrate;



	return weekPay;





}

float Medicare(float grosspay)

{



grosspay=grosspay*0.015;



	return grosspay;

}



float SocialSecurity(float grosspay)

{

grosspay=grosspay*0.065;



	return grosspay;



}

float FederalTax(float grosspay)

{

	grosspay=grosspay*52;





	if (grosspay>0.00 && grosspay<8500.00)

	{

	return grosspay=grosspay*0.10;

	}



	else if (grosspay>8500.01 && grosspay<34500)

	{

	return grosspay=grosspay*0.15;

	}



	else if (grosspay>34500.01 && grosspay<83600)

	{

	return grosspay=grosspay*0.25;

	}



	else if (grosspay>83600.01 && grosspay<174400.00)

	{

	return grosspay=grosspay*0.28;

	}

	

	else if (grosspay>174400.01 && grosspay<379150.00)

	{

	return grosspay=grosspay*0.33;

	}



	else

	{

	return grosspay=grosspay*0.35;

	}







}

float NetPay(float grosspay, float health, float med, float ss, float fed)

{

	//declare variables

	float netpay=0.0;

	

	grosspay=grosspay*52;



	netpay=(health+med+ss+fed)-grosspay;

	

return netpay;



}





void DisplayPaycheck(string name, string ssn, float hours, float payrate, float gross, float health, float med, float ss, float fed, float net)



{



cout<<"\n********************************************************\n";

cout<<"Employee Name: "<<name<<"\t\t\tSSN#:"<<ssn<<endl;

cout<<"********************************************************\n";

cout<<"Hours Worked: \t\t\t\t"<<hours<<endl;

cout<<fixed<<showpoint<<setprecision(2);

cout<<"Hourly Pay: \t\t\t\t$"<<payrate<<endl;

cout<<"Regular Gross Pay: \t\t\t$"<<gross<<endl;

cout<<"Health Insurance: \t\t\t$"<<health<<endl;

cout<<"Medicare: \t\t\t\t$"<<med<<endl;

cout<<"Social Security: \t\t\t$"<<ss<<endl;

cout<<"Federal Withholding Tax:\t\t$"<<fed<<endl;

cout<<"Net Pay: \t\t\t\t$"<<net<<endl;



}





