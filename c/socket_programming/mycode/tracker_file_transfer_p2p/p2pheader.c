//
//  p2pheader.c
//  p2p
//
//  Created by tmoore on 10/2/15.
//  Copyright © 2015 tmoore. All rights reserved.
//

#include "p2pheader.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <pthread.h>


/*
 ***********************************************************
                   START OF GLOBAL VARIABLES
 ***********************************************************
 */
pthread_mutex_t lock; // mutex for updating total peer count... keeps threads scrynohized 
int totalFileCount=0; // number of nodes in the list
int totalPeers= 0;
PeerInfo peer[1000]; // tracker supports 1000 connections.... saves info about peer cookie style
int ipCheck = 0 ;
// generate list of files

node *head = NULL;
node *curr = NULL;

/*
 ***********************************************************
                 END OF GLOBAL VARIABLES
 ***********************************************************
 */


// Purpose: this function outputs the error message and exits with a failure code
void printError(char *msg)
{
    
    perror(msg);
    exit(-1);
    return;
    
}

//Purpose: to read a msg from a client
char *acceptMsg(int socketDescriptor,char buff[], int buffLength, int *msgLength)
{
    // zero out all bytes in the buffer
    bzero(buff, buffLength);
    int bytesReceived = recv(socketDescriptor, buff,buffLength, 0);
    if(bytesReceived < 0 || buff[0] =='\0' )
    {
        printError("Tracker not available..Did not receive mesage.");
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
    
   // exit(0);
    
    return;
    
}

//list the files in the executing programs directory by calling the readdir system call
char* listFiles(struct dirent *directory,DIR *folderPath)
{
    struct stat s;
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
            char path[1024]; path[0] = 0;
            strcat(path, directory->d_name);
            
            if (!stat(path, &s))
            {
                if (S_ISREG(s.st_mode))
                {
                    strcat(allFiles,directory->d_name);
                    strcat(allFiles, "\n");
                }
            }
    
   
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

//Purpose: This function will count the number of files in a directory returned by ls-local
int countFiles(char* fileList,struct dirent *directory,DIR *folderPath)
{
    int file_count = 0;
    
    folderPath = opendir("."); // open the current directory where the source code is being called
    if (folderPath != NULL)
    {
    while ((directory = readdir(folderPath)) != NULL)
    {
        if (directory->d_type == DT_REG)// check if entry is a regular file...
        {
            file_count++;
        }
    }
    closedir(folderPath);
    }
    else
    {
        printError("Directory not found !");
    }
    
    return file_count;
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
        current = send(socket,string+totalBytes,bytesToSent, 0);
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

// takes in a line  from the server and parses into struct
Line parseLineInfo(char* line)
{
    Line peerInfo;
    // local variables to store crit info from string param
    char ip[30];
    int portNum;
    char filename [30];
    
    char *p = malloc(strlen(line)*sizeof(char));
    char *delimiter = " "; // Asumming string is "HEY YOU"
    //Segment will point to "HEY".
    p = strtok(line, delimiter); // points to [position]... not needed so ignore
    
    // Segment will point to the file name.
    p = strtok(NULL, delimiter);
    strcpy(filename, p);
    
    char *p2 = malloc(strlen(line)*sizeof(char));
    p2 = strtok(NULL, delimiter);
    strcpy(ip, p2); // should point to the port and up... need to part at delmiter ': now'
    
    
    char *p3 = malloc(strlen(line)*sizeof(char));
    char *delimiter2 = ":"; // Asumming string is ""
    p3 = strtok(p2, delimiter2);
    strcpy(ip, p3); // should point to the port and up... need to part at delmiter ':'
    //Segment will point to "the ip".
    p3 = strtok(NULL, delimiter2); // points to the port number.
    portNum = atoi(p3);
    
    
    strcpy(peerInfo.filename,filename);
    stpcpy(peerInfo.ip, ip);
    peerInfo.portNum = portNum;
    
    
    return peerInfo;
    
}


// counts the number of new line characters in a string
int countNewLines(char*string)
{
    int count=0;
    int i ;
    
    for(i = 0; i < strlen(string); i++)
    {
        if (*(string+i)=='\n')
        {
            count++;
        }
    }
    
    return count;
    
}

// returns a string before the \n delimiter
char* splitFileList(char* list,int fileWanted)
{

    char *file = NULL;
    int count=0;
    int round =0;
    int found =0;
    int i ;
    int j = 0;
    int num = 0;
    char* location = list;
    for(i = 0; i < strlen(list); i++)
    {
        if (*(location)=='\n')
        {
            round++;
            // reset the count to begin counting from 0
            // special case for the file file
            
            if (fileWanted == 0)
            {
                location = location+i+1;
                file = malloc(sizeof(char)*i+1);
                strncpy(file, list,i);
                *(file+i) = '\0';
                return file;
                
            }
            if (round == fileWanted) // if we want the file after new line number round
            {
                found = 1; // we set a flag
                // count until the next '\n' and keep track of size of the file
                for(j = 0; j < strlen(list); j++)
                {
                    num++;// the number of character to the next new line character - length of next string
                    if (*(location+j+1)=='\n') // the next new line character
                        
                    {
                        count = num; // record to size of the character
                        break;
                    }
                }
            }
        }

        // in linear order we want file number x speicified by the user so keep track of position
        
        if (fileWanted==round && found ==1 && fileWanted!= 0 ) // we want the file number x from the list of files
        {
            break;
        }

        location = location +1;
    
    }
    // copy that amount of characters to the string file with strncopy
    file = malloc(sizeof(char)*count+1);
    // location = list+state+1;
    strncpy(file,location+1,count);
    // null terminate the file
    *(file+count-1) = '\0';

    //return file before the "\n character "
    return file;

    
}


char* getHashFile(int position,PeerInfo peer)
{
    //assert(peer.hashTable[position].position== position); // make sure we are in the same position in the array
    return peer.hashTable[position].file;
    
}



/*
 ***********************************************************
 START OF  LINKED LIST IMPLEMENTATION
 ***********************************************************
 */

// starts a line new list
node *createList(Line peerLine)
{
    
    node *ptr = ( node*)malloc(sizeof(node));
    if(NULL == ptr)
    {
        printError("Error creating linked list");
    }
    
    //set the values for the collection list
    strcpy( ptr->line.filename,  peerLine.filename);
    strcpy(ptr->line.ip ,peerLine.ip);
    ptr->line.portNum = peerLine.portNum;
    ptr->line.posiiton = peerLine.posiiton;
    ptr->next = NULL;
    
    head = curr = ptr;
    
    return ptr;
    
}

// appends a line to the end of the list
node* addLine(Line peerLine)
{
    
    if(NULL == head)
    {
        totalFileCount++; // update node count
        return createList(peerLine); // if its teh first value on the list....
      
    }
    
    node *ptr = (node *)malloc(sizeof(node));
    if(NULL == ptr)
    {
        printError("Could not create node to add to list \n\n");
    }
    
    //set the values for the collection list
    strcpy( ptr->line.filename,  peerLine.filename);
    strcpy(ptr->line.ip ,peerLine.ip);
    ptr->line.portNum = peerLine.portNum;
    ptr->line.posiiton = peerLine.posiiton;
    ptr->next = NULL;
    
    // add the node to the end of the list
    curr->next = ptr;
    curr = ptr;
    totalFileCount++;
    return ptr;
}

// finds a line
node* locateLine(char* ip,node **prev, int portNum)
{
    node *ptr = head;
    node *tmp = NULL;
    int  found = 0;
    
    while(ptr != NULL)
    {
        if(strstr(ptr->line.ip, ip) != NULL && ptr->line.portNum == portNum) // if the ip of the line
        {
         // for debbuging purposes.. flag the line    printf("\n Found line with ip [%s] \n",ip);
            found = 1;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    
    if(found == 1 )
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

node* locateFile(int posNum,node **prev)
{

node *ptr = head;
node *tmp = NULL;
int  found = 0;

while(ptr != NULL)
{
    if(ptr->line.posiiton == posNum) // if the ip of the line
    {
        // for debbuging purposes.. flag the line    printf("\n Found line with ip [%s] \n",ip);
        found = 1;
        break;
    }
    else
    {
        tmp = ptr;
        ptr = ptr->next;
    }
}

if(found ==1 )
{
    if(prev)
        *prev = tmp;
        return ptr;
}
else
{
    return NULL;
}
    
}

// deletes all the lines with the ip from the list of lines
int removePeer(int lineNum, char* ip,int portNum)
{
    int count = 0;
    
    while (count < lineNum) // While there are still lines with that ip
    {
        // delete all the lines
        node *prev = NULL;
        node *del = NULL;
        
        del = locateLine(ip,&prev,portNum);
        if(del == NULL)
        {
            return -1;
        }
        else
            
        {
           // for debbuing purposes  printf("\n Deleting line with ip [%s] from list\n",ip);
            if(prev != NULL)
                prev->next = del->next;
            
            if(del == curr)
            {
                curr = prev;
            }
            else if(del == head)
            {
                head = del->next;
            }
        }
        
        free(del);
        del = NULL;
        count++;
        totalFileCount--;
    }
    
    if (totalFileCount ==0 &&head->next== NULL)
    {
        totalFileCount=0; // set the list to ZERO 
        head = NULL;// if there are no files reset the head
        curr = NULL;
    }
    
    return 0;
}


// writes the list given the total number of files, also updates the position umbers for each peer
char* writeList(int totalFileNum)
{
    char list[4096];
    char line[100]; // asume there ising a huge file name.....
    bzero(list, sizeof(list));
    int i;
    node *ptr = head;
    
    for(i = 0; i < totalFileNum; i++)
    {
        ptr->line.posiiton = i; // reset the file positions according to the list
        bzero(line, sizeof(line)); // reset buffer
        sprintf(line, "[%d] %s %s:%d\n",i,ptr->line.filename,ptr->line.ip,ptr->line.portNum);
        
        strcat(list, line);
        ptr = ptr->next;
        
    }
    
    char*p = malloc(sizeof(char)*strlen(list));
    strcpy(p, list);
    return p;
    
    
}
// gives back a line from the linked list given a position number
char * getLine(int pos)
{
    char*p = NULL;
    // delete all the lines
    node *prev = NULL;
    node *node = NULL;
    
    node = locateFile(pos,&prev);
    if(node == NULL)
    {
        printError("Node with file not found");
    }
    
    else
    {
        
        char line[100];
        bzero(line, 0);
        sprintf(line, "[%d] %s %s:%d\n",pos,node->line.filename,node->line.ip,node->line.portNum);
        p = malloc(sizeof(char)*strlen(line));
        strcpy(p, line);
        return p;
    }
    
    return p;
}


/*
 ***********************************************************
    END OF  LINKED LIST IMPLEMENTATION
 ***********************************************************
 */


/*
 ***********************************************************
            START OF  SERVER  FUNCTIONS
 ***********************************************************
 */

// Thread to run server in the background of client
void* runServer(void* serverInfo)
{
    int tcount = 0;
    pthread_t thread_id[10]; // supports 10 threads for now...
    Server server = *(Server*)(serverInfo); // convert paramater to struct type
    int sockfd = server.fd; // assign the server fd to local variable
    int serverPort = server.port; // assign server port to local variable
    
    char clientAddress[INET6_ADDRSTRLEN]; // used to store ip address of the client
    int newsockfd; // for the new processes that will be spawned
    struct sockaddr_in serv_addr, clt_addr; // struct used for the socket to connect
    socklen_t addrlen;

    // Create a socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printError("Failed to open socket.\n");
    }
    
    else
    { // Needed for debbuging
        //   printf("Creating socket...\n");
        
    }
    
    // set deaults for server network values
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; //adress format is IP adresses
    serv_addr.sin_addr.s_addr = INADDR_ANY; // IPV4 or IPV6
    serv_addr.sin_port = htons(serverPort); // set server network port(host to network short)
    
    //binds socket to host program given file descriptor and server address values
    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printError("Could not bind socket to host..\nChoose different port");
    }
    else
    {
        // Needed for debugging
        //    printf("Binding server socket to port %d...\n", serverPort);
    }
    
    // start listening from the socket we just set up
    if(listen(sockfd, 10) < 0)
    {
        //assert that we started listening
        printError("Could not start listening on specified socket.");
    }
    
    addrlen = sizeof(clt_addr);
    
        //create a new file descriptor with the clients address
    while ((newsockfd = accept(sockfd, (struct sockaddr*)&clt_addr, &addrlen)))
    {
        if(newsockfd < 0)
        {
            printError("Can't accept client socket");
        }
        // code to get client IP
        void *clientIP;
        struct in_addr ip = clt_addr.sin_addr;
        clientIP = &ip.s_addr;
        //convert to string
        inet_ntop(AF_INET, clientIP, clientAddress, sizeof clientAddress);
        
       // printf("\nConnection established from peer %s ...\n", clientAddress);
        
        
        if( pthread_create( &thread_id[tcount], NULL ,(void*) serveFile, (void*)&newsockfd) < 0)
        {
            printError("Could not create peer thread..\n\n");
        }

        int i;
        tcount++; // add to the number of threads
        for (i = 0; i < tcount; i ++)
        {
         pthread_join(thread_id[i] , NULL); // wait for thread to finish then decrease thread count
            // this terminates the server so that we dont leave an open connectioin after a download 
         tcount --;
        }
    }
    
    return 0;
}

// thread to make a request to the peer server given the specified server info
void *requestFile(void *fileToGetLine)
{
    
    Line fileLine = *(Line*)(fileToGetLine);
    
    int sockfd;
    struct hostent* peer;
    struct sockaddr_in peersockaddr_in;
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0)
    {
        printError("Cannot establish a valid socket..");
    }
    
    peer = gethostbyname(fileLine.ip); // set the settings of the server
    if(!peer)
    {
        fprintf(stderr, "printError: no such host: %s\n", fileLine.ip);
        printError("Exiting..\n");    }
    
    
    printf("Creating socket..\n");
    
    // set the server adress struct to pass in connect system call
    memset(&peersockaddr_in, 0, sizeof(peersockaddr_in));
    peersockaddr_in.sin_family = AF_INET;
    peersockaddr_in.sin_addr = *((struct in_addr*)peer->h_addr);
    peersockaddr_in.sin_port = htons(fileLine.portNum);
    struct in_addr ip = peersockaddr_in.sin_addr;
    void * serverIP= &ip.s_addr;
    //convert to string
    inet_ntop(AF_INET, serverIP, fileLine.ip, sizeof(fileLine.ip));
    
    if(connect(sockfd, (struct sockaddr*)&peersockaddr_in, sizeof(peersockaddr_in)) < 0)
    {
        printError("Cannot establish server connection...");
    }
    printf("Connecting to server at %s:%d...\n",fileLine.ip,fileLine.portNum);
    
    
    // send the file name to get back
    send(sockfd, fileLine.filename, sizeof(fileLine.filename), 0);
    
    //get "get" the file requested "
    
    // get the file size
    // get file size
    int y = 0;
    read(sockfd, &y, sizeof(y));
    int x;
    x = ntohl(y);
    
    printf("Receiving %d bytes...\n",x);
    
    //open file to write to
    FILE *fPointer = fopen(fileLine.filename, "a");
    if(fPointer==NULL)
    {
        printError("Error opening file for writing..\n");
        
    }
    
    char buf[256]; // size of buffer to receive
    int fileSize = 0; // start with the buffer size
    int sum = 0;
    while (sum < x)
    {
        bzero(buf, strlen(buf)); // clear out the buffer
        
        fileSize = recv(sockfd, buf, 255,0); // receive 255 bytes from server
        sum += fileSize;
        fwrite(buf, 1,fileSize,fPointer);
    }
    fclose(fPointer);
    printf("File received.\n");
    return 0;
}

void *serveFile(void *sock)
{
    char *fileRequested; // string returned by buffer
    char buffer[256]; // for the string of the message being accepted
    int sockfd = *(int*)sock;
    
    
    // spawn new process
    // we are in the child process print for debbuging
    //printf("Peer has made a file request...\n");
   // printf("Creating a separate thread to service peer ...\n");
    
    
    // allocate memory for string command
    int cmdLength = strlen(buffer);
    fileRequested = (char*)malloc(255 * sizeof(char));
    
 
        // spawn a new thread  to handle request, send file then close fd and respawn if needed

        // read in the command from the client
        memset(buffer, 0, strlen(buffer));
        fileRequested= acceptMsg(sockfd, buffer, 255 ,&cmdLength); // listen for the file name to send back
        
       // printf("File requested is: '%s'\n",fileRequested);
        
        
        int fileSize=  getFileSize(fileRequested); // get amount of bytes to send over
       // printf("The size of %s is: %d bytes...Sending file...\n",fileRequested, fileSize);
       //printf("Sending %d byte message to client...\n",fileSize);
        
        
        // send client file size
        // send file size to server
        int num = fileSize;
        int x = htonl(num);
        write(sockfd, &x, sizeof(x));
        
        
        // printf("%d\n\n\n",x);
        
        // send file to client
        
        char buf[PATH_MAX + 1];// for real path function
        FILE *fPointer = fopen(realpath(fileRequested,buf), "r");      //open file
        if(fPointer==NULL)
        {
            printError("Error opening file for reading..\n");
            
        }
        
        unsigned char buff[256]; // declare a buffer to read from
        int buffRead = 0;
        int totalRead = 0;
        
        while (totalRead<fileSize) // while there are still bytes to send
        {
            buffRead = fread(buff,1,255,fPointer); // send 255 bytes at a time from the file
            totalRead += buffRead; // keep track of how many bytes were sent
            
            send(sockfd, buff, buffRead,0); // send the buffer
            
        }
    
      //  printf("%d byte file sent..\n",totalRead);
        fclose(fPointer);
        terminateConnection(sockfd);
        return 0;
}


/*
 ***********************************************************
            END SERVER  FUNCTIONS
 ***********************************************************
 */

/*
 ***********************************************************
    TRACKER HANDLER... HANDLES ALL  TRACKER CONNECTIONS
 ***********************************************************
 */

void *connection_handler(void * serv)
{
    char* list = malloc(sizeof(char)*4096);
    Server info  = *(Server*)(serv);
    int x = info.servCount; // the specified peer number that is requesting connection
    
    // create a new peer and store its info the the peer info data structure
    // for peer x counting up form the number spawned 
    
    // set peer info
    strcpy(peer[x].clientIP, info.ip);
    //Get the socket descriptor
    int sock = info.fd;
    
    
    // we are in the child process
    printf("Creating a separate thread for client %s ...\n",info.ip);
    
    char buffer[512]; // for the string of the message being accepted
    // allocate memory for string command
    char *clientCommand; // string returned by buffer
    char *acceptedString;
    int acptStringLength;
    int cmdLength = strlen(buffer);
    clientCommand = (char*)malloc(255 * sizeof(char));
    int wrongCommandCount = 0;
    char fileToAdd[100];
    
    // get client server port number
    int tmp = 0;
    read(sock, &tmp, sizeof(tmp));
    int clientPortNo=0 ;
    clientPortNo = ntohl(tmp);
    // set the struct accordingly
    peer[x].serverPort = clientPortNo;
    
    //get the clients local file list from peer
    bzero(buffer, strlen(buffer));
    acceptedString = acceptMsg(sock, buffer, 255,&acptStringLength); // ack from server
    printf("Received %d byte file list from peer...\n",acptStringLength);
    
    
    
    // store the file list in the data structure - need to manipulate
    strcpy(peer[x].localItemList,acceptedString);
    
    
    printf("File list added to tracker, successful.\n");
    
    int fileCount = countNewLines(acceptedString);
    
    
    
    peer[x].numFiles= fileCount;
    // update the total file countmake
    //char* fileToAdd;
    int i;
    // populate the hash map of the peer with the files in the peer directory
    for (i = 0; i < peer[x].numFiles; i++)
    {
        peer[x].hashTable[i].position =i;
        
        //allocate memory for file to add
        //fileToAdd = malloc(sizeof(char)*strlen(splitFileList(peer[x].localItemList,i)));
        
        bzero(fileToAdd,strlen(fileToAdd));
        strcpy(fileToAdd, splitFileList(peer[x].localItemList,i));
        
        peer[x].hashTable[i].file = malloc(sizeof(char)*strlen(fileToAdd));
        
        strcpy(peer[x].hashTable[i].file,fileToAdd);
        
    }
    
    // add peer to connection list
    Line peerLine ;
    // add files to collection
    for(i = 0; i < peer[x].numFiles; i++)
    {
        strcpy( peerLine.filename, getHashFile(i, peer[x]) );
        strcpy(peerLine.ip ,peer[x].clientIP);
        peerLine.portNum = peer[x].serverPort;
        peerLine.posiiton = i; // this should get overwwriten by write line method
        pthread_mutex_lock(&lock); // update total peer count ...
        addLine(peerLine);// populate the list of lines
        pthread_mutex_unlock(&lock);
    }
    
    
    do
    {
        // read in the command from the client
        memset(buffer, 0, strlen(buffer));
        clientCommand= acceptMsg(sock, buffer, 255 ,&cmdLength);
        
        // printf("Command received by peer with address %s is: '%s'\n",peer.clientIP,clientCommand);
        
        // get the server port where the client will accept connection and sabe it in its struct
        
        //perform the command passing in the child descriptor...
        if (strcmp(clientCommand, "exit") == 0 || clientCommand == NULL)
        {
            wrongCommandCount = 0; //reset connection counter
            // send exit back to peer .. confirm
            send(sock, buffer, sizeof(buffer), 0);
            // terminate connection
            printf("Terminating Connection for %s ..\n",peer[x].clientIP);
            pthread_mutex_unlock(&lock); // updating total peer count... add mutex
            removePeer(peer[x].numFiles,peer[x].clientIP,peer[x].serverPort); // update collection list
            pthread_mutex_unlock(&lock);
            terminateConnection(sock);
        }
        else if(strcmp(clientCommand, "list") == 0 )
        {
            
            // send over acknoledgement to  string
            send(sock, clientCommand ,strlen(clientCommand), 0);
            bzero(buffer, strlen(buffer));
            bzero(list, strlen(list));

            strcpy(list, writeList(totalFileCount));
            //list = writeList(totalFileCount); // print the list with all the files
            
            // send over the list of files
            send(sock,list ,strlen(list), 0);
            
            
        }
        else if(strstr(clientCommand, "download") != NULL )
        {
            // send over acknoledgement to peer
            send(sock, clientCommand ,strlen(clientCommand), 0);
           
            char fileLine[100] ;
            
            //fileLine = malloc(sizeof(char)*50));
            
            int fileNum;
            char *fileToRecv = malloc(sizeof(char)*strlen(clientCommand));
            // parse the line and get the file number of the list requested
            fileToRecv = getFileName(clientCommand);
            fileNum = atoi(fileToRecv);
            // send entire line requested back to the client ( or send and receive individually)
            
            // make sure it is a valid file
            if (fileNum<0|| fileNum>=totalFileCount)
            {
                printf("client requested invalid file \n");
                printf("sending 'error' to client\n ");
                strcpy(fileLine, "error");
                // send line back to peer for server information
                int sentVal = strlen(fileLine); // the amount of bytes sent
                if(assertSend(sock, fileLine, &sentVal) ==-1)
                {
                    printf("Bytes sent : %d\n",sentVal);
                    printError("Error send all the bytes..value sent is %d ");
                }
            }
            
            else // otherwise send file requested
            {
                strcpy(fileLine, getLine(fileNum));
                
                printf("Line requested by client : %s\nSending peer info to client...\n",fileLine);
                
                // send line back to peer for server information
                int sentVal = strlen(fileLine); // the amount of bytes sent
                if(assertSend(sock, fileLine, &sentVal) ==-1)
                {
                    printf("Bytes sent : %d\n",sentVal);
                    printError("Error send all the bytes..value sent is %d ");
                }
            }

        }
        
        else // send back exit to peer to confirm
        {
            wrongCommandCount++; // too many attempts will force close connection
            int sentVal = strlen(clientCommand);
            if(assertSend(sock, clientCommand, &sentVal) ==-1)
            {
                printf("Bytes sent : %d\n",sentVal);
                printError("Error send all the bytes..value sent is %d ");
            }
            //keep prompting client and sending messages until client receives an exit from server
            if (wrongCommandCount > 10)
            {
                wrongCommandCount = 0;
                printf("Peer %s entered too many invalid commands...\nTerminating Connection for %s..\n",peer[x].clientIP,peer[x].clientIP);
                removePeer(totalFileCount,peer[x].clientIP,peer[x].serverPort); // update the collection list
                terminateConnection(sock);
                break;
            }
        }
    } while (strcmp(clientCommand, "exit") != 0);
    return 0;
}



