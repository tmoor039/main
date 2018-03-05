
#include<iostream>
using namespace std;

//function prototypes
//return type: float
//parameters: none
//purpose: this function prompts the user for the length of a rectangle and validates it to be positive
float GetLength();

//return type: void
//parameters: 1 float by ref(w)
//purpose: this function prompts the user for the width of a rectangle and validates it to be positive
void GetWidth(float &w);

//return type: float
//parameters: 2 floats by value(l,w)
//purpose: this function calculates and returns the perimeter of the given rectangle
float RectanglePerimeter(float l, float w);

//return type: void
//parameters: 2 floats by value(l,w), 1 float by ref(a)
//purpose: this function calculates the area of the given rectangle
void RectangleArea(float l, float w, float &a);


//return type: void
//parameters: 2 floats by value(a,p)
//purpose: this function displays the area and perimeter of the given rectangle
void DisplayData(float a,float p);


int main()
{
	//variables
	float mylength = 0.0, mywidth = 0.0, myarea = 0.0, myperimeter = 0.0;
	
	//call functions
	mylength = GetLength();
	
	GetWidth(mywidth);
	
	myperimeter = RectanglePerimeter(mylength, mywidth);
	
	RectangleArea(mylength, mywidth, myarea);
	
	DisplayData(myarea, myperimeter);
	


 return 0;
}
//function definitions

float GetLength()
{
	//declare a local variable
	float length = 0.0;
	do
	{
	cout<<"Enter the length of a rectangle: ";
	cin>>length;
	if(length <=0)
		cout<<"Invalid.  Must be positive.\n\n";
	}
	while(length <=0);	

	return length;
}

void GetWidth(float &w)
{

	do
	{
	cout<<"Enter the width of a rectangle: ";
	cin>>w;
	if(w <=0)
		cout<<"Invalid.  Must be positive.\n\n";
	}
	while(w <=0);	


}

float RectanglePerimeter(float l, float w)
{
	return 2 * l + 2 * w;
}

void RectangleArea(float l, float w, float &a)
{
	a = l * w;
}

void DisplayData(float a,float p)
{
	cout<<"Area:\t\t"<<a<<" square units.\n";
	cout<<"Perimeter:\t"<<p<<" units.\n";
	
}
