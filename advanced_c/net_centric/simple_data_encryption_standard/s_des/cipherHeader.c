//
//  desHeader.c
//  homework4
//
//  Created by tmoore on 11/21/15.
//  Copyright © 2015 tmoore. All rights reserved.
// This header file

#include "cipherHeader.h"
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/************************
 
 KEY GENERATION FUNCTIONS
 
*************************/

// Purpose: this function outputs the error message and exits with a failure code
void printError(char *msg)
{
    
    perror(msg);
    exit(-1);
    return;
    
}

// Purpose is to overwrite a string in reverse order
void reverseString(char* buf)
{
    int i = 0, j = strlen(buf)-1; // start j at the end
    while(i < j) // while we havent swapped letters
    {
        char c = buf[j]; // keep track of the last character
        buf[j--] = buf[i]; //make the last character the front charater and update the last character
        buf[i++] = c; // make the first character the last one and update the first character
    }
    return;
}

// get the size of a file
int getFileSize(char *fileName)
{
char buf[PATH_MAX + 1];
FILE *filePointer = NULL;

int size = 0;
//open file for reading
filePointer = fopen(realpath(fileName, buf), "rb");
if (filePointer==NULL)
{
printError("Error opening file for size measuring.\n");
}
//traverse trhough file counting each byte
if(fseek(filePointer,0,SEEK_END)!=0)
{
//if system call failed...handle error
printError("Error measuring file size.\n");
}
size = ftell(filePointer);
if(size ==-1)
{
printError("Invalid file size");
}

fclose(filePointer);

return size;
}

// converts byte to 8 bit string (reverses it for manipulation)
// this key generation is done with character manipulation and not bit shifting
void permuteTen(char* initKey)
{
    char permutedString[11];
    //defined permuation array
    int pTen[10]={3,5,2,7,4,10,1,9,8,6};
    
    int i ;

    // assign values to the permutated version
    for(i=0;i<10;i++)
    {
        permutedString[i]=initKey[pTen[i]-1];
    }
    // copy the key to return
    strcpy(initKey, permutedString);
    return; 
}

// generates the first key
unsigned char getK1(char* initKey)
{

    unsigned char leftM = 7; //0000111 // we only care about the last 3 bits from left  byte
    unsigned char blank = 0;
   // printByte(pTenOutput);
    
    char original[11];
    strcpy(original, initKey);
    
    int pEight[8]={4,1,5,2,6,3,8,7 }; // define permuation array
    char left[6];
    char right[6];
    int i;
    
    // split up the left and the right sides with character manipulation
    for(i=0;i<5;i++)
    {
        left[i]=original[i];
        right[i]=original[i+5];
    }
    left[5]='\0';
    right[5]='\0';
    
    unsigned char leftByte1; // convert it to byte
    unsigned int l = (unsigned int)strtol(left, NULL, 2);
    leftByte1 = l;
    
    unsigned char rightByte1; // convert it to byte
    l = (unsigned int)strtol(right, NULL, 2);
    rightByte1 = l;
    
    // perform a left shit one on those bytes
    leftByte1 = leftShitOne(leftByte1);
    rightByte1= leftShitOne(rightByte1);

    // put the left byte in a position to &
    unsigned char lb = leftByte1 &leftM;
    blank = lb | blank; // so that we can isolate the last 3 bits of the last side
    blank = blank <<5;// move the bits to the left side

    // or the left side with the righ side to get P8
unsigned char p8 = blank | rightByte1;
    
   // this converts the to string format .... for character manipulation
    unsigned int tempx;
    char bits[9];
    tempx = p8;
    unsigned char tempy;
    for (i = 0; i < 8; i++)
    {
        tempy  =tempx %2;
        tempx = tempx/2;
        if (tempy!=0)
        {
            bits[i] = '1';
        }
        else
        {
            bits[i] = '0';
        }
        
    }
    bits[8] = '\0';
    reverseString(bits); // reverse the string to write to bits in for loop
    char k1[9];
    
    // permutate the stiring
    for(i=0;i<8;i++)
    {
        k1[i]=bits[pEight[i]-1]; // assigned the p8 to the key
    }
    
    k1[8]='\0'; // null termiante k1
    
    // convert it back to byte format
    l = (unsigned int)strtol(k1, NULL, 2);
    p8 = l;
    // return the ke back in byte format
    return p8; 
    
}

