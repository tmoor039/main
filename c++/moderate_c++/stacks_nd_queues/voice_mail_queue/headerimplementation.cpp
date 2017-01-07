
// Implementation file for the StringQueue class
#include <iostream>
#include "Header.h"
using namespace std;


StringQueue::StringQueue(int s)
{
    queueArray = new string[s];
    queueSize = s;
    front = 0;
    rear = 0;
    numItems = 0;
}


StringQueue::StringQueue(const StringQueue &obj)
{
    // Allocate the queue array.
    queueArray = new string[obj.queueSize];
    
    // Copy the other object's attributes.
    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;
    
    // Copy the other object's queue array.
    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

StringQueue::~StringQueue()
{
    delete [] queueArray;
}


void StringQueue::enqueue(string word)
{
    if (isFull())
        cout << "The queue is full.\n";
    else
    {
        
        // Insert new item
        queueArray[rear] = word;
        // Calculate the new rear position
        rear = (rear + 1) % queueSize;
        // Update item count
        numItems++;
    }
}


void StringQueue::dequeue(string &word)
{
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        
        // Retrieve the front item
        word = queueArray[front];
        // Move front
        front = (front + 1) % queueSize;
        // Update item count
        numItems--;
    }
}

bool StringQueue::isEmpty() const
{
    bool status;
    
    if (numItems)
        status = false;
    else
        status = true;
    
    return status;
}


bool StringQueue::isFull() const
{
    bool status;
    
    if (numItems < queueSize)
        status = false;
    else
        status = true;
    
    return status;
}


void StringQueue::clear()
{
    front = 0;
    rear = 0;
    numItems = 0;
}
