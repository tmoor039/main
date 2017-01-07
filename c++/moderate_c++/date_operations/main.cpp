//
//  main
//  Homework
//
//  Created by TJ Moore on 11/6/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    int menu = 0 , menu2 = 0;

  
    cout<<"*************************************************"<<endl;
    cout<<"Welcome to my overloaded  Date class program\n\n"<<endl;
    
    do
    {
    
    cout<<"\nWhat would you like to do? \n\n";
    
    cout<<"1)Test my program a the hard code.\n";
    
    cout<<"2)Enter data to test my program with.\n";
    
    cout<<"3)Exit.\n";
        
        cout<<"\nEnter choice: ";
        cin>>menu;
        
        
        if (menu == 1) {
            
            
            Date d1(31,5,2002);
            Date d2(1,5,2000);
            Date date;
            
            cout<<d1;
            
            
            cout<<d2;
            
            cout<<"d2 - d1  is as follows :";
            
            cout<<d2-d1<<"days difference"<<endl;
            
            cout<<"incremented d1"<<endl;
            d1++;
            
            cout<<d1;
            
            cout<<"decremente d2"<<endl;
            d2--;
            
            cout<<d2;
            
            cout<<endl;
            
            cout<<"Enter data for an object to test cin operator.";
            cin>>date;
            
            cout<<date;
            
            
            
            
        }
        
        
        
        else if (menu == 2)
        {
        cout<<"\nI have declared two Date objects for you to fill with data.\n\n";
        
        Date d3;
        Date d4;
        
        cout<<"FILL THE FIRST OBJECT WITH DATA.\n\n"<<endl;
        
            cin>>d3;
            
        cout<<"The data for the date you entered is as follows: "<<endl<<endl;
        
        cout<<d3;
     
        cout<<"\n\nFILL THE SECOND OBJECT WITH DATA\n\n";
        
            cin>>d4;
            
               cout<<"The data for the date you entered is as follows: "<<endl<<endl;
        
        cout<<d4;
        
        
            cout<<endl;
            
        do
        {
        cout<<"Which of the following operation would you like to perform with the objects?\n\n";
        
            cout<<"1) Use the -  overloaded operator\n";
            cout<<"2) Use the  prefix ++ overloaded operator.\n";
            cout<<"3) Use the postfix ++ overloaded operator.\n";
            cout<<"4) Use the prefix -- overloaded operator.\n";
            cout<<"5) use the postfix -- overloaded operator.\n";
            cout<<"6) Rewrite the data in the object using the overloaded cin operator.\n";
            cout<<"7) Display the  objects using the overloaded cout operator.";
        
            
            cin>>menu2;
        
            cout<<endl<<endl;;
            
        switch (menu2)
        {
            case 1:
            {
                cout<<" The difference between the two dates are  "<<d4-d3<<"days difference. "<<endl;
                
            
                break;
            }
            case 2:
            {
                
                cout<<"Creating another empty object.\n\n ";
                Date d5;
                
                cout<<"\n The first date you entered have been incremented ";
                d5 = ++d3;
                
                cout<<"new empty object date :"<<d5<<" first date : "<<d3<<" ";
                
                
                break;
            }
                
            case 3:
            {
                cout<<"Setting a new date to your first date for demosntration:\n\n ";
                Date d6 = d3;
                
                cout<<"incrementing.."<<endl<<endl;
                
                d6 = d3++;
                
                cout<<"new date :"<<d6<<"date you entered : "<<d3<<" ";
                

                break;
            }
                
            case 4:
            {
                
                cout<<"Creating another  empty object.\n";
                Date d7;
                
                cout<<"decrementing.."<<endl<<endl;
                
                d7 = --d3;
                
                cout<<"new object :"<<d7<<"first objected you entered date : "<<d3<<" ";
                
                
                break;
                
                
            }
                
                
            case 5:
            {
                cout<<"Setting a new date to your first date for demosntration\n\n ";
                Date d8 = d3;
                
                cout<<"Decrementing.."<<endl<<endl;
                
                d8 = d3--;
                
                cout<<"new object date :"<<d8<<"first date you entered : "<<d3<<" ";
                
                
                break;
            }
            
                
            case 6:
            {
                Date newdate;
                cout<<"Enter a new date: ";
                cin>>newdate;
                
                cout<<"New date is as follows:";
                cout<<newdate;
                
                break;
            }
                
            case 7:
            {
                cout<<d3;
                cout<<endl;
                cout<<d4;
                break;
            }
            default:
                cout<<"Invalid";
                break;
        }
        
        
        }while(menu2 != 1 && menu2!= 2 && menu2 != 3 &&menu2!=4 &&menu2 !=5 && menu2 != 6 &&menu2 !=7);
        
        }
        
        else if (menu ==3)
        {
            cout<<"goodbye."<<endl;
        }
        
        else
        {
            cout<<"invalid.";
        }
       
    }
    while (menu != 3);
    
    
    
return 0;
}