// this fucntion does the same thing as get K1 but shits by  2 bytes
unsigned char getK2(char* initKey)
{
    
    //unsigned char pTenOutput = l ;
    unsigned char leftM = 7; //0000111 // we only care about the last 3 bits from left  byte
    unsigned char blank = 0;
    // printByte(pTenOutput);
    
    char original[11];
    strcpy(original, initKey);
    
    int pEight[8]={4,1,5,2,6,3,8,7};
    char left[6];
    char right[6];
    int i;
    for(i=0;i<5;i++)
    {
        left[i]=original[i];
        right[i]=original[i+5];
    }
    left[5]='\0';
    right[5]='\0';
    
    unsigned char leftByte1;
    unsigned int l = (unsigned int)strtol(left, NULL, 2);
    leftByte1 = l;
    
    unsigned char rightByte1;
    l = (unsigned int)strtol(right, NULL, 2);
    rightByte1 = l;
    
    leftByte1 =  leftShitTwo(leftByte1);
    rightByte1= leftShitTwo(rightByte1);
    
    // put the left byte in a position to &

    unsigned char lb = leftByte1&leftM; // ignore the first 4 bits
    unsigned char rb = 224;// 11100000;
    
    blank = lb | blank; // so that we can isolate the last 3 bits of the last side
    blank = blank <<5;// move the bits to the left side
    
    // or the left side with the righ side to get P8
    
    // combined strings trucnked first and second bit... need to permuate
    unsigned char p8 = blank | rightByte1;
    
   // printByte(p8);
    
    unsigned int tempx;
    char bits[9];
    tempx = p8;
       unsigned char tempy;
    for (i = 0; i < 8; i++)
    {
        tempy  =tempx %2;
        tempx = tempx/2;
        if (tempy!=0)
        {
            bits[i] = '1';
        }
        else
        {
            bits[i] = '0';
        }
        
    }
    bits[8] = '\0';
    reverseString(bits); // reverse the string to write to bits in for loop
    char k1[9];
    
    // permutate the stiring
    for(i=0;i<8;i++)
    {
        k1[i]=bits[pEight[i]-1];
    }
    
    k1[8]='\0'; // null termiante k1

    // convert it back to byte format
    l = (unsigned int)strtol(k1, NULL, 2);
    p8 = l;
    // return the ke back in byte format
    return p8;
}

// shits a byte bit one bit left
unsigned char leftShitOne( unsigned char side)
{
    unsigned char mask = 31;
    side = (side <<1) | (side  >> (5 - 1));
    
    return mask & side;
}
// shits a byte by 3 bits left.....called by K2
unsigned char leftShitTwo( unsigned char side)
{
    unsigned char mask = 31;
    side = (side <<3) | (side  >> (5 - 3)); // shift bytes
        return mask & side;
}


//print byte for debugging purposes
void printByte(unsigned char byte )
{
     char* binaryString = malloc(9);
    unsigned int tempx;
    char bits[9];
    tempx = byte;
    int i, tempy;
    for (i = 0; i < 8; i++)
    {
        tempy  =tempx %2;
        tempx = tempx/2;
        if (tempy!=0)
        {
            bits[i] = '1';
        }
        else
        {
            bits[i] = '0';
        }
    }
    bits[8] = '\0';
    strcpy(binaryString, bits);
    reverseString(binaryString);
    
    printf("%s\n",binaryString);
    

}

// performs the IP permuation
unsigned char ipFunction(unsigned char byte)
{
    int ip[8] = {6,2,5,7,4,0,3,1}; // defined permutation array
    // create a byte with bits al all zeroes
    unsigned char blank = 0;
    //blank = byte;
   // printByte(byte);
    int i ;
    // shift bytes
    for ( i = 0; i < 8; i++ )
    {
        blank <<= 1;
        if ( byte & (1 << ip[i]) )
            blank |= 1;
    }
   // printByte(blank);
    return blank;
}

// performs the inverse ip function on a byte
unsigned char ipInverseFunction(unsigned char byte)
{
    int ip[8] = {4,7,5,3,1,6,0,2}; // defined permutation array(modified since we change array backwards)
    // create a byte with bits al all zeroes
    unsigned char blank = 0;
    //blank = byte;
   //  printByte(byte);
    int i ;
    // shift bytes
    for ( i = 0; i < 8; i++ )
    {
        blank <<= 1;
        if ( byte & (1 << ip[i]))
            blank |= 1;
    }
  //  printByte(blank);
    return blank;
}

// this function xors the vector with a plaintext byte
// returns the result of the xor of the cipher chain block to be passed in the IP function
unsigned char xOr(unsigned char ciphertext, unsigned char plaintext)
{
    return  ciphertext ^ plaintext;
}


