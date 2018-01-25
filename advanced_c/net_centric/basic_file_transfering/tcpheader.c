//
//  tcpheader.c
//  Net_Centric_Projects
//  Header to be used with all tcp type programs
//  Created by tmoore on 9/12/15.
//  Copyright (c) 2015 tmoore. All rights reserved.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "tcpheader.h"
#include <limits.h>




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

// Purpose is to assert all bytes were sent
int assertSend(int socket, char *string, int *stringLength)
{
    int totalBytes = 0;
    int bytesToSent = *stringLength;
    int current = 0;
    
    while(totalBytes < *stringLength)
    {
        // attempts to send all the bytes
        current = send(socket, string+totalBytes,bytesToSent, 0);
        if (current == -1)
        {
            printError("Error sending bytes.");// should terminate here
            return -1;
        }
        
        totalBytes+= current;
        
        bytesToSent-= current;
    }
    
    *stringLength = totalBytes; // sets the number of bytes that were sent for usage in main program
    
    return 0;
    
}

//Purpose: to read a msg from a client
char *acceptMsg(int socketDescriptor,char buff[], int buffLength, int *msgLength)
{
    // zero out all bytes in the buffer
    bzero(buff, buffLength);
    int bytesReceived = recv(socketDescriptor, buff,buffLength, 0);
    if(bytesReceived < 0)
    {
        printError("Did not receive mesage.");
    }
        // set the last position in the char arry to \0
        buff[bytesReceived] = '\0';
        *msgLength = strlen(buff); // returns the length of command here

    return buff;
    
}

//terminates a connection by closing file descriptor and exiting the current process
void terminateConnection(int fileDescriptor)
{
    close(fileDescriptor);
    
    exit(0);
    
    return;
    
}

//list the files in the executing programs directory by calling the readdir system call
char* listFiles(struct dirent *directory,DIR *folderPath)
{
    char *allFiles = NULL; // string to return that will have list of all references in directory
    int totalBytes = 0;
    int numFileCount = 0; // to compensate for the '\'n' that will be added to each file name

    folderPath = opendir("."); // open the current directory where the source code is being called
    if (folderPath != NULL) // if open was sucesfull
    {
        // run trhough all the names of the files once and get total size of final string that will have all the directory names
        while ((directory = readdir(folderPath)) != NULL)
        {
            totalBytes+= strlen(directory->d_name);
            numFileCount++;
        }
        // allocate memory for string that will contain list of all files
        
        allFiles = malloc(sizeof(char)*totalBytes+numFileCount);
        
        // reset position of directory
        rewinddir(folderPath);
        while ((directory = readdir(folderPath)) != NULL) // while there are still files in this diretory
        {
            strcat(allFiles,directory->d_name);
            strcat(allFiles, "\n");
        }
    }
    // otherwise..cant open dir file throw an error
    else
    {
        printError("Directory not found !");
        // should exit
    }

    return allFiles;
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

// simple function to split a stirng and get the second
char* getFileName(char* lineToSplit)
{
    char *p = malloc(strlen(lineToSplit)*sizeof(char));
    char *delimiter = " "; // Asumming string is "HEY YOU"
    //Segment will point to "HEY".
    p = strtok(lineToSplit, delimiter);
    
    // Segment will point to "YOU".
    p = strtok(NULL, delimiter);

    return p;
    
}
  
          


