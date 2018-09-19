//
//  File.cpp
//  Josephus
//
//  Created by TJ Moore on 11/12/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include <iostream>  // For cout  and NULL
#include "File.h"
using namespace std;

//**************************************************
// appendNode appends a node containing the        *
// name parameter pased into its name member, to the end of the list.   *
//**************************************************

void NameList::appendNode(string name)
{
    ListNode *newNode;  // To point to a new node
    
    // Allocate a new node and store name there.
    newNode = new ListNode;
    newNode->name = name;
    newNode->next = NULL;
    
    // If there are no nodes in the list
    // make newNode the first node and the last node.
    // and make the end->next points to head, so that it is a circle.
    if (!head) {
        head = newNode;
        end = newNode;
        end->next = head;
    }
    else  // Otherwise, insert newNode at end and adjust end pointer properly.
    {
        // Insert newNode as the last node.
        end->next = newNode;
        newNode->next = head;
        end = newNode; // set end point to the last node
    }
    numberOfNodes++; // increment the number of nodes by 1 after appending the new node to the list
}

//**************************************************
// displayList shows the name                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void NameList::displayList() const
{
    ListNode *nodePtr;  // To move through the list
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    // While nodePtr is not equal to the end node, traverse
    // the list.
    cout << endl;
    while (nodePtr != end)
    {
        // Display the name in this node.
        cout << nodePtr->name << endl;
        
        // Move to the next node.
        nodePtr = nodePtr->next;
    }
    // now nodePtr is equal to end, display the data of the last node
    cout << nodePtr->name << endl;
    cout << endl;
    
    
}

//**************************************************
// The deleteNode function searches for a node     *
// with the name parameter as its name. The node,  *
// if found, is deleted from the list and from memory.*
//**************************************************

void NameList::deleteNode(string name)
{
    ListNode *nodePtr = NULL;       // To traverse the list
    ListNode *previousNode = NULL;  // To point to the previous node
    
    // If the list is empty, do nothing.
    if (!head) {
        cout <<endl <<  "the list is empty."<<endl;
    } else if (head == end) { // if the list has only one node
        // Determine if the only node is the one to be deleted.
        if (head->name == name) {
            cout <<endl << head->name << " is deleted from the list."<<endl;
            numberOfNodes--;
            delete head;
            head = NULL;
            end = NULL;
        } else { // the name is not in the list
            cout <<endl << name <<" is not in the list."<<endl;
        }
    } else { // the list has at least two nodes
        // Initialize nodePtr to head of list
        nodePtr = head;
        
        // Skip all nodes whose name member is
        // not equal to name.
        while (nodePtr != end && nodePtr->name != name) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr != end) { // nodePtr->name must be equal to name
            cout <<endl << nodePtr->name << " is deleted from the list."<<endl;
            numberOfNodes--;
            if ( previousNode == NULL) {
                // the previousNode never updates, that is, the loop never runs
                // it means the head is the one to be deleted.
                delete head;
                head = nodePtr->next;
                end->next = head;
            } else {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        } else {  // nodePtr is pointing to the last node
            // check whether the last node is the one to be deleted
            if (end->name == name) {
                cout <<endl << end->name << " is deleted from the list."<<endl;
                numberOfNodes--;
                delete end;
                end = previousNode;
                end->next = head;
            } else {
                cout <<endl << name << " is not in the list."<<endl;
            }
        }
    } // end of else // the list has at least two nodes
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

NameList::~NameList()
{
    ListNode *nodePtr;   // To traverse the list
    ListNode *nextNode;  // To point to the next node
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    // While nodePtr is not at the end of the list...
    while (nodePtr != end)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;
        
        // Delete the current node.
        delete nodePtr;
        
        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
    // now nodePtr is pointing to end (the last node)
    delete nodePtr;
    head = NULL;
    end = NULL;
    numberOfNodes = 0;
}

//**************************************************
// the isEmpty() function returns true is the list *
// is empty, otherwise, false.                     *
//**************************************************
bool NameList::isEmpty() const {
    return head == NULL;
}

//**************************************************
// the size() function returns the number of nodes *
// in the list.                                    *
//**************************************************
int NameList::getsize() const {
    return numberOfNodes;
}



void NameList::JosephusFunction(string n, int c)
{
    //make a pointer to move trhough the list
    ListNode *p;
    string eliminatedname;
    
    //set the pointer to the shortest name
    p = head;
    
    
    //traverst the list
    while (p->name != n)
    {
        p = p->next;
        
    }
    
    //move the node  enough times to include the starting name and delete the first person
    for ( int i = 0; i < c-1 ; i ++)
    {
        p = p->next;
        
    }
    //delete the first name (n-1) nodes away from the shortest name
    eliminatedname = p->name;
    
    cout<<"Ah how unfortunate!! " <<p->name<<" is the first person to get removed from the list !";
    
    deleteNode(eliminatedname);
    
    
    
    // set a while loop to make sure there is one  node left ( the winner)
    
    while (numberOfNodes > 1) {
        
    
            // move 5 times to the next  node and delete it
        for ( int i = 0; i < c ; i ++)
        {
            p = p->next;
            
        }
        
        eliminatedname = p->name;
        
        deleteNode(eliminatedname);
                  
    }
    
    p = head;
    
    cout<<"\n\nThe person that gets to take the horse home is : "<<p->name<<endl<<endl;
        
        }
   

