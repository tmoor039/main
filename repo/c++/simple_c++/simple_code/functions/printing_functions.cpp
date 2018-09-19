//Tiago Moore

// mad.cpp

//This program will promt user for data and display in functions


#include<iostream>
#include<string>
using namespace std;

//function prototypes

//return type: string
//parameters: none
//purpose : Promt user for his or her name
string Name();


//return type : int
//parameters : none
// purpose : promt and returns an age
int Age();

//return type : string
//parameters : none
//purpose : Promt user for current city
string City();


//return type :string
//parameters :none
//purpose: Promt user for  name of college
string College();

//return type :string
//parameters:none
//purpose: Promt user for profession
string Profession();


//return type: string
//parameters: none
//purpose : promt user  for a type of animal
string Animal();



//return type: string
//parameters: none
//purpose: promt user for name of animal
 string AnimalName();

//return type : void
//parameters: 6 string , 1 int
//purpose: display message on screen with inputted values
void DisplayMessage(string,string,string,string,string,string,int);


int main()
{
	string personName, personCity , personCollege, personProfession, petName , petType;
	int personAge = 0 ;

//call Name function and store it in personName

personName = Name();

//call Age function and store it in personAge

personAge = Age();

// call City function and store it in personCity

personCity = City();

// call College function and store it in personCollege

personCollege = College();

//call Profession function and store it in personProfession

personProfession = Profession();

// call Animal function and store it in petType

petType = Animal();


//call AnimalName function and store it in petName;

petName = AnimalName();

cout<<endl<<endl;
//Display Message with void function

DisplayMessage(personName, personCity , personCollege, personProfession, petType , petName, personAge);








return 0;
}

//function definitions

string Name()
{
	string name;

	cout<<"Please enter your name: ";
	getline(cin,name);

	return name;
}


int Age()
{
	int age = 0;
	cout<<"Please enter your age: ";
	cin>>age;

cin.ignore(5,'\n');

	return age;
}


string City()
{
	string city;

	cout<<"Please enter your city: ";
	getline(cin,city);

	return city;
}


string College()
{
	string college;
	cout<<"Please enter your college: ";
	getline(cin,college);
	
	return college;
}

string Profession()
{
	string profession;

	cout<<"Please enter your profession: ";
	getline(cin, profession);

	return profession;
}

string Animal()
{
	string animal;
	cout<<"Enter your animal type: ";
	getline(cin,animal);

	return animal;
}

string AnimalName()
{
	string animalName;
	cout<<"Please enter the name of your animal: ";
	getline(cin, animalName);

	return animalName;
}

void DisplayMessage(string name,string city, string college,string profession,string animal,string animalName, int age)
{
	cout<<"There once was a person named "<<name<<" who lived in "<<city<<". At the age of "<<age<<", "<<name<<" went to college at "<<college<<". "<<name<< " graduated and went to work as a "<<profession<<". Then, "<<name<<" adopted a(n) "<<animal<<" named "<<animalName<<". They both lived happily ever after!\n\n";
}











