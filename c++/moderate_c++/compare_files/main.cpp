//
//  main.cpp
//  FileCompare
//
//  Created by James Moore on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Header.h"
#include<iostream>
#include<fstream>
#include<cstdlib>



using namespace std;

int main()
{

//declare variables

char letter1;
char letter2;

ifstream infile;
ofstream outfile;
    
CharQueue line1(INT_MAX);
CharQueue line2(INT_MAX);


//read in everythig in the first text file
int counter1 = 0 ;
    
infile.open("File.txt", ios::in);

    while (infile>>letter1) 
    {
        line1.enqueue(letter1);
        counter1 ++;
    }

    infile.close();
    
    cout<<"There are "<<counter1<<" charaters in File 1 "<<endl;

    // read in everything in second text file
    
    int counter2 = 0 ;
    
    infile.open("File2.txt",ios::in);
    
    
    while (infile>>letter2) 
    {
        line2.enqueue(letter2);
        counter2 ++;
    }
    
    infile.close();
    
    //Compare both the files numerically
    
    cout<<"There are "<<counter2<<" charaters in File 2 "<<endl;
    
    if (counter1 != counter2) 
    {
        cout<<"The Text in both the files are not the same!"<<endl;
        
        cout<<"The content in the first file is as follows: "<<endl;
        
        while (!line1.isEmpty()) {
            line1.dequeue(letter1);
            cout<<letter1;
        }
        cout<<endl;
        
        cout<<"The content in the second file is as follows: "<<endl;
        
        while (!line2.isEmpty()) {
            line2.dequeue(letter2);
            cout<<letter2;
        }
        cout<<endl;
        

        exit(EXIT_FAILURE);
    }
      
    
    
    else if(counter1 == counter2)
    {
        while (!line1.isEmpty() && !line2.isEmpty()) {
            line1.dequeue(letter1);
            line2.dequeue(letter2);
            
            if(letter1 != letter2)
            {
                cout<<"The contents are not the same!"<<endl;
                exit(EXIT_SUCCESS);
            }

        }
        
        cout<<"The contents are the same!"<<endl;
    }
    
    
    

    

    return 0;
}

