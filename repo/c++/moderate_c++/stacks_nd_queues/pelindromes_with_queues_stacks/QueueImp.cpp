


#include <iostream>
#include "CharQueue.h"

using namespace std;

//***************************************************************
// This constructor creates an empty queue of a specified size. *
//***************************************************************

CharQueue::CharQueue(int s)
{
    queueArray = new char[s];
    queueSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}

//***************************************************************
// Copy constructor                                             *
//***************************************************************

CharQueue::CharQueue(const CharQueue &obj)
{
    // Allocate the queue array.
    queueArray = new char[obj.queueSize];
    
    // Copy the other object's attributes.
    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;
    
    // Copy the other object's queue array.
    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

//***************************************************************
// Destructor                                                   *
//***************************************************************

CharQueue::~CharQueue()
{
    delete [] queueArray;
}

//***************************************************************
// Function enqueue inserts a value at the rear of the queue.   *
//***************************************************************

void CharQueue::enqueue(char letter)
{
    if (isFull())
        cout << "The queue is full.\n";
    else
    {
        // Calculate the new rear position
        rear = (rear + 1) % queueSize;
        // Insert new item
        queueArray[rear] = letter;
        // Update item count
        numItems++;
    }
}

//***************************************************************
// Function dequeue removes the value at the front of the queue * 
// and copies t into num.                                       *
//***************************************************************

void CharQueue::dequeue(char &letter)
{
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        // Move front
        front = (front + 1) % queueSize;
        // Retrieve the front item
        letter = queueArray[front];
        // Update item count
        numItems--;
    }
}

//***************************************************************
// isEmpty returns true if the queue is empty, otherwise false. *
//***************************************************************

bool CharQueue::isEmpty() const
{
    bool status;
    
    if (numItems)
        status = false;
    else
        status = true;
    
    return status;
}

//***************************************************************
// isFull returns true if the queue is full, otherwise false.   *
//***************************************************************

bool CharQueue::isFull() const
{
    bool status;
    
    if (numItems < queueSize)
        status = false;
    else
        status = true;
    
    return status;
}

//*****************************************************************
// clear sets the front and rear indices, and sets numItems to 0. *
//*****************************************************************

void CharQueue::clear()
{
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}