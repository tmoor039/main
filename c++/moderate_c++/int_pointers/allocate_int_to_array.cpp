//
//  main.cpp
//  ArrayAllocator Function
//
//  Created by  on 9/9/12.
// Reviewed 9/4/2018
//
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//function prototype

//return type: pointer
//paramenters: one int which will indicate the number of elements to allocate
//Purpose: this funciton will dynamically allocates an integers to the array.

int* arrayAllocator (int integer);


int main()

{
    
    int SIZE = 0 ;
    do {

        cout<<"How many number do you want to use? ";
        cin>>SIZE;
        if (SIZE< 0) 
            
        {
            cout<<"You cannot enter a value less than 0"<<endl;
        }  
        
    } while (SIZE < 0 );
    
	int *p = arrayAllocator(SIZE);
    // this created an array ( or opened up an array of the specific size entered by the user)
    
    
    //seed random number generator
    
    srand( time(0) );
    
    
    //for display purposes populate the array with random integers
    
    for( int i = 0 ; i < SIZE; i ++)
    {
    
        *(p+i) = rand()%11;
        
    }
    
    //display popullated array 
    
    cout<<" The following numbers were generated randomly : ";
    for (int i = 0 ; i <SIZE; i ++)
    {
        
        cout<< *(p+i) << " " ;
        
    }
    
	
    cout<<"\n\n\n";
    
    
    return 0;
    
}

int*arrayAllocator (int size)

{
 
	int  * p = NULL;
	
	p = new int[size];
	do {
        
        if (p == NULL)
        {
            cout<<"Warning pointer is point no where!"<<endl;
            
        }
        
    } while (p == NULL);    

	return p;
    
}
