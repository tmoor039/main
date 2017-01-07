//
//  Header.h
//  FileCompare
//
//  Created by James Moore on 10/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#ifndef CharQueue_CharQueue_h
#define CharQueue_CharQueue_h

class CharQueue
{
private:
    char *queueArray;  // Points to the queue array
    int queueSize;    // The queue size
    int front;        // Subscript of the queue front
    int rear;         // Subscript of the queue rear
    int numItems;     // Number of items in the queue
public:
    // Constructor
    CharQueue(int);
    
    // Copy constructor
    CharQueue(const CharQueue &);
    
    // Destructor
    ~CharQueue();
    
    // Queue operations
    void enqueue(char);
    void dequeue(char &);
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};
#endif

