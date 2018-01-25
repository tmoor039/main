//
//  tcpheader.h
//  Net_Centric_Projects
//
//  Created by tmoore on 9/12/15.
//  Copyright (c) 2015 tmoore. All rights reserved.
//

#ifndef Net_Centric_Projects_tcpheader_h
#define Net_Centric_Projects_tcpheader_h
#include <dirent.h>

// Purpose: this function outputs the error message and exits with a failure code
// Parameters: one char - the error message captured by the program and a file descriptor to temrinate connection
// Returns:  void - no return value
void printError(char *msg);

//Purpose: this function overwrites the buffer in reverse order
void reverseString(char *string);


//Purpose: to read a msg from a client
//Parameters: the socket file descriptor, the buffer, buffersize lengthOfcmd 
//Returns : The message read from the client, and the implicit return of cmdLength
char * acceptMsg(int socketDescriptor,char buff[], int buffLength, int *cmdLength);

//Purpose: this function will terminate the connection of the client once the command exit is received
//Parameters: the file descriptor to close
//Returns: 0 if successfully terminated -1 if not terminated
void terminateConnection( int fileDescriptor);

//Purpose: this fucntin will list the files in the executing programs directory by calling the readdir system call
//Parameters, a dirent struct to hold file names/etc and and DIR to represent a directory stream
// return :a string with all the files in a directory
char* listFiles(struct dirent *directory,DIR *folderPath);

//Purpose: THis function should return the size of a file in bytes
//Parameters: One file pointer to the file we want to get the size off
//return: the number of bytes in the file
int getFileSize( char* fileName);

//Purpose: Splits a string in the format of "Hey You" and returns "You"..
//Parameters: A string to split, char pointer
//REturns: the second half of the string
char* getFileName(char* lineToSplit);

// makes sure all the bytes are sent... returns the string lenghth as total bytes sent 
int assertSend(int socket, char *string, int *stringLength);


#endif
