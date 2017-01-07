//
//  main.c
//  ArraySamp
//
//  Created by T Moore on 4/5/14.
//  Copyright (c) 2014 T Moore. All rights reserved.
//
/*
 Author  : Michael Robinson
 Program : arraysV2.c
 Purpose : To present multiple forms of working with arrays
 Updated : Jan 29, 2011
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void stringArray( char array[] )
{
    printf( "\n\nname in char array[] is %s the length is %zu\n", array, strlen(array) );
    
    char *theName = array; //copies the array into the variable theName
    printf( "\nname in char theName is %s and the length is %zu\n", theName, strlen(theName) );
    
    //example one creating a single dimension array with ONE index
    char *nameOne[1];  // creates a single dimension array of data type char with ONE index only
    // does not determine the size of the data to be placed in the array[0] location
    
    nameOne[0] = "George & Washington % Rodriguez "; //initializes nameOne[0]
    printf("\nfirst example is %s\n", nameOne[0]);     //prints content in nameOne[0]
    
    
    //example two
    char nameTwo[1][20]; //size of the data to be placed in the array[0] location is maximum 20
    
    strcpy(nameTwo[0], "George & Washington % Rodriguez "); //copies data into nameTwo[0] arrays
    
    printf( "\nsecond example is %s, the name length is %zu\n", nameTwo[0], strlen(nameTwo[0]) );
    
}//end void stringArray( char array[] )



int main()
{
    stringArray( "Michael" );
    
    printf("\n END OF PROGRAM\n\n");
    
}//end int main()