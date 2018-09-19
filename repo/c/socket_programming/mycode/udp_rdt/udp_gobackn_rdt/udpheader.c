//
//  udpheader.c
//  homework3
//
//  Created by tmoore on 10/29/15.
//  Copyright © 2015 tmoore. All rights reserved.
//

#include "udpheader.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 ***********************************************************
 RDT UDP FUNCTIONS
 ***********************************************************
 */

// prints an error msg to the console
void printError(char *msg)
{
    
    perror(msg);
    exit(-1);
    return;
    
}


// get the size of a file
int getFileSize(char *fileName)
{
    char buf[PATH_MAX + 1];
    FILE *filePointer = NULL;
    
    int size = 0;
    //open file for reading
    filePointer = fopen(realpath(fileName, buf), "r");
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


// this uses a checksum algorithm that adds the sum and
int calculateCheckSum(char data[])
{
    int i;
    int sum = 0;
    int checkSum;
    int magicNum = 127; // 99 posibilities of what the checksum could be
    for (i = 0; i< strlen(data); i++)
    {
        sum += data[i];
    }
    
    checkSum = (sum%magicNum);
    
    return checkSum;
}
