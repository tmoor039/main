//Tiago Moore

//grades.cpp

//this program prompts the user for the following student’s grades in a course – from 0 to 100

#include<iostream>
using namespace std;

int main()
{
	//declare and initialize variables
	 float assigment = 0.0, project = 0.0 , midterm = 0.0,  final = 0.0 , avarage =  0.0;

	//promt for each grade
	cout<<"Please enter grade for Assigments: ";
	cin>>assigment;

	if (assigment < 0 || assigment > 100)
	{
		cout<<"You must enter a grade between 0 and 100.";
	}



	cout<<"Please enter grade for Projects: ";
	cin>>project;

	if (project < 0 || project > 100)
	{
		cout<<"You must enter a grade between 0 and 100.";
	}

	cout<<"Please enter grade for your Midterm: ";
	cin>>midterm;

	if (midterm < 0 || midterm > 100)
	{
		cout<<"You must enter a grade between 0 and 100.";
	}

	cout<<"Please enter grade for your Final: ";
	cin>>final;

	if (final < 0 || final > 100)
	{
		cout<<"You must enter a grade between 0 and 100.";
	}

	avarage = (assigment + midterm + final + project)/ 4;

	cout<<"Your avarage is an "<<avarage<<"%"<<endl;

	if (avarage <= 60 )
	{	
		cout<<"You Failed the class!\n";
	}
	else
		{
			cout<<"You passed the class\n";
	}

return 0;
}



	

	


