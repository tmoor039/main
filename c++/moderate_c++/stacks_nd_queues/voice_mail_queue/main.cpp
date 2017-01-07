//
//  File.cpp
//  Queue
//
//  Created by James Moore on 10/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Header.h"
    
    using namespace std;
    
    int main() 
    {
        StringQueue newMsgs(10);
        StringQueue oldMsgs(10);
        StringQueue oldSavedMsg(10);
        
        bool create = false;
        string message;
        string answer;
        
        do
        {
            
            cout<<"Do you want to create a new message? (y/n) ";
            cin>>answer;
            
            cin.ignore(5, '\n');
            
            if(answer == "y")
            {
                create = true;
                
                cout<<"Enter the message :";
                getline(cin,message);
                newMsgs.enqueue(message); 
            }
            
            else if (answer == "n")
            {
                cout<<endl;
            }
            
            else
            {
                cout<<"Invalid."<<endl;
            }
            
            
        }while(create != false && answer != "n");
        
        
        
        int menuchoice = 0 ;
        int secondmenuchoice;
        
        string currentmessage;
        
        do
        {
            
        
        //display the menu
        cout<<"What would you like to do?\n";
        cout<<"Play new messages.\n";
        cout<<"Play old messaged.\n";
        cout<<"Exit.\n";
        
        cout<<"Enter your choice here : ";
        cin>>menuchoice;
        
        switch (menuchoice) {
            case 1:
                while (!newMsgs.isEmpty()) {
                    newMsgs.dequeue(currentmessage);
                    cout<<currentmessage<<endl;
                    
                    cout<<"What would you like to do with this message? ";
                    cout<<"1)Save this message.";
                    cout<<"2)Delete this message.";
                    cin>>secondmenuchoice;
                    switch (secondmenuchoice) {
                        case 1:
                            
                            oldMsgs.enqueue(currentmessage);
                        
                            break;
                        case 2:
                            
                            cout<<"Deleted."<<endl;
                            
                        default:
                            cout<<"Invalid Choice.";
                            break;
                    }
                    
                }
                
                cout<<"There are no more messages."<<endl;
                
                break;
                
            case 2 :
                while (!oldMsgs.isEmpty()) {
                
                    oldMsgs.dequeue(currentmessage);
                    cout<<currentmessage<<endl; 
                    
                 
              
                    cout<<"What would you like to do\n\n";
                    cout<<"1) Save the old message.\n2)Delete the old message.\n";
                    cout<<"Enter your choice here: ";
                    cout<<"Exit.\n";
                    cout<<"Enter choice: ";
                    cin>>secondmenuchoice;
                    
                    switch (secondmenuchoice) {
                        case 1:
                            oldSavedMsg.enqueue(currentmessage);
                            cout<<"Message Saved.";
                        
                            break;
                            case 2:
                            cout<<"Message Deleted.\n";
                            
                        default:
                            cout<<"Invalid Choice.\n";
                            
                      
                    }
                    
        
                    }
                cout<<"there are no more messages\n\n";
                break;
                
                case 3:
                cout<<"Bye.";
                
                break;
                
                default:
                
                cout<<"invalid choice.";
                break;
                
        }
        
        
        }while (menuchoice!=3) ;
        
        
        
        
        
                
        
        
        
        
        
        return 0;
        
    }

    
    
  