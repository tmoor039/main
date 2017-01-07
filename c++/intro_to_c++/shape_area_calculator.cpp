/*This program will create a menu  that will calculate the area of a circle, triagle, and rectangle. 
Tiago Moore
Feb, 23, 2012*/

//declare and initialize variables

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
int main()

{



const float PI = 3.14;
float radius = 0.0 , length = 0.0 , width = 0.0 , base = 0.0 , height = 0.0 ,  areaCircle = 0.0 , areaRectangle = 0.0 ,  areaTriangle = 0.0 ;
int choice =  0;

//make do while loop for menu choice

//display menu
do
{
	cout<<"Geometry Calculator\n";
	cout<<"1.Calculate the Area of a Circle\n";
	cout<<"2.Calculate the Area of a Rectangle\n";
	cout<<"3.Calculate the Area of a Triangle\n";
	cout<<"4.Exit\n\n";

	cout<<"Enter your choice (1 - 4) : ";
	cin>>choice;

	
	
//create if statements for choice


if (choice == 1)
{
	do
	{

//promt for radius of the circle
	cout<<"Enter the radius of a circle";
//input radius
	cin>>radius;
	
//input validation

	if ( radius < 0 )
//display invalid
	cout<<"The radius of the circle cannot be a negative number!!\n";


}
while (radius < 0 );

//calculate
	areaCircle = PI * pow(radius, 2);
//display area
	cout<<"Area  of circle = "<<areaCircle<<endl;

}//end if choice 


else if (choice == 2)

{
	do
	{

//promt for length of rectagle
	cout<<"Enter length of Rectangle: ";
	cin>>length;

	if (length < 0)
		cout<<"Invalid.\n\n";
	}
	while(length < 0);

do
{
//promt for width of rectangle 
	cout<<"Enter the width of the rectangle : ";
	cin>>width;


//input validation
	if (width < 0 )
	cout<< "Invalid.\n\n";
	}
	while (width < 0);

//calculate
areaRectangle = length * width ;

//display area
	cout<<"Rectangle Area = "<<areaRectangle<<endl;
		
}//end if choice == 2



else if (choice == 3)

{
	do
	{

//promt for base
cout <<"What is the base of the triangle? ";
//input base
cin>>base;

//input validation

	if (base < 0 )
//display invalid 
	cout<<"Base and cannot be a negative number!\n";
	}
	while (base < 0 );
		
do
{
//promt for height
	cout<<"What is the height for triangle? ";
//input height
cin>>height;

//input validation
	if (height < 0)
	cout<<"Invalid.\n\n";
	}
	while (height <0);


//calculate area
	areaTriangle = 0.5 * base * height;
//display are

cout<<"Area = "<<areaTriangle<<endl;

}//end if choice 3


 else if (choice == 4)
{
	//display 
	cout<<"Good Bye!\n\n";
}
else
	cout<<"Invalid.  You must choose 1 - 4.\n\n";

}
	while(choice != 4);

return 0;

}
