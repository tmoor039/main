//
//  Header.h
//  Queue
//
//  Created by James Moore on 10/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Queue_Header_h
#define Queue_Header_h

// Specification file for the IntQueue class


#include<string>

using namespace std;

class StringQueue
{
private:
    string *queueArray;  // Points to the queue array
    int queueSize;    // The queue size
    int front;        // Subscript of the queue front
    int rear;         // Subscript of the queue rear
    int numItems;     // Number of items in the queue
public:
    // Constructor
    StringQueue(int);
    
    // Copy constructor
    StringQueue(const StringQueue &);
    
    // Destructor
    ~StringQueue();
    
    // Queue operations
    void enqueue(string);
    void dequeue(string &);
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};
#endif
