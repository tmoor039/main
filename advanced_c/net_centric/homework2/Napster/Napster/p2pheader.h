//
//  p2pheader.h
//  p2p
//
//  Created by tmoore on 10/2/15.
//  Copyright © 2015 tmoore. All rights reserved.
//

#ifndef p2pheader_h
#define p2pheader_h

#include <stdio.h>
#include <dirent.h>
#include <netinet/in.h>
#include <arpa/inet.h>


/*
 ***********************************************************
                START OF  LINKED LIST STRUCTURES
 ***********************************************************
 */

typedef struct LineInfo // the value of the node...
{
    
    int posiiton; // the position in the total list of files
    char filename[100]; // the name of the file in the line
    char ip[100]; // the ip address the peer which the line belongs to
    int portNum; // the port number for the client with the line accepts connections
}Line;

typedef struct Node // node of a linked list
{
    Line line;
    struct Node *next;
}node;

/*
 ***********************************************************
                END OF LINKED LIST STRUCTURES
 ***********************************************************
 */

/*
 ***********************************************************
                START OF  Network STRUCTURES
 ***********************************************************
 */
// struct for the connectionInfo

// acts as a hash map
typedef struct HashTable
{
    char* file; // array of file strings in this client (value)
    int position; // the position of that file  in the total list of files array( key)
    
}Table;

// declare structs

typedef struct PeerInfoStruct
{
    char clientIP[50]; // Peers ip address
    char localItemList[200]; // Peers local  directory files
    int serverPort; // Port in which the peer accepts connections
    int numFiles; // number of files in the localItemList
    Table hashTable[50]; // supports 50 file names

}PeerInfo;

// struct for the server thread in the peer
typedef struct ServerItem
{
    int fd;
    int port;
    char ip[50];
    int servCount;
    
}Server;


/*
 ***********************************************************
                    END OF NETWORK STRUCTURES
 ***********************************************************
 */



// Purpose: This thread runs the server functionality of our peer... spawns new processes for incomming connections
// Parameters: the int file descriptor of the server, and the port to run the server on
// Returns : void -
void *runServer(void* serverInfo);


// thread for handling a connection
void *connection_handler(void *);


// This thread requests a file from the peer
void *requestFile(void *fileToGetLine);


// runs within the run server thread.. handles peer connection
void *serveFile(void *sockfd);

//purpose: parses the line in the format of [0] file1 131.94.130.178:6000 to a line struct
// parameter: the ine in the format of [0] file1 131.94.130.178:6000
// returns a line struct with all critical server info
Line parseLineInfo(char* line);


// Purpose: this function outputs the error mes/Users/tmoore/Documents/School/Net_Centric_Projects/Net_Centric_Projects/tcpheader.hsage and exits with a failure code
// Parameters: one char - the error message captured by the program and a file descriptor to temrinate connection
// Returns:  void - no return value
void printError(char *msg);

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




//Purpose: Splits a string in the format of "Hey You" and returns "You"..
//Parameters: A string to split, char pointer
//REturns: the second half of the string
char* getFileName(char* lineToSplit);

/*Purpose: This function will count the number of files in a directory returned by ls-local
         it should ignore '.' and '..' and count the number of string seperated by '/n'
Parameters: 1 char[] -the string returned by ls-local containing the list of files in the current
            directory
Returns: An integer value for the number of files in the directory*/
int countFiles(char* fileList,struct dirent *directory,DIR *folderPath);


// Purpose: this function will assert all bytes were sucessuly sent from client
// Paramenters: the string and number of bytes read and the length of the numberOfbytes actually read
//returns 0 if all bytes were read and -1 if uncessefull
int assertSend(int socket, char *string, int*stringLength);

// Purpose: conunt the number of occurances of the '\n'
//Parameters: one string to count new lines
// Return: the nubmer of files separated by '\n'

int countNewLines(char* string);


//Purpose: This function receives a list of files separated by \n and spits back a file before position specified \n
// Paramameters: the list of files and the number of \n to skip before getting the next file name
//Returns : the file name before the fileLoc \n location
char* splitFileList(char* list,int fileWanted);

// Hash function that returns the position requested by the peer
char* getHashFile(int position,PeerInfo peer);

/*
 ***********************************************************
 START OF  LINKED LIST FUNCTIONS
 ***********************************************************
 */

node *createList(Line peerLine);

node* addLine(Line peerLine);

node* locateLine(char* ip,node **prev, int portNum);

// searches for specific file number in a line
// returns the entire line containing the position requested
node* locateFile(int posNum,node **prev);

int removePeer(int numOfLinesToRemove,char*iP, int portNum);

//returns the line specified by position
char * getLine(int pos);

// returns the formatted list
char* writeList(int totalFileNum);
/*
 ***********************************************************
 END LINKED LIST FUNCTIONS
 ***********************************************************
 */



#endif /* p2pheader_h */
