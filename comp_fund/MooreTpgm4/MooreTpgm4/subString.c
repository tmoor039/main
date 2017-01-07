/*
Author  : Michael Robinson
Program : subString.c
Purpose : subString( string, from, to)
          extract a subString from a string from location to location  
Updated : Jan 29, 2011
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char subbuff[5];

const char* subString( char word[], int from, int to )
{
    memcpy( subbuff, &word[from], (to-from+1) );
    subbuff[to-from+1] = '\0';
    printf( "[%s]  [%s] from %d  to %d\n", word, subbuff, from, to );

    return  subbuff;
}


int main()
{
    const char *string = subString( "michael $ Robinson % ", 3, 8  );
    printf( "\n%s\n", string  );
        
}//end int main()/Users/tmoore/Documents/School/FIU/Spring2014/CDA3103/subString.c
