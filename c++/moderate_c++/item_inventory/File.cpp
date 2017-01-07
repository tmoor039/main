//
//  File.cpp
//  Money
//
//  Created by James Moore on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<cassert>
#include"Inventory.h"
#include"Money.h"
#include<cstdlib>
#include<fstream>


using namespace std;

int main()
{
    //declare variables.
    
    int menuchoice = 0 , howmany = 0 , amountbought = 0 ;

   
    
    double price, payment, salestax ;    
    const double TAX = .06;

    char buychoice;
    
    InventoryItem Myitems[100];
    
    Money saleAmount;
    Money tax;
    Money total;
    Money paid;
    
    
    
    //Promt the user to Enter some items information
    
    cout<<"How many Items would you like to add to your Inventory? : ";
    cin>>howmany;
    
   
    
    //For loop to Assign values to items
    for (int i = 0 ; i < howmany ; i ++)
    {
        string name;
        double cost;
        int number;
        
        cout<<"What is the name of  item # "<<i+1<<"? ";
        cin>>name;
        
        
        cout<<"What is the cost of item # "<<i+1<<" ? ";
        cin>>cost;
        
        cout<<"How many units are available for item # "<<i+1<<" ? ";
        cin>>number;
        
        Myitems[i].setDescription(name);
        Myitems[i].setCost(cost);
        Myitems[i].setUnits(number);
    }

    //Display Entire inventory.
    cout<<"\n\nThe Items in your Inventory are as follows: "<<endl<<endl;
    
    for (int i = 0 ; i < howmany; i ++)
    {
        Myitems[i].display();
    }
    
    
    bool buy = false;
    
    do 
    {
        
    cout<<"Would you like to buy an Item? (y/n)";
       cin>> buychoice;
        
        if (buychoice == 'y')
        {
            buy = true;
            
            cout<<"Choose an item you wish to buy. \n\n"<<endl;
            
            do
            {
                //Promt the user to choose an item
                for (int i = 0 ; i < howmany; i ++)
                {
                    cout<<"Enter "<<i+1<< " to buy "<<Myitems[i].getDescription()<<"."<<endl;
                }    
                
                cout<<"\nEnter your choice here: "<<endl;
                cin>>menuchoice;
                
                if (menuchoice < 0 || menuchoice >howmany)
                {
                    cout<<"Invalid Choice."<<endl;
                }
                
            }while (menuchoice < 0 || menuchoice >howmany);
            
         do 
         {
            //Promt for amount of items bought
             cout<<"How many items would you like to buy? There are "<<Myitems[menuchoice-1].getUnits()<<" items available.";
            cin>>amountbought;
            
            if (amountbought > Myitems[menuchoice-1].getUnits())
            {
                cout<<"Invalid.Not enough Items.Below are the number of units available."<<endl;
                cout<< Myitems[menuchoice-1].getUnits();
            }
            
         } while (amountbought > Myitems[menuchoice-1].getUnits());
             
            
                        //update the item the user picked
            
            cout<<"The number of "<<Myitems[menuchoice-1].getDescription()<<" units are being updated..\n";
                
            Myitems[menuchoice-1].setUnits(Myitems[menuchoice-1].getUnits()-amountbought);
          
            
            
            //update the number of units
                       
            price = Myitems[menuchoice-1].getCost() *amountbought;
            
            //DISPLAY  the total cost.
            
            cout<<"The total retail price for your items bought is $"<<price<<endl;
            
            
            cout<<"\n\nStoring amount in private member function..."<<endl;
            
            //Store that amount in private member function
            
            saleAmount.addamount(price);
            

        }
        
        else 
        {
            
            if  (saleAmount.getamount() > 0 )
            {
            cout<<"We have to add the salestax to your total!\n"<<endl;
            cout<<"Creating and adding sales tax to your total\n"<<endl;
            
            salestax = TAX * price;
            
            tax.setamount(salestax);
            //Add salestax to total amount
            
            saleAmount.addamount(tax);
            
            do 
            {
                
                cout<<"\nYour final total with tax is $"<<saleAmount.getamount()<<endl;
                
                cout<<"Enter the amount of the payment: ";
                cin>>payment;
                
                if (payment < saleAmount.getamount()) {
                    cout<<"\nInvalid. The amount is not paid in full.\n\n";
                    
                }
                
            }
            while(payment < saleAmount.getamount());
            
            paid.setamount(payment);
            
            //calculate
            
            
            paid.subtractamount(saleAmount);
            
            
            //Display the total change
            
            cout<<"Your change is as follows : \n"<<endl;
            
            paid.displayamount();
            
            }
            
            else
            cout<<"Goodbye\n";
            exit(EXIT_SUCCESS);
        }
    
    }
    while(buy != false);
    
    

    
    
    
    
        
    return 0;
}