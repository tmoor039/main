//Tiago Moore
//April 1, 2012
//this program calculates test scores and drops the lowest one


#include<iostream>
using namespace std;




//function protytypes

//return type:void
//parameter: 1 float passed by reference (grade&)
//purpose: to promt the user for the test grade and validate 
void GetScore(float&);

//return type: void
//parameters: 5 floats passed by value(scores)
//purpose: to calculate  and display the averagage of the hihgest four scores
void CalcAverage(float,float,float,float,float);

//return type: float
//parameters: 5 floats passed by value
//purpose: to find  and return the lowest test score and subtract it from the average
float FindLowest(float,float,float,float,float);





int main()

{

	float score1 = 0 , score2 = 0 , score3 = 0 , score4 = 0 , score5 = 0 ;

	GetScore(score1);
	GetScore(score2);
	GetScore(score3);
	GetScore(score4);
	GetScore(score5);

	CalcAverage(score1,score2,score3,score4,score5);


return 0;

}



void GetScore(float &grade)
{

do
{
	//Promt for grade
	cout<<"Enter your grade: ";
	
	//Read in grade
	cin>>grade;



	//input validation
	if (grade < 0 or grade > 100)

	cout<<"Invalid, you must have a score between 0-100.";
}
while (grade < 0 or grade > 100);


}





float FindLowest(float s1,float s2,float s3,float s4,float s5)
{
	//declare local variable for lowest

	float lowest = s1;

	//if statements to determine lowest

	if (s2< lowest)
		
		lowest = s2;

	if (s3 < lowest)

		lowest = s3;

	if (s4 < lowest)
		
		lowest = s4;

	if (s5 < lowest )

		lowest = s5;


		return lowest;
}


void CalcAverage(float g1,float g2,float g3,float g4,float g5)
{
	float average = 0;
//calculate average

	 average = (g1+g2+g3+g4+g5 - FindLowest(g1,g2,g3,g4,g5))/4.0;


//display average
 
	cout<<"Your average is after dropping lowest grade is an "<<average<<endl;

}




