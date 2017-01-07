//
//  File.h
//  Josephus
//
//  Created by TJ Moore on 11/12/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef NAMELIST_H
#define NAMELIST_H

#include <string>
using namespace std;

class NameList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        string name;           // The name in this node
        struct ListNode *next;  // To point to the next node
    };
    
    ListNode *head;            // List head pointer: pointing to the 1st node
    ListNode *end;             // List end pointer: pointing to the last node
    int numberOfNodes;         // the number of nodes in the list
    
public:
    // Constructor
    NameList() {
        head = NULL;
        end = NULL;
        numberOfNodes = 0;
    }
    
    // Destructor
    ~NameList();
    
    // Linked list operations
    // for the hw question: Josephus problem, we do not need the insertNode() function. Therefore, I deleted it.
    void appendNode(string);
    void deleteNode(string);
    
    void displayList() const;
    bool isEmpty() const; // returns true if the list is empty
    int getsize() const; // returns the numberOfNodes in the list
    
    void JosephusFunction( string, int);
    
};
#endif
