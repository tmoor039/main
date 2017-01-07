//
//  main.cpp
//  Homework1
//
//  Created by Tiago Moore on 9/19/12.

//
#include<iostream>
#include<cassert>

using namespace std;

//fuction prototypes
//return type: pointer
//parameters: one  double , which will be the size
// purpose: this function acepts an integer and indicates a number of integers to allocate
int *arrayAllocator(int number);

int showMode(int *array, int size);

void selectionSort(int array[], int size);

void showMedian(int *array, int size);

int findMode(int *arrPTR,  int size) ;

int main()
{
    int amount = 0;
    double average = 0 ,  total = 0 , mode = 0 ;
    
    
    cout<<"***********************Movie Statistics*****************\n\n\n"<<endl;    
    
    do
    {    //promt for students surveyed
        cout<<"How many students were surveyed? ";
        cin>>amount;
        
        if(amount < 0)
            //display invalid
        {
            cout<<"Invalid. You must enter a number greater than 0."<<endl;
        }
    }
    while ( amount < 0);
    
    
    int *p = arrayAllocator(amount);
    
    
    //populate  the array with the number of movies that they watched
    
    for (int i = 0; i < amount; i ++)
    {
        
        do
        {
            
            cout<<"Enter the number of movies that student #"<<i+1<<" watched: ";
            cin>> *(p+i);
            
            if(*(p+i) < 0)
            {
                cout<<"Invalid, you must enter a positive number."<<endl;
            }
            
        }
        while(*(p+i) < 0);
    }
    
    //Call function to sort all values entered by the user
    
    selectionSort(p,amount);
    
    cout<<"The numbered of movies that everyone entered has been sorted!! Below are the values in increasing order:\n\n\n";
    
    //display the value for verification purposes.
    
    for ( int i = 0; i < amount ; i ++)
    {
        
        cout<<*(p+i) << "\t";
    }
    cout<<endl<<endl<<endl;
    
    
    
    //calculate the average
    
    for (int i = 0; i < amount ; i ++ )
        
    {
        total += *(p+i);
        
        average = total/(i+1);
    }
    
    
    cout<<"The Average for the numbers entered by all the students is : "<<average<<endl<<endl;
    
    //calculate the median
    showMedian(p,amount);
    
    
    
    mode = findMode(p,amount);
    
    cout<<"the mode is "<<mode<<endl;
    
    return 0;
    
    
}

int *arrayAllocator(int number)
{
    
    int *p = NULL;
    p = new  int[number];
    
    assert( p != NULL);
    
    return p;
    
}



void selectionSort(int array[], int size)
{
    int startScan, minIndex;
    int minValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}




void showMedian(int *array, int size)
{
    
    selectionSort(array,size);
    
    int middle = 0;    
    double median = 0;
    
    if ((size % 2)!= 0)
    {
        middle = ((size - 1) / 2);
        median = array[middle];
    }
    
    else
    {
    middle = (0 + size) / 2;
    
    median = ((array[middle] + array[middle +1]) /2); 
    }
    cout << "The median for the numbers entered is: " << median <<" "<< endl;
    
}


int findMode(int *pointer,  int size)
{
    int mode = 0, amount = 0, highestnumber= 0 ;
    
    int *frequency = NULL;
    frequency = new  int[size];
    
    assert( frequency != NULL);    
 
    
    //create a nested loop to calculate the numbers that appear more than once in the array
    
    for (int i = 0; i < size; i++)
        
    {
       
    for (int j = 1; j < size; j++)
            
    {
           
        if (*(pointer + i) == *(pointer + j) ) 
                
                //if the number is detected, increment
                
                *(frequency + i) = *(frequency+i) + 1 ;               
            
        }
       
    }
    
    
    highestnumber = *(frequency);
    
    for (int t = 0; t< size; t++)   
      
    {
        
        // do a for loop to increment the number of times the number is found
        if (*(frequency + t) > highestnumber)
          
        {
           
            highestnumber = *(frequency + t);
          
            amount += t;                        
        }
        
    }
    
  
    for(int i = 0; i < size; i++)
       
        if(*(frequency + i) != *(frequency + (i + 1)) )
            
        {
            
            mode = *(pointer + amount);
           
            return mode;    //returns number that occurs most
           
        }
        
    
        else
        {
            cout<<"There is no mode, there must be more than once."<<endl;
           
        }    
             return mode;
}

    