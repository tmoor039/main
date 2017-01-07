#include<iostream>
#include<iomanip>
using namespace std;

//function protptypes

//return type: void
//Parameters: 1 float by ref(score)
//Purpose: This function prompts for a score and validates that it is between 0 and 10
void GetJudgeData(float&);

//return type: void
//Parameters: 5 floats by value (5 scores)
//This function calculates and displays the average of the scores after dropping the lowest and highest score
void CalcScore(float,float,float,float,float);

//return type: float
//Parameters: 5 floats by value (5 scores)
//Purpose: This function returns the lowest of the 5 scores
float FindLowest(float,float,float,float,float);

//return type: float
//Parameters: 5 floats by value (5 scores)
//Purpose: This function returns the highest of the 5 scores
float FindHighest(float,float,float,float,float);

int main()
{
	float score1 = 0.0, score2 = 0.0, score3 = 0.0, score4 = 0.0, score5 = 0.0;
	
	//call getJudgeData 5 times to store the 5 scores
	GetJudgeData(score1);
	GetJudgeData(score2);
	GetJudgeData(score3);
	GetJudgeData(score4);
	GetJudgeData(score5);

	//call CalcScore
	CalcScore(score1,score2,score3,score4,score5);
	
	
 return 0;
}

//function definitions
void GetJudgeData(float &score)
{
	do
	{
	cout<<"Enter a score between 0 and 10: ";
	cin>>score;
	//input validation
	if (score < 0 || score >10)
		cout<<"Invalid.  Score must be between 0 and 10.\n\n";
	}
	while	(score < 0 || score >10);

}

float FindLowest(float s1,float s2,float s3,float s4,float s5)
{
	//declare a local variable 
	//set lowest to the first value
	float lowest = s1;
	//compare the rest of the scores to lowest and only replace lowest if the value is less than the current lowest
	if (s2 < lowest)
		lowest = s2;
		
	if (s3 < lowest)
		lowest = s3;
	
	if (s4 < lowest)
		lowest = s4;
	
	if (s5 < lowest)
		lowest = s5;
				
	return lowest;


}

float FindHighest(float s1,float s2,float s3,float s4,float s5)
{
	//declare a local variable 
	//set highest to the first value
	float highest = s1;
	//compare the rest of the scores to highest and only replace highest if the value is less than the current highest
	if (s2 > highest)
		highest = s2;
		
	if (s3 > highest)
		highest = s3;
	
	if (s4 > highest)
		highest = s4;
	
	if (s5 > highest)
		highest = s5;
				
	return highest;


}
void CalcScore(float s1,float s2,float s3,float s4,float s5)
{
	//declare a local average
	float average = 0.0;
	
	//Calculate average after dropping the lowest and highest scores
	average = (s1 + s2 + s3 + s4 + s5 - FindLowest(s1,s2,s3,s4,s5) - FindHighest(s1,s2,s3,s4,s5)) / 3.0;
	
	//display average
	cout<<fixed<<showpoint<<setprecision(1);
	cout<<"The average after dropping the lowest and highest scores = "<<average<<endl;

}







