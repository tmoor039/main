//
//  main.cpp
//  pg1099 problem # 12
//
//  Created by James Moore on 10/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "inventoryclass.h"
#include "stackheader.h"


using namespace std;

void Createitem( Inventory &item);


int main()
{
    
    
    int menu = 0;
    Inventory p;
    Inventory tmp;// to hold part that will be getting popped
    InventoryStack myStack(100);//stack with 100 individual inventory objects (parts)
    
   
        
   
    
    do {
        
        cout<<"What would you like to do?\n\n"<<endl;
        cout<<"1)Add a part from the inventory."<<endl;
        cout<<"2)Remove a part form the inventory.";
        cout<<"\n3)Exit.\n\n"<<endl;
        
        cout<<"Enter your choice here: ";
        cin>>menu;
        
     
    switch (menu)
    {
            
        case 1:
            
            cout<<"You have chosen to add a part to the iventory."<<endl;
                
                Createitem(p);
                
                myStack.push(p);
                
                break;
            
            case 2:
            
            
               
                myStack.pop(tmp);
           
                tmp.displayfunctions();
                
        
                break;
       
            break;
            
        case 3:
            cout<<"Exiting"<<endl;
            while (! myStack.isEmpty()) {
                myStack.pop(tmp);
                tmp.displayfunctions();
            }
        
            
        break;
               
        default:
                cout<<"Invalid"<<endl;
                exit(EXIT_FAILURE);
           
            break;
        }    
    
   } while (menu!=3);
    return 0;
   
                
}


void Createitem ( Inventory &item)
{
    int serialnum,mandate,lotnum;
    
    cout<<"What is the serial number for the part?";
    cin>>serialnum;
    cout<<"\nWhat is the manufacturing date of the part";
    cin>>mandate;
    cout<<"\nWhat is the lot number of the part";
    cin>>lotnum;
    
    item.setlotnumber(lotnum);
    item.setmanufacutredate(mandate);
    item.setserialnumber(serialnum);
    //assign values
    
    //create an array for those items
    
    // item = new Inventory(serialnum, mandate, lotnum);
    //aseert(item !=NULL);
    
    
}