// the funciton performs the EP function on a byte on the form 00001111
// parameters: one unsignced char the 4 bits to be expanded
// returns the expanded byte
unsigned char epFunction( unsigned char fourBitByte)
{
   
    int EP[8] = {0,3,2,1,2,1,0,3}; // defined constant permutation function...
    unsigned char blank = 0; // the result
    int i ;
    // shift bytes
    for ( i = 0; i < 8; i++ )
    {
        blank <<= 1;
        if ( fourBitByte & (1 << EP[i]) )// this does the permutation 
            blank |= 1;
    }
    return blank; // returns the permuated 8 bit byte
}

// this fucnction takes in the result of the ep function xored with k1 and performs subtitiontion
// parameter: the xored result of k1 and expanded right half
// returns: 4 bits specified by the sboxes
unsigned char fKay1( unsigned char xOrOutput,unsigned char ipLeft, unsigned char ipRight)
{
    unsigned char s0Input= 0 ;
    unsigned char s1Input = 0;
    unsigned char p4 = 0;
    unsigned char permuttedP4 = 0;
    
    // varaibles for the 2d arrays
    unsigned int s0row = 0;
    unsigned int s0col = 0;
    unsigned int s1row = 0;
    unsigned int s1col= 0;
    // output from the arrays
    unsigned int s0Result = 0;
    unsigned int s1Result = 0;
    
    // gets the row for s0 in binary form
    if (xOrOutput & (1 << 4))
    {
        s0Input |= 1 << 0;
    }
    if (xOrOutput & (1 << 7))
    {
        s0Input |= 1 << 1;
    }
    s0row = s0Input; // set the row to get from s0 box
    s0Input = 0; // clear the input
    // gets the colum for s0 in binary form
    // gets the row for s0 in binary form
    if (xOrOutput & (1 << 6))
    {
        s0Input |= 1 << 1;
    }
    if (xOrOutput & (1 << 5))
    {
        s0Input |= 1 << 0;
    }
    s0col = s0Input; // set the row to get from s0 box
    
    
    // repeat proceadude for s1 box
    if (xOrOutput & (1 << 3))
    {
        s1Input |= 1 << 1;
    }
    if (xOrOutput & (1 << 0))
    {
        s1Input |= 1 << 0;
    }
    s1row = s1Input; // set the row to get from s0 box
    s1Input = 0;
    // gets the colum for s0 in binary form
    // gets the row for s0 in binary form
    if (xOrOutput & (1 << 2))
    {
        s1Input |= 1 << 1;
    }
    if (xOrOutput & (1 << 1))
    {
        s1Input |= 1 << 0;
    }
    s1col = s1Input; // set the row to get from s0 bo
    
    //now we know where to look in our defined 4 d array..
    
    // defined S box 0
    int S0[4][4]={1,0,3,2,3,2,1,0,0,2,1,3,3,1,3,2};
    // defined S box 1
    int S1[4][4] = {0,1,2,3,2,0,1,3,3,0,1,0,2,1,0,3};
    
    // generate p4 from the sbox output.
    
    s0Result = S0[s0row][s0col];
    s1Result = S1[s1row][s1col];
    
    
    // it bit 0 in s1 in set
    if (s1Result & (1 << 0))
    {
        p4 |= 1 << 0; // set bit 0 in p4
    }

    // if bit 1 in s1 in set
    
    if (s1Result & (1 << 1))
    {
        p4 |= 1 << 1;  // set bit 1 in p4
    }
    

    // if bit 0 in s0 is it
    
    if (s0Result & (1 << 0))
    {
        p4 |= 1 << 2;    // set bit 2 in p4
    }

    // if bit 1 in s0 is set
    if (s0Result & (1 << 1))
    {
        p4 |= 1 << 3;// set bit 3 in p4
        
    }
    
    // at this point we need to permutate p4
    
    int P4[4] = {2,0,1,3}; // defined permutation array
    int i;
    // shift bytes
    for ( i = 0; i < 4; i++ )
    {
        permuttedP4 <<= 1;
        if ( p4 & (1 << P4[i]))
            permuttedP4 |= 1;
    }
 
    // p4 is permutted and ready.

    // shift the ip left 4 bits so we could xor
    //00001010
    //00001000
    
    ipLeft = ipLeft >>4;// move the bits to the left side
    // reset p4
    p4 = 0;
    // xcluse or ip left with the  new right
    p4 = xOr(ipLeft, permuttedP4);
  
    // shift those 4 of the right to he left (SWAP STAGE )
    ipRight = ipRight <<4;
    //combine the origin iP right with the new left
    
    // reset permutedP4
    permuttedP4 = 0;
    
    permuttedP4 = p4 | ipRight;

    // return the result for the round
    return permuttedP4;
}

