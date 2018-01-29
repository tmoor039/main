//
//  main.c
//  MooreTpgm3
//  Created by T Moore on 3/26/14.
//  Copyright (c) 2014 Tiago Moore. All rights reserved.
//
/*********************************************************************
 Author    : Tiago Moore
 Course    : CDA3101 MWF 1300-1350
 Professor : Michael Robinson
 Program # : An introduction to programming in the C language
 
 Due Date : 04/04/2014
 
 Certification:
 I hereby certify that this work is my own and none of it is the work of any other person.
                //SIGNED// TIAGOMOORE
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prints the name character by character
// takes parameter array of size 1 hold up to a maximum of 24 letters of the alphabet
//Note, method is hard coded for the assigment, it considers all but & % space and vowels as consonants
void myName(char array[1][1])

{

    for(int i = 0; i < strlen(array[0]); i++)
    {
        
        char character = array[0][i];
        //if its uppercase or lower case vowel
        if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U')
        {
            //print it
            printf("Character [%c] located at position %d is a vowel.\n", character, i);
        }
        
        else if(character == '&' || character == '%')
        {
            printf("Character [%c] located at position %d is a symbol.\n", character, i);
        }
        else if(character == ' ')
        {
            printf("Character [%c] located at position %d is a space.\n", character, i);
        }
        else // if c is a consonant upper or lower case.
        {
            printf("Character [%c] located at position %d is a consonant.\n", character, i);
        }
        
    }
    
}


int main()
{
    //declare and initialize variables
    char name[1][26];
    strcpy(name[0], "Tiago & Giovani % Moore ");
    printf("\nMy name is %s and the length of the array is %zu\n\n", name[0], strlen(name[0]));
    myName(name);// call function to print name
  
    
    // create a single dimension array with one index
    
    
        return 0;
}




