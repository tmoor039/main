//hahahaa//  desHeader.h
//  homework4
//
//  Created by tmoore on 11/21/15.
//  Copyright © 2015 tmoore. All rights reserved.
//

#ifndef desHeader_h
#define desHeader_h

#include <stdio.h>

#endif /* desHeader_h */

// fthis fucintion is used in the key generation stage
char* shiftBits(char *bs,int n);

/*
 * Purpose: This function performs the P10 operation on 10 buts
 * Parameters: 1 char
 * Returns:
 */
char *pTenFunction(void);

// Purpose: This functions gives us the size of a file given the file name
// Parameters: 1 character String - The name of the file
// Returns: The size of the file as an integer (# of bytes)
int getFileSize(char *fileName);

// Purpose: this function outputs the error message and exits with a failure code
// Parameters: one char - the error message captured by the program and a file descriptor to temrinate connection
// Returns:  void - no return value
void printError(char *msg);

// Purpose: This function will convert a binary byte to a 8 bit string
// Parameters: 1 byte read in from a file
// Return: an 8 bit binary array
 char* convertByte(unsigned char byte);


// Purpose: This function will perform the P 10 function  on the given key
// Parameters: The key specified in the command line
// Modifies the init key parameter by reference... after calling this it will be permutated
void permuteTen( char* initKey);


// generates K1
unsigned char getK1(char* initKey);

// generates K2
unsigned char getK2(char* initKey);


// Purpose: This fucntion will shift a byte first 4 bits and return the shifted output
// Parameters: The entire result of P10
// Returns: the first four bits shifted by one position in the form 00001000
unsigned char leftShitOne( unsigned char side);


// Purpose: This fucntion will shift a byte first 4 bits and return the shifted output
// Parameters: The entire result of P10
// Returns: the first four bits shifted by two positions in the form 00001000
unsigned char leftShitTwo( unsigned char side);

// this fucnction takes in the result of the ep function xored with k1 and performs swaps
// parameter: the xored result of k1 and expanded right half and the original IP left 4 bits
// returns: 4 bits specified by the sboxes
unsigned char fKay1( unsigned char xOrOutput, unsigned char ipLeft, unsigned char ipRight);


// this fucnction takes in the result of the ep function xored with k1 but does not swap the bits in the end
// parameter: the xored result of k1 and expanded right half and the original IP left 4 bits
// returns: 4 bits specified by the sboxes
unsigned char fKay2( unsigned char xOrOutput, unsigned char ipLeft, unsigned char ipRight);

// helper function to print a byte 
void printByte(unsigned char byte );

// this fucntion performs the IP function on a byte
unsigned char ipFunction(unsigned char byte);


// This function performs an xor operation between two bytes and returns a byte
unsigned char xOr(unsigned char ciphertext, unsigned char plaintext);


// this fucntion returns the defined Ip inverse funciton
unsigned char ipInverseFunction(unsigned char byte);

// this performs the deifined ep funciotn on half a byte
unsigned char epFunction( unsigned char fourBitByte);

