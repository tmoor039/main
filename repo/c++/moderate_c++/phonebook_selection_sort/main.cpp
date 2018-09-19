/*
//  main.cpp
//  Exercie 18
//
//  Created by James Moore on 9/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
// Tiago Moore exercise 18 program
// JC
// 9/20/2012 10:01 am


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

void selectionSort(PhoneEntry  array [ ] , int size, int menuchoice);



int main() 
{
	string line, s ;
	
	string fileName;
    
    ifstream infile;
    
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
    
    cin.ignore(5,'\n');
	string searchItem;
	cout<<"Enter a whole  or apart of a name/phone number to search:"<<endl;
    getline(cin,searchItem);
    
    
 	size_t found;
    
    
    // if it is found it will display 
	for
        (int i = 0 ; i < size; i ++)
	{
        found = p[i].find(searchItem);
        if(found != string ::npos)
        {
            cout<<p[i]<<endl;
        }
    }
    
	
	infile.open(fileName.c_str());
	//create dynamic array to hold entries
     PhoneEntry*k = new PhoneEntry[size];
	assert(p!=NULL);
    
	for (int i= 0; i < size; i ++)
	{
		infile>>k[i].fname;
		infile>>k[i].lname;
		infile>>k[i].phonen;
	}
    	infile.close();
    //sort  each in menu
	
    int menuselection = 0 ;
    
    
    cout<<"Choose an option from the menu."<<endl;
    cout<<"Sort by last name."<<endl;
    cout<<"Sort by first name."<<endl;  
    cout<<"Sort by phone number."<<endl;
    
    cout<<"Enter your choice:";
    cin>>menuselection;
    
    
    selectionSort(k, size, menuselection);
    
    //Display the array after it is sorted.
    
    for (int i = 0 ; i < size ; i ++)
    
    {
            cout<<k[i].fname<<" "<<k[i].lname<<" "<<k[i].phonen<<endl;
    }
    
    
    
    
    
	return 0;
}

void selectionSort(PhoneEntry array[], int size, int menuchoice)
{
    int startScan , minIndex   ;
    string minValue ;  
    
    int menu = menuchoice  ; 
    switch (menu) {
        case 1:
            for (startScan = 0; startScan < (size - 1); startScan++)
            {
                minIndex = startScan;
                minValue = array[startScan].lname;
                
                for(int index = startScan + 1; index < size; index++)
                {
                    if (array[index].lname < minValue)
                    {
                        minValue = array[index].lname;
                        minIndex = index;
                    }
                }
                array[minIndex].lname = array[startScan].lname;
                array[startScan].lname = minValue;
            }

            break;
            
        case 2:
            for (startScan = 0; startScan < (size - 1); startScan++)
            {
                minIndex = startScan;
                minValue = array[startScan].fname;
                
                for(int index = startScan + 1; index < size; index++)
                {
                    if (array[index].fname < minValue)
                    {
                        minValue = array[index].fname;
                        minIndex = index;
                    }
                }
                array[minIndex].fname = array[startScan].fname;
                array[startScan].fname = minValue;
            }
            
            break;
        case 3:
           
            
            for (startScan = 0; startScan < (size - 1); startScan++)
            {
                minIndex = startScan;
                minValue = array[startScan].phonen;
                
                for(int index = startScan + 1; index < size; index++)
                {
                    if (array[index].phonen < minValue)
                    {
                        minValue = array[index].fname;
                        minIndex = index;
                    }
                }
                array[minIndex].phonen = array[startScan].phonen;
                array[startScan].phonen = minValue;
            }
            
            break;


            
            
        default:
           
            
            
            break;
 
}

}

 */
