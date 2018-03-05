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

//return type: string
//parameters: none
//Purpose: This function prompts the user for a name and returns the name.
string GetName();

//return type: int
//parameters: 1 string
//purpose: this functions accepts one parameter, the users name and promts for the main menu choice
int MenuChoice(string &name,int &choice) ;

//return type:void
//parameters: none
//purpose: displays rules of the game to the user
void DisplayRules();

//return type : float
//parameters: 2 floating scores
//purpose :this function  adds a random value  to a value 
float Random( string name, string pet);

//return type : float
//parameters: 2 floating scores
//purpose :this function  subtracts a random value  to a value 
float Random2(string name, string pet);


//return type : float
//parameters 2: 2 accepts two values from an array and adds them together
//purpose: returns the total of the two values added
float AddScores(float&, float&);

// return type : void
//parameters : none
// purpose : press enter to continue for user friendlyness
void Enter();


//return type: void
//parameters : 2 arrays one of scores and one of names
// purpose: This function writes the values of the arrau to a datafile called "highscore.txt"
void WriteData(string[] , float[], string ,float);





int main()

{


//declare array of floats , size 4, initialize all values to 0
float score[5] = {0};



//declare parallel arrays for Highscore and Playername

string NameArr[3] ;
float HighScore[] = {0,0,0};


//declare parallel arrays 

//Declare and initialize variables 

int  mainMenu = 0 , petMenu = 0 , playMenu = 0 ,  sleepMenu = 0, friendMenu = 0 ;
float random = 0 ,random2 = 0.0 , highest = 0;
string name , petName, highName;

//seed random number genorator
srand(time(NULL));


//declare file pointer for input
ifstream infile;

// decalre file pointer for output

ofstream outfile;

//INTRO

	PrintIntro();
	
	Enter();

//call function to store users name in variable name

	cout<<"\n\nWelcome, what is your name?";
	name = GetName();

do
{
	//display mainMenu	

	MenuChoice(name, mainMenu);

 	//if statements for Main menu choice

	if (mainMenu == 1)

	{
		//call function to display rules
		DisplayRules();
	}

	else if (mainMenu == 2)
	{

//open file highscore.txt for input
	infile.open("highscore.txt",ios::in);
//read in file data for all of array
	for (int i = 0 ; i < 3 ; i ++)
	{
	infile>>NameArr[i]>>HighScore[i];
	infile.close();
	}




	//Display Message
	cout<<"You have choosen to play the game! Now make sure you dont have an angry pet running around! \n\n";
	
	Enter();
do 
{
	//cin ignore for petname string
	cin.ignore(5,'\n');

//Promt for petName
	cout<<"What would  you like to name your pet? ";
	petName = GetName();

//display menu petMenu
	cout<<"Choose the pet you would like to play with.\n\n";

	cout<<"1)Dog\n2)Cat\n3)Monkey\n\n";

//promt for petmenu choice
	cout<<"Enter your choice here: ";
	cin>>petMenu;

	cout<<endl;

score[0] = petMenu * 32;

score[4] = score[0];

//if statements for pet choice

	if (petMenu == 1)
	{
	cout<<"You have choosen to play with a dog it is" <<score[4]<<"% happy!\n\n\n";
	}
	
	else if (petMenu == 2)
	{
	
	cout<<"You have choose to pay with a Cat, it is "<<score[4]<<" % happy!\n\n\n";

	}

	else if (petMenu == 3 )
	{


	cout<<"You have choosen to play with a Monkey!,"<<petName<<" is "<<score[4]/3<<" % happy!\n\n\n";	

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


score[1] = playMenu *20;

score[4] += score[1];

//create if staments for playMenu
	

	if (playMenu == 1)
	{
	cout<<"You choose to give "<<petName<<" something yummy to eat."<<petName<<" is now "<<score[4]<<"% happy.\n";
	}

	else if (playMenu == 2)
	{
	cout<<"You choose to give "<<petName<<" something to play with! This will keep him occupied for some hours!" <<petName<<" is now "<<score[4]<<" % happy.\n\n\n"; 

	}

	
	else if (playMenu == 3)
	{

	cout<<"You choose to give "<<petName<<" a bath! Now it smells like fresh strawberrys!It is now "<<score[4]<<" % happy.\n\n";
	
	}
	else
	{
	
	cout<<"Invalid ! you must choose a an activity from 1-3.\n";
	}

}while (playMenu !=1 && playMenu !=2 && playMenu !=3);





//Display fourth Menu


do
{

	cout<<"Your pet is lonley and needs a friend. Choose the type of animal you would like to have in the house with "<<petName<<"\n\n";

	cout<<"1)A Tiger\n2)A Turtle\n3)A Hamster\n\n";

	//Promt for playMenu
	cout<<"Enter your choice here: ";
	cin>>friendMenu;

	cout<<endl;


score[5] = friendMenu *43;

score[4] += score[5];

//create if staments for playMenu
	
	if (friendMenu == 1)
	{
	cout<<"You choose to buy a Tiger! "<<petName<<" is scared and wont leave your room."<<petName<<" is now"<<score[4]<<" % happy.\n";
	}

	else if (friendMenu == 2)
	{
	cout<<"You have purchased a turtle! Everytime "<<petName<<" comes close it hides inside its shell! Your pet is fascienated by !" <<petName<<" is now "<<score[4]<<" % happy.\n\n\n"; 

	}

	
	else if (friendMenu == 3)
	{

	cout<<"There is a Ramster running around the house! "<<petName<<"  seems to get along with it quite well they are playing hide and seek. It is "<<score[4]<<" % happy.\n\n";
	
	}
	else
	{
	
	cout<<"Invalid ! you must choose one of the animals listed in choices 1-3.\n";
	}

}while (friendMenu !=1 && friendMenu !=2 && friendMenu !=3);

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


score[2] = sleepMenu *30;

score[4] += score[2];

	if (sleepMenu == 1)
	{
	cout<<petName<<" feel asleep watching TV! "<<petName<<" is now "<<score[4]<<"% happy!\n\n";
	}


	else if (sleepMenu == 2)
	{
	cout<<petName<<" is having fun checking out the full moon."<<petName<<" is now "<<score[4]<<" % happy!\n";	
	}


	else if (sleepMenu == 3)
	{
	cout<<petName<<" got to meet some great friends out in the wild! "<<petName<<" is now "<<score[4]<<" % happy!\n\n\n";
	}

else
	{
	cout<<"Invalid, You must choose a choice from 1-3.\n";
	}

}while (sleepMenu !=1 && sleepMenu !=2 && sleepMenu !=3);


//call function to Calculate random Numbers and store it in score array 3

score[4] += Random(name, petName);

score[4] -= Random2(name, petName);



cout<<"You have managed to make your pet "<<score[4]<<" % happy!\n\n";

cout<<"Your score is "<<score[4]<<"%."<<endl;





WriteData(NameArr,HighScore,name,score[4]);

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


void DisplayRules()

{


cout<<"****************************************RULES***********************************************\n\n";

	 cout<<"First you will need to Choose your favorite pet. After pet has been chosen you will select if you want to give the pet food, drink , play with the pet  and also where you will put your pet to sleep everynight.You will choose what you want to give your pet and at the end your pets happyness percentage will be displayed.\n\n";


}

string GetName()

{
	string name;

	cout<<"\n\nEnter name here: ";

	getline(cin,name);
	
	return name;
}
	

int MenuChoice(string &username, int &choice) 
{
	
//display mainMenu	

	cout<<"Hello "<<username<<", please choose an option from the following menu.\n\n";

	cout<<"1)See Rules\n2)Play Game\n3)Exit\n\n";

//Promt for mainMenu choice
	cout<<username<<"Enter your choice here: ";
	cin>>choice;
	
	cout<<endl;

}

float Random(string name, string pet)
{

	float totalScore = 0;
	const float random = rand()%100 + 1;

	totalScore += random;



cout<<name<<","<<pet<<" is having dreams about how his day went it has gained "<<random<<" % happyness!\n\n\n";


	return totalScore;
}

float Random2(string name, string pet)
{

	float totalScore = 0;
	const float random = rand()%20 + 1;;

	totalScore += random;


	cout<<"Somethings may not have gone the way "<<pet<<" expected.In the middle of the night it had to wake up for a stretch and lost "<<totalScore<<"% happyness.\n\n";

return totalScore;
}

	


void Enter()
{

	cout<<"Press enter to continue... ";
	cin.get();	
}








void WriteData(string NameArray[], float FinalScoresArray[], string name, float playerscore)
{
	
	ofstream outfile;

if(playerscore>FinalScoresArray[0])
	{
	FinalScoresArray[2] = FinalScoresArray[1];
	 NameArray[2] =  NameArray[1];
	FinalScoresArray[1] =FinalScoresArray[0];
	NameArray[1] = NameArray[0];
	FinalScoresArray [0] = playerscore;
	NameArray[0] = name;
	cout<<"You have a new high score!!\n\n";
	}

else if (playerscore > FinalScoresArray[1])
{
	FinalScoresArray[2] = FinalScoresArray[1];
	 NameArray[2] =  NameArray[1];
	FinalScoresArray [1] = playerscore;
	NameArray[1] = name;
	cout<<"Second Score"<<endl;
}

else 
{
	FinalScoresArray[2] = playerscore;
	
	NameArray[2] = name;
	cout<<"third score"<<endl;
}

	

outfile.open("highscore.txt", ios::out);

	for (int i = 0; i < 3; i ++)
	{
	outfile<<NameArray[i]<<"\t"<<FinalScoresArray[i]<<endl;
	}



//close file
outfile.close();


}


	