// this fucnction takes in the result of the ep function xored with k1 and performs subtitiontion
// parameter: the xored result of k2 and expanded right half
// returns: 4 bits specified by the sboxes
unsigned char fKay2( unsigned char xOrOutput,unsigned char ipLeft, unsigned char ipRight)
{
    // varialbes for the box input
    unsigned char s0Input= 0 ;
    unsigned char s1Input = 0;
    unsigned char p4 = 0;
    unsigned char permuttedP4 = 0;
    
    // varaibles for the 2d arrays
    unsigned int s0row = 0;
    unsigned int s0col = 0;
    unsigned int s1row = 0;
    unsigned int s1col= 0;
    // output from the arrays
    unsigned int s0Result = 0;
    unsigned int s1Result = 0;
    
    // gets the row for s0 in binary form
    if (xOrOutput & (1 << 4)) // if the  fourth bit of the para is 1
    {
        s0Input |= 1 << 0; // set the input for the s box
    }
    if (xOrOutput & (1 << 7))
    {
        s0Input |= 1 << 1;
    }
    s0row = s0Input; // set the row to get from s0 box
    s0Input = 0; // clear the input
    // gets the colum for s0 in binary form
    // gets the row for s0 in binary form
    if (xOrOutput & (1 << 6))
    {
        s0Input |= 1 << 1;
    }
    if (xOrOutput & (1 << 5))
    {
        s0Input |= 1 << 0;
    }
    s0col = s0Input; // set the row to get from s0 box
    
    
    // repeat proceadude for s1 box
    if (xOrOutput & (1 << 3))
    {
        s1Input |= 1 << 1;
    }
    if (xOrOutput & (1 << 0))
    {
        s1Input |= 1 << 0;
    }
    s1row = s1Input; // set the row to get from s0 box
    s1Input = 0;
    // gets the colum for s0 in binary form
    // gets the row for s0 in binary form
    if (xOrOutput & (1 << 2))
    {
        s1Input |= 1 << 1;
    }
    if (xOrOutput & (1 << 1))
    {
        s1Input |= 1 << 0;
    }
    s1col = s1Input; // set the row to get from s0 bo
    
    //now we know where to look in our defined 4 d array..
    
    // defined S box 0
    int S0[4][4]={1,0,3,2,3,2,1,0,0,2,1,3,3,1,3,2};
    // defined S box 1
    int S1[4][4] = {0,1,2,3,2,0,1,3,3,0,1,0,2,1,0,3};
    
    // generate p4 from the sbox output.
    
    s0Result = S0[s0row][s0col];
    s1Result = S1[s1row][s1col];
    
    // it bit 0 in s1 in set
    if (s1Result & (1 << 0))
    {
        p4 |= 1 << 0; // set bit 0 in p4
    }
    
    // if bit 1 in s1 in set
    
    if (s1Result & (1 << 1))
    {
        p4 |= 1 << 1;  // set bit 1 in p4
    }
    
    
    // if bit 0 in s0 is it
    
    if (s0Result & (1 << 0))
    {
        p4 |= 1 << 2;    // set bit 2 in p4
    }
    
    // if bit 1 in s0 is set
    if (s0Result & (1 << 1))
    {
        p4 |= 1 << 3;// set bit 3 in p4
    }
    
    // at this point we need to permutate p4
    
    int P4[4] = {2,0,1,3}; // defined permutation array
    int i;
    // shift bytes
    for ( i = 0; i < 4; i++ )
    {
        permuttedP4 <<= 1;
        if ( p4 & (1 << P4[i]))
            permuttedP4 |= 1;
    }
    
    // p4 is permutted and ready.
    
    // shift the ip left 4 bits so we could xor
    //00001010
    //00001000
    
    ipLeft = ipLeft >>4;// move the bits to the left side
    // reset p4
    p4 = 0;
    // xcluse or ip left with the  new right
    p4 = xOr(ipLeft, permuttedP4);
    
    // shift bits to the left to be combined with right part
    p4 = p4 <<4;
    //combine the origin iP right with the new left
    
    // reset permutedP4
    permuttedP4 = 0;
    
    permuttedP4 = p4 | ipRight;
    
    // return the result for the round
    return permuttedP4;
    
    }







