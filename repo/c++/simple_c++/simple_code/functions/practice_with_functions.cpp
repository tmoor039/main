//FunctionWorksheetSolution.cpp
//March 14, 2012
#include<iostream>
using namespace std;
//function prototypes
//return type: float
//Parameters: 2 floats(l and w)
//Purpose: This function calculates and returns the area of the given rectangle
float RectangleArea(float,float);


//return type: bool
//Parameters: 1 int(n)
//Purpose: This function determines whether or not n is even.  If even, return true.  If odd, return false.
bool IsEven(int);


//return type: int
//Parameters: 2 ints(i and j)
//Purpose: This function calculates and returns sum of the integers from i to j.
int Sum(int,int);


//return type: float
//Parameters: 1 float(radius)
//Purpose: This function calculates and returns the volume of a sphere with the given radius.
float SphereVolume(float);

//return type: char
//Parameters: 1 float(numGrade)
//Purpose: This function returns the letter grade that corresponds to the given numeric grade.
char LetterGrade(float);


//return type: int
//Parameters: 1 int(n)
//Purpose: This function calculates and returns the sum of the natural numbers from 1 to n.
int SumN(int);



//return type: float
//Parameters: None
//This function prompts for and returns a grade that has been validated between 0 and 100.
float GetGrade();

//return type: int
//Parameters: None
//This function prompts for and returns an int that has been validated to be positive.
int GetInt();







int main()
{
 //Declare variables
 float length = 0.0, width = 0.0, area = 0.0, userradius = 0.0, volume = 0.0;
 int usernum = 0, low = 0, high=0;
 char letterGrade = ' ';
 float usergrade = 0.0;
 
 
 
 //prompt for length and width
 cout<<"Enter the length of a rectangle: ";
 cin>>length;
 cout<<"Enter the width of a rectangle: ";
 cin>>width;
 
 //call RectangleArea to display the area of the rectangle that the user entered
 cout<<"Your rectangle has area = " << RectangleArea(length, width)<<endl;
 
 //call RectangleArea to store the area of a rectangle with dimensions 4 and 20 in area
 area = RectangleArea(4,20);
 
 //display area
 cout<<"The area of a rectangle with dimensions 4 x 20 = "<<area<<endl;
 
 cout<<endl;
 
 //call IsEven to see if 15 is even
 if(IsEven(15) == true)
  cout<<"15 is even.\n";
 else
  cout<<"15 is odd.\n";
  
 //call GetInt to store a value in usernum
 usernum = GetInt();
 
 //call IsEven to see if usernum is even
 if(IsEven(usernum))
  cout<<usernum<<" is even.\n";
 else
  cout<<usernum<<" is odd.\n";
  
 cout<<endl; 
  
 //call Sum to display the sum of the numbers from 10 to 20
 cout<<"The sum of the numbers from 10 to 20 = "<<Sum(10,20)<<endl;
 
 //call GetInt to store low and high
 low = GetInt();
 high = GetInt();
 
 //diplay the sum of the numbers from low to high
 cout<<"The sum of the numbers from "<<low<<" to "<<high<<" = "<<Sum(low, high)<<endl;
 
 cout<<endl;
 
 //Call SphereVolume to store the volume of a sphere with radius 7 in volume
 volume = SphereVolume(7);
 //display volume
 cout<<"The volume of a sphere with radius 7 = "<<volume<<endl;
 
 //Prompt for radius
 cout<<"Enter a radius: ";
 cin>>userradius;
 
 //display the volume of the user's sphere
 cout<<"The volume of your sphere = "<<SphereVolume(userradius)<<endl;
 
 cout<<endl;
 
 //call GetGrade to store a grade in usergrade
 usergrade = GetGrade();
 
 //Call LetterGrade to display the user's letter grade
 cout<<"Your letter grade = "<<LetterGrade(usergrade)<<endl;
 
 //Store the letter grade for 82 in letterGrade
 letterGrade = LetterGrade(82);
 
 //display letterGrade
 cout<<"The letter grade that corresponds to 82 = "<<letterGrade<<endl;
 
 cout<<endl;
 
 //Call GetInt to store an integer in usernum
 usernum = GetInt();
 
 //Call SumN to display the sum of the first usernum natural numbers
 cout<<"The sum of the integers from 1 to "<<usernum<<" = "<<SumN(usernum)<<endl;
 
 //Call SumN to display the sum of the first 10 natural numbers
 cout<<"The sum of the intgers from 1 to 10 = "<<SumN(10)<<endl;
 
 
 return 0;
}





//function Definitions
float RectangleArea(float l,float w)
{
 return l * w;
}




bool IsEven(int n)
{
 if(n % 2 == 0)
  return true;
 else
  return false;
}




int Sum(int i,int j)
{
 //declare variable for total
 int total = 0;
 for(int n = i; n <= j; n++)
  total += n;
  
 return total;
 
}




float SphereVolume(float radius)
{
 return 4.0 / 3.0 * 3.14 * radius * radius * radius;
}



char LetterGrade(float numGrade)
{
 if(numGrade >= 90)
  return 'A';
 else if(numGrade >= 80)
  return 'B';
 else if(numGrade >= 70)
  return 'C';
 else
  return 'F';
}



int SumN(int n)
{
 //local variable for total
 int total = 0;
 for(int i = 1; i <= n; i++)
  total += i;
  
 return total;
}



float GetGrade()
{
 //local variable
 float grade = 0.0;
 do
 {
 cout<<"Enter a test grade: ";
 cin>>grade;
 if(grade < 0 || grade > 100)
  cout<<"Invalid.  Must be between 0 and 100.\n";
 }
 while(grade < 0 || grade > 100);
 
 return grade;
}


//return type: int
//Parameters: None
//This function prompts for and returns an int that has been validated to be at least zero.
int GetInt()
{
 int num = 0;
 do
 {
 cout<<"Enter an integer: ";
 cin>>num;
 if(num < 0)
  cout<<"Invalid.  Can not be less than zero.\n\n";
 }
 while(num < 0);
 
 return num; 
}
