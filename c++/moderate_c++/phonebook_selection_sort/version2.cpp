
//  File.cpp
//  Exercie 18
//  Created by James Moore on 9/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

/*
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

struct NewEntry
{
	string firstn;
	string lastn;
	string pnumber;
};





void selectionSort(PhoneEntry  array [ ] , int size, int menuchoice);


void selectionSort(NewEntry  array [ ] , int size, int menuchoice);

int main() 
{
	string line, secondline, s ;
	ifstream infile;
	string fileName;
    
    
    
    cout<<"\n\n****************************** LIST PROGRAM**************************"<<endl;
    
    cout<<"Would you like to create a new text file or use an existing one?"<<endl;
        
    
        
   
    int filechoice = 0 ,howmany = 0 ; 
    cout<<"1)Enter data to a new file"<<endl;
    cout<<"2) Use an existing file"<<endl;
    
    cout<<"Enter your choice here : ";
    cin>>filechoice;
    

    
   if (filechoice == 1 )
   {
            
            ifstream infile;
            ofstream outfile; 
            
            
            
            cout<<" You Have chosen to enter data into a new file.  Your new file name is : new.txt"<<endl<<endl;
            
            cout<<"How many peoples information would you like to input data for? " ;
            
            //dynamically allocate memory space to store  however many entries the user wants to make 
            
            cin>>howmany;
            
            // create dynamic array to hold data
            
            NewEntry *n = new NewEntry[howmany];
            
            assert(n!=NULL);
            
            cout<<"Now enter the information  to be put in the list."<<endl;
            
            for( int i = 0 ; i < howmany ; i ++ )
            {
                
                cout<<" Enter the information for person # "<<i<<"."<<endl;
                cout<<"First name: ";
                cin>>n[i].firstn;
                cout<<endl;
                cout<<"Last name : " ;
                cin>>n[i].lastn;
                cout<<"Phone number XXX-XXXX :";
                cin>>n[i].pnumber;
                
            }
            
            //write all the data to the file
            //open file for output
            outfile.open("new.txt",ios::out);
            
            for ( int i  = 0 ; i < howmany ; i ++ )
            {
                outfile<<n[i].firstn<<" "<<n[i].lastn<<" "<<n[i].pnumber<<endl;
            }
            outfile.close();
            
            if(!outfile)
            {
                cout<<"DID NOT WRITE TO FILE!"<<endl;	
            }
            
       
            cout<<" The data in the file is as follows :\n\n\n******************************\n\n";
            //read in data from file
       
       int counter = 0;
            
            infile.open("new.txt", ios::in);
            
            while (getline(infile,secondline) )
            {
                cout<<secondline<<endl;
                counter ++;
                
            }
            infile.close();
            
       cout<<"There are "<<counter<<"lines of data in this  file."<<endl;
       
       
       
       cout<<"\n\n\nWhat would you like to do ? "<<endl<<endl;
    
        cout<<"1)Search for  a persons record by first name, last name, or number.\n2)Sort out the list of data.";
        int searchmenu = 0 ;
       cin>>searchmenu;
       
      
       
       switch (searchmenu) {
               
           case 1:
           {
               string *l = new string[howmany];
               
               assert(l!=NULL);
               
               string secondsearchItem;
               cout<<"Enter a whole  or apart of a name/phone number to search:"<<endl;
              cin>>secondsearchItem;
               
                infile.open("new.txt", ios::in);
               
               for( int i = 0 ; i < howmany; i ++ )
               {
                   getline(infile,l[i]);
                   //or you could also do *(p+i) = line after that 
               }
               infile.close();
           
               
               size_t found;
               
                       
               // if it is found it will display 
               for
                   (int i = 0 ; i < howmany; i ++)
               {
                   found = l[i].find(secondsearchItem);
                   if(found != string ::npos)
                   {
                       cout<<l[i]<<endl;
                   }
               }
               break;
       }
            case 2:
               
           {
               infile.open("new.txt", ios::in);               
               for (int i= 0; i < howmany ; i ++)
               {
                   infile>>n[i].firstn;
                   infile>>n[i].lastn;
                   infile>>n[i].pnumber;
               }
               infile.close();
               //sort  each in menu
               
               int secondmenuselection = 0 ;
               
               
               cout<<"Choose an option from the menu."<<endl;
               cout<<"1)Sort by last name."<<endl;
               cout<<"2)Sort by first name."<<endl;  
               cout<<"3)Sort by phone number."<<endl;
               
               cout<<"Enter your choice:";
               cin>>secondmenuselection;
               
               
             selectionSort(n, howmany, secondmenuselection);
               
               //Display the array after it is sorted.
               
               cout<<"This is the list Sorted :"<<endl;
               
               for (int i = 0 ; i < howmany; i ++)
                   
               {
                   cout<<n[i].firstn<<" "<<n[i].lastn<<" "<<n[i].pnumber<<endl;
               }
               
               cout<<"blah"<<endl;
               
       }

            break;
               

           default:
           {
               cout<<"invalid"<<endl;
               
           }
               break;
               
       }
       
       
       
       
       
       
       
   }
    
   else if ( filechoice == 2)
   {
    
    
       
	//Promt user to enter the name of a file to display 
	cout << "enter the name of the input file: ";
       cin>>fileName;
       
       
       
       
    
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
    
   }
            
 
   else {
       cout<<"Invalid Choice."<<endl;
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

void selectionSort(NewEntry array[], int size, int menuchoice)
{
    int startScan , minIndex   ;
    string minValue ;  
    
    int menu = menuchoice  ; 
    switch (menu) {
        case 1:
            for (startScan = 0; startScan < (size - 1); startScan++)
            {
                minIndex = startScan;
                minValue = array[startScan].lastn;
                
                for(int index = startScan + 1; index < size; index++)
                {
                    if (array[index].lastn < minValue)
                    {
                        minValue = array[index].lastn;
                        minIndex = index;
                    }
                }
                array[minIndex].lastn = array[startScan].lastn;
                array[startScan].lastn = minValue;
            }
            
            break;
            
        case 2:
            for (startScan = 0; startScan < (size - 1); startScan++)
            {
                minIndex = startScan;
                minValue = array[startScan].firstn;
                
                for(int index = startScan + 1; index < size; index++)
                {
                    if (array[index].firstn < minValue)
                    {
                        minValue = array[index].firstn;
                        minIndex = index;
                    }
                }
                array[minIndex].firstn = array[startScan].firstn;
                array[startScan].firstn = minValue;
            }
            
            break;
        case 3:
            
            
            for (startScan = 0; startScan < (size - 1); startScan++)
            {
                minIndex = startScan;
                minValue = array[startScan].pnumber;
                
                for(int index = startScan + 1; index < size; index++)
                {
                    if (array[index].pnumber < minValue)
                    {
                        minValue = array[index].pnumber;
                        minIndex = index;
                    }
                }
                array[minIndex].pnumber = array[startScan].pnumber;
                array[startScan].pnumber = minValue;
            }
            
            break;
            
            
            
            
        default:
            
            
            
            break;
            
    }


}
*/

