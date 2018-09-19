//functionPractice1.cpp
//March 12, 2012
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


//function prototypes
//return type: void
//parameters: none
//Purpose: This function displays an introduction to the user.
void PrintIntro();


//return type: string
//parameters: none
//Purpose: This function prompts the user for a name and returns the name.
string GetName();
//return type: void
//parameters: 1 string(name)
//Purpose: This function prints a greeting to the user by name.
void DisplayGreeting(string);
//return type: int
//parameters: none
//Purpose: This function prompts for and returns an age.  The function validates that the age is positive.
int GetAge();
//return type: float
//parameters: none
//Purpose: This function prompts for and returns a GPA.  The function validates that the GPA is between 0.0 and 4.0.
float GetGPA();
//return type: void
//parameters: 1 string(name), 1 int(age), 1 float(gpa)
//Purpose: This function displays the user's information.
void DisplayUserInfo(string, int, float);
int main()
{ //declare and initialize variables
 string username;
 int userage = 0;
 float usergpa = 0.0;
 
 //call(invoke) PrintIntro function
 PrintIntro();
 
 //call GetName and store the result in username
 username = GetName();
 //call DisplayGreeting
 DisplayGreeting(username); //username is the actual parameter that gets passed to the formal parameter name
 //invoke GetAge
 userage = GetAge();
 
 //invoke GetGPA
 usergpa = GetGPA();
 
 //call DisplayUserInfo
 DisplayUserInfo(username, userage, usergpa);
 
 //call DisplayUserInfo with other info
 DisplayUserInfo("John Doe", 22, 3.4);
 return 0;
}
//function definitions
void PrintIntro() //function headers
{
 cout<<"Welcome to my program!!!\n\n\n";
}
string GetName()
{ //declare a local variable for name
 string name;
 cout<<"Enter your name: ";
 cin>>name; 
 return name;
}
void DisplayGreeting(string name)
{
 cout<<"Hi "<<name<<", nice to see you today!!\n\n";
}
int GetAge()
{
 //local variable
 int age = 0;
 do
 {
 cout<<"Enter your age: ";
 cin>>age;
 if(age < 1)
  cout<<"Invalid.  Age must be positive.\n";
 }
 while(age < 1);
 
 return age;
}
float GetGPA()
{
 //local variable
 float gpa = 0.0;
 do
 {
 cout<<"Enter your gpa: ";
 cin>>gpa;
 if(gpa < 0.0 || gpa >4.0)
  cout<<"Invalid.  GPA must be between 0.0 and 4.0\n";
 }
 while(gpa < 0.0 || gpa >4.0);
 
 return gpa;
}
void DisplayUserInfo(string name, int age, float gpa)
{
 cout<<"Name:\t"<<name<<endl;
 cout<<"Age:\t"<<age<<endl;
 cout<<fixed<<showpoint<<setprecision(1);
 cout<<"GPA:\t"<<gpa<<endl;
}
