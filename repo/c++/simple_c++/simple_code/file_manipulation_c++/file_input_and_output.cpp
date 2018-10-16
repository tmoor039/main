// This program will read data form file football.txt

#include<fstream>
#include<iostream>

using namespace std;

int main()
{

	string name, team, position ; 
	int age;
	float salary;

	ifstream infile;

	//declare a file pointer for output
	ofstream outfile;

	infile.open("football.txt", ios::in);

	if(!infile)
	cout<<"File not found!!\n";

	getline(infile,name);

	infile>>salary;

	infile>>age;

	infile.ignore(2, '\n');

	getline(infile,team);
	
	getline(infile,position);

	

	infile.close();
	//open file "footballformatted.txt" for output
	outfile.open("footballformatted.txt",ios::out);

	if(!outfile)
	cout<<"File not found!\n";

	//write the formatted output to file
	outfile<<"Player Name:\t"<<name<<endl;

	outfile<<"Salary:\t"<<salary<<endl;
	
	outfile<<"Age:\t"<<age<<endl;

	outfile<<"Team:\t"<<team<<endl;

	outfile<<"Position\t"<<position<<endl;

	cout<<name<<endl;
	cout<<salary<<endl;
	cout<<age<<endl;
	cout<<team<<endl;
	cout<<position<<endl;

	


	//close file
	outfile.close();


return 0;

}



	




