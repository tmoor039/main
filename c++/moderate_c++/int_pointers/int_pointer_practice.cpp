
//  main.cpp
//  Gas
//Created by Tiago Moore on ${date}.
//Copyright (c) ${year} __TJPrograms__. All rights reserved.

// This program will calculate  the users vehicle gas milage
//Tiago Moore
//Jan,28, 2012

#include<iostream>
#include<iomanip>
#include<cassert>
using namespace std;

// function prototypes
//return type : pointer
//parameters: one int 
//purpose: to dynamically allocate enough memory for the amout of days of which the user wants to calculate. 
int* numberOfDays(int size);

int main()

{
	int days = 0 ;
    
    
	double miles = 0.00 , gallon = 0.00, total = 0.00, gallonprice = 0.0, gasprice = 0.0 , mileprice = 0.0 ;
    
    cout<<"##################################################################\n\n";
	cout<<"\tWelcome to my gas mileage program!!"<<endl<<endl;
    
    
	cout<<"How many gallons of gas can your car's tank hold?:  ";
	cin>>gallon;
    
	cout<<"With "<<gallon<<" gallons of gas, how many miles can your car be driven?  ";
	cin>>miles;
    
	total = miles / gallon;
	
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"Your car will drive :"<<setw(23)<<total<<" miles on every gallon!"<<endl;
    
    
	cout<<"Enter the price of gas per gallon: ";
	cin>>gallonprice;
    
	gasprice = gallonprice * gallon;
    
	cout<<"It will cost you "<<gasprice<<" dollars to fill up your car with gas!\n\n"<<endl;
    
    
    
	mileprice = gallonprice/total;
    
    
    
	cout<<"For every mile you drive you spend $ "<<mileprice<< " cents\n\n"<<endl;
	

	cout<<"How many miles days of gas expences would you like to calculate? ";
	cin>>days;
    
      int x = 0 ;
    int *pointer = numberOfDays(days);
    
    for (int i = 0; i < days; i ++) 
    {
      
        
        cout<<"How many miles  were driven on day " <<i<<"? : ";
        cin>>*(pointer+i);  
    
      x += *(pointer+i);
    }
    
    cout<<"These are the values currenty in the pointer array"<<endl;
    
    for (int i = 0; i < days ; i ++)
    {
        cout<<*(pointer+i)<<" ";
    }
    
    
	cout<<"You spent "<<mileprice*x<<" dollars in "<<days<<" days!\n\n"<<endl;
    
    
    return 0;
    
}


int *numberOfDays(int size)

{
    int *p = NULL;
    
    p = new int[size];
    
    assert(p!= NULL);
    
    return p ;
    
}

