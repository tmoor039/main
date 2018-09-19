//
//  main.cpp
//  Josephus
//
//  Created by TJ Moore on 11/12/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.


#include<iostream>
#include "File.h"
#include<fstream>
#include<cstdlib>
#include<cassert>


using namespace std;

int main()
{
    //declare variables
    int  count = 0, number = 0;
    string name,fileName;
    
    //declare new NameLis Object
    NameList list;
    
    ifstream infile;
    
    cout<<"Enter the name of the file with the names to run the Josephus Program: ";
    cin>>fileName;
    cout<<endl;
    
    
    infile.open(fileName.c_str());
    
	// If not found, Program will end.
	if (!infile)
	{
		cout <<"Error: cannot open Josepus.txt for reading."<<endl;
		cout << "Not found. Program Abort."<<endl;
		exit(EXIT_FAILURE);
	}
    
    
    //Read in first number
    cout<<"\n\nReading in the first line of the file which should be a number.....\n\n";
    infile>>count;
    
    //Read in Remaining lines with names and append them to the list
    
    while(getline (infile,name))
    {
        list.appendNode(name);
        
        number ++;
    }
    
    if (number == list.getsize())
    {
        list.deleteNode("");
        cout<<"The list have been succefully created.\n";
    }
   
  
    cout<<"\nThe items in the list are as follows:\n\n";
    
    list.displayList();
    
    
    infile.close();
    
    infile.open("Josephus.txt",ios::in);
    
    infile>>count;
    
    //create an array with all the names and find the shortest name
    
    string *p = NULL;
    
    p = new string[number];
    
    for ( int i = 0; i < number; i ++)
    {
        getline(infile,*(p+i));
        
    }
    
    infile.close();
    
    //determine the person  with the shortest name. assuming the files first line was discarded.
    
    string shortestname = *(p+1);
   
    string x = "";
    
    for (int i = 1 ; i < number; i ++)
    {
            x = *(p+i);
        
        while (shortestname.length() > x.length())
        {
            shortestname = x;
        }
    }
    
    delete [] p ;
    
    cout<<"We have the determined that the shortest name in the list is :\n\n"<<shortestname<<endl<<endl;
    
 
    cout<<"\n\nHERE WE GOOO!!!! RUNNING THE JOSEPHUS FUNCTION.......\n\n";
    
    list.JosephusFunction(shortestname, count);
    
    
    cout<<"\n\nGoodBye.\n";
    
    
    return 0;
    
}