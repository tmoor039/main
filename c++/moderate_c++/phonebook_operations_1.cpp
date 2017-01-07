// Tiago Moore exercise 18 program
// JC
// 9/20/2012 10:01 am
// This programs count the lines of a file, opens it , and searches for a work in the line and adds the names to an array. 


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;

struct PhoneEntry
{
	string fname;
	string lname;
	string phonen;
};



int main() 
{
	string line, s ;
	ifstream infile;
	string fileName;

	//Promt user to enter the name of a file to display 
	cout << "enter the name of the input file: " <<endl;
	getline(cin, fileName);

	infile.open(fileName.c_str());

	// If not found, Program will end. 
	if (!infile)
	{
		cout <<"Error: cannot open " << fileName << " for reading."<<endl;
		cout << "Not found. Program Abort."<<endl;
		exit(EXIT_FAILURE);
	}

	int size = 0 ;

	// If it is found , the  file is opened properly and displays it 
	while (getline(infile, line) ) 
	{
		cout << line << endl;
	
	size ++;

	}
	infile.close();

	cout<<" There are :"<< size<<" lines in the file ." <<endl;

	
	string *p = new string[size];
	assert(p != NULL);

	infile.open(fileName.c_str());

	for( int i = 0 ; i < size; i ++ )
{
	getline(infile,p[i]);
	//or you could also do *(p+i) = line after that 
}
	infile.close();
//ask user to enter sth to search

	string searchItem;
	cout<<"Enter a whike/part of a name/phone number to search:"<<endl;

 	size_t found;

	for
	(int i = 0 ; i < size; i ++)
	{
	found = p[i].find(searchItem);
	if(found != string ::npos)// if it is found it will display 
	{
	cout<<p[i]<<endl;
	}
}

	
	infile.open(fileName.c_str());
	//create dynamic array to hold entries
	 *p = new PhoneEntry[size];
	assert(p!=NULL);

	for (int i= 0; i < size; i ++)
	{
		infile>>p[i].fname;
		infile>>p[i].lname;
		infile>>p[i].phonen;
	}

	//sort  each in menu
	
	infile.close();



		
	return 0;
}
