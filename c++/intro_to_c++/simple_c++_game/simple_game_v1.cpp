/*This is the first game project 
Tiago Moore
March 5, 2012*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;

//function prototypes
//return type:void
//paremeters:none
//purpose:this function displays an introduction to the user
void PrintIntro();

int main()

{

//Declare and initialize variables 

int  mainMenu = 0 , petMenu = 0 , playMenu = 0 ,  sleepMenu = 0;
float score = 0.0 , score2 = 0.0, score3 = 0.0 , totalScore = 0.0,random = 0 ,random2 = 0.0 , highest = 0;
string name , petName, highName;

//seed random number genorator
srand(time(NULL));


//declare file pointer for input
ifstream infile;

// decalre file pointer for output

ofstream outfile;

//INTRO

	PrintIntro();

//Promt for name

	cout<<"Hello There Please enter your name: ";
	getline(cin,name);
	
	cout<<endl;



do
{

//display mainMenu	

	cout<<"Hello "<<name<<", please choose an option from the following menu.\n\n";

	cout<<"1)See Rules\n2)Play Game\n3)Exit\n\n";

//Promt for mainMenu choice
	cout<<name<<", enter your choice here: ";
	cin>>mainMenu;
	
	cout<<endl;



//Create if statements for Main menu choice

	if (mainMenu == 1)

	{

	//Display Rules of Game

	cout<<"****************************************RULES***********************************************\n\n";

	 cout<<"First you will need to Choose your favorite pet. After pet has been chosen you will select if you want to give the pet food, drink , play with the pet  and also where you will put your pet to sleep everynight.You will choose what you want to give your pet and at the end your pets happyness percentage will be displayed.\n\n";

	}

	else if (mainMenu == 2)
	{



//open file highscore.txt for input
infile.open("highscore.txt",ios::in);
infile>>highName>>highest;
infile.close();

	


//Display Message
	cout<<"You have choosen to play the game! Now make sure you dont have an angry pet running around! \n\n";
	
do 
{
//cin ignore for petname string
	cin.ignore(5,'\n');

//Promt for petName
	cout<<"What would  you like to name your pet? ";
	getline(cin,petName);

//display menu petMenu
	cout<<"Choose the pet you would like to play with.\n\n";

	cout<<"1)Dog\n2)Cat\n3)Monkey\n\n";

//promt for petmenu choice
	cout<<"Enter your choice here: ";
	cin>>petMenu;

	cout<<endl;

score = petMenu * 32;

totalScore = score;

//if statements for pet choice

	if (petMenu == 1)
	{
	cout<<"You have choosen to play with a dog it is" <<totalScore<<"% happy!\n\n\n";
	}
	
	else if (petMenu == 2)
	{
	
	cout<<"You have choose to pay with a Cat, it is "<<totalScore/2<<" % happy!\n\n\n";

	}

	else if (petMenu == 3 )
	{


	cout<<"You have choosen to play with a Monkey!,"<<petName<<" is "<<totalScore/3<<" % happy!\n\n\n";	

	cout<<"m-----m------\nl l __ l l\n| (o o)|\n||(~)||\nll__ll\nll ll\nll ll\nw w\n\n";

	}

	else
	{
		cout<<"Invalid! you must choose something from 1 - 3\n";
	}

}while (petMenu !=1 && petMenu !=2 && petMenu !=3);


do
{

	//Display second Menu

	cout<<"Please choose what you would like to do with your pet.\n\n";

	cout<<"1)Give food\n2)Give a toy\n3)Give a bath\n\n";

	//Promt for playMenu
	cout<<"Enter your choice here: ";
	cin>>playMenu;

	cout<<endl;


score2 = playMenu *20;

totalScore += score2;

//create if staments for playMenu
	

	if (playMenu == 1)
	{
	cout<<"You choose to give "<<petName<<" something yummy to eat."<<petName<<" is now"<<totalScore<<" % happy.\n";
	}

	else if (playMenu == 2)
	{
	cout<<"You choose to give "<<petName<<" something to play with! This will keep him occupied for some hours!" <<petName<<" is now "<<totalScore<<" % happy.\n\n\n"; 

	}

	
	else if (playMenu == 3)
	{

	cout<<"You choose to give "<<petName<<" a bath! Now it smells like fresh strawberrys!It is now "<<totalScore<<" % happy.\n\n";
	
	}
	else
	{
	
	cout<<"Invalid ! you must choose a an activity from 1-3.\n";
	}

}while (playMenu !=1 && playMenu !=2 && playMenu !=3);


do
{

//Display Message

	cout<<"You must now decice where you would like your pet to sleep.\n\n";
	
	//Display sleepMenu

	cout<<"1) In the same bed as you\n2) In the back yard\n3) Somewhere in the Jungle \n\n";

	//Promt for sleepMenu
	cout<<"Enter your choice here: ";
	cin>>sleepMenu;

	cout<<endl<<endl;


score3 = sleepMenu *30;

totalScore += score3;

	if (sleepMenu == 1)
	{
	cout<<petName<<" feel asleep watching TV! "<<petName<<" is now "<<totalScore<<"% happy!\n\n";
	}


	else if (sleepMenu == 2)
	{
	cout<<petName<<" is having fun checking out the full moon."<<petName<<" is now "<<totalScore<<" % happy!\n";	
	}


	else if (sleepMenu == 3)
	{
	cout<<petName<<" got to meet some great friends out in the wild! "<<petName<<" is now"<<totalScore<<" % happy!\n\n\n";
	}

else
	{
	cout<<"Invalid, You must choose a choice from 1-3.\n";
	}

}while (sleepMenu !=1 && sleepMenu !=2 && sleepMenu !=3);


//Calculate random Numbers

random = rand()%100 + 1;

totalScore += random;

	cout<<name<<","<<petName<<" is having dreams about how his day went it has gained "<<random<<" % happyness!\n\n\n";


random2 = rand()%20 + 1;

	cout<<"Somethings may not have gone the way "<<petName<<" expected.In the middle of the night it had to wake up for a stretch and lost "<<random2<<"% happyness.\n\n";

totalScore -= random2;

cout<<"You have managed to make your pet "<<totalScore<<" % happy!\n\n";

cout<<"Your score is "<<totalScore<<"% "<<endl;





if(totalScore>highest)

{
outfile.open("highscore.txt", ios::out);

outfile<<name<<"\t"<<totalScore<<endl;
outfile.close();
cout<<"You have a new high score!!\n\n";

}




else
{
	cout<<" Sorry!"<<name<<" You did not earn a high score\n\n";

	cout<<"The pevious highscore was "<<highest<<"% by "<<highName<<".\n"<<endl;
	
}




}

else if (mainMenu == 3)

	{

		cout<<"Have a nice day "<<name<<"!!"<<endl; 
	}

else
	{
	cout<<"Invalid . You must choose a choice from 1-3 from the main menu.";
	}


}while (mainMenu !=3);



return 0;

}


//function defenitions

void PrintIntro()
{

cout<<"\n\n**************WELCOME TO MY PET GAME THIS IS MY PET GAME***********\n\n\n";

}






	
