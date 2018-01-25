

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "tcpheader.h"
#include <assert.h>
#include  <limits.h>

int main(int argc, char *argv[])
{
    //declare required local variables for socket connection
    int sockfd; // file descriptor
    int newsockfd; // file descriptor for new connection
    int portno; // the port number for the socket
    char clientAddress[INET6_ADDRSTRLEN]; // used to store ip address of the client
    int pid; // process id's
    char *clientCommand; // string returned by buffer
    char buffer[256]; // for the string of the message being accepted
    int bytesSent; // to keep track of when we use send()
    int wrongCommandCount = 0;
    DIR *folder; // reference to represent directory stream
    struct dirent *directoryStruct; //store directory information
    int sentVal ;// to be used with assertSend
    struct sockaddr_in serv_addr, clt_addr; // struct used for the socket to connect
    socklen_t addrlen; // the length of the socket
     char getFlag[8]; // flag to send to client if file does not exit in server
    int fileSize;
    char * fileToRecv;
    
    // sanity check
    
    if(argc != 2)
    {
        printf("Port not specified...\nSpecifying default port to 5555\n");
        
        portno = 5555;
        
    }
    else
    {
        // Make sure that port number entered is in the range 0x0000–0xFFFF
        assert(atoi(argv[1]) >= 0 && atoi(argv[1]) <= 65535);
        
        // Assign the user specifed port to local variable
        portno = atoi(argv[1]);
    }
    
    
    // Create a socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printError("Failed to open socket.\n");
    }
    
    else
    {
        printf("Creating socket...\n");
        
    }
    
    // set deaults for server network values
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; //adress format is IP adresses
    serv_addr.sin_addr.s_addr = INADDR_ANY; // IPV4 or IPV6
    serv_addr.sin_port = htons(portno); // set server network port(host to network short)
    
    //binds socket to host program given file descriptor and server address values
    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printError("Could not bind socket to host..");
    }
    else
    {
        printf("Binding socket to port %d...\n", portno);
    }
    
    // start listening from the socket we just set up
    if(listen(sockfd, 10)< 0)
    {
        //assert that we started listening
        printError("Could not start listening on specified socket.");
    }
    
    addrlen = sizeof(clt_addr);
    
    while(1) //loop forever.... server is running
    {
        printf("\nServer is running on port %d...\n", portno);
        
        printf("Waiting for clients...\n");
        
        //create a new file descriptor with the clients address
        newsockfd = accept(sockfd, (struct sockaddr*)&clt_addr, &addrlen);
        
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
        
        printf("\nConnection established from I.P %s ...\n", clientAddress);
        pid = fork();
        
        
        // spawn new process
        
        
        if(pid<0) // check for fork sucess
        {
            printError("Error creating new process.\n");
        }
        if (pid == 0)
        {
            // we are in the child process
            printf("Creating a separate process for client %s ...\n",clientAddress);
            
            close(sockfd); // close the file descriptor for the server socket ... since child inherited from parent program
            
            // allocate memory for string command
            int cmdLength = strlen(buffer);
            clientCommand = (char*)malloc(255 * sizeof(char));
            
            do
            {
                // read in the command from the client
                
                memset(buffer, 0, strlen(buffer));
                clientCommand= acceptMsg(newsockfd, buffer, 255 ,&cmdLength);
                
                printf("Command receivedls by client with address %s is: '%s'\n",clientAddress,clientCommand);
                
                //perform the command passing in the child descriptor...
                
                if (strcmp(clientCommand, "exit") == 0 || clientCommand == NULL)
                {
                    wrongCommandCount = 0; // client entered valid command reset connection counter
                   
                    // send exit back to client .. confirm
                     bytesSent = send(newsockfd, buffer, sizeof(buffer), 0);
                    // terminate connection
                    printf("Terminating Connection for %s ..\n",clientAddress);
                    terminateConnection(newsockfd);
                }
                else if (strcmp(clientCommand, "ls-local") == 0)
                {
                    wrongCommandCount = 0; // client entered valid command reset connection counter
                   bytesSent = send(newsockfd, clientCommand,strlen(clientCommand), 0);
                    printf("Sending %d byte reply to client...\n",bytesSent);
                }
                else if (strcmp(clientCommand, "ls-remote") == 0)
                {
                    wrongCommandCount = 0; // client entered valid command reset connection counter 
                    // get files into a string
                   char *serverDirFiles = listFiles(directoryStruct, folder);
                    
                    // send string back to client
                     sentVal = strlen(serverDirFiles);
                    int val = assertSend(newsockfd, serverDirFiles, &sentVal);
                    if(val == -1)
                    {
                        printf("Bytes sent : %d\n",sentVal);
                        printError("Error send all the bytes..value sent is %d ");
                    }
 
                }
                else if (strstr(clientCommand, "get") != NULL)
                {
                    wrongCommandCount = 0; // client entered valid command reset connection counter
                    // get the file name that user wants to send
                    char *fileToSend;
                    fileToSend = getFileName(clientCommand);
                    char *serverDirFiles = listFiles(directoryStruct, folder);

                    // check if file exist within our current directory
                    if (strstr(serverDirFiles,fileToSend)== NULL)
                    {
                        // file does not exist;
                        // send error back to client
                        printf("Specified file '%s' does not exit..\n",fileToSend);
                        strcpy(getFlag, "fail");
                        bytesSent = send(newsockfd,getFlag,strlen(getFlag), 0);
                        printf("Sending %d byte 'fail' reply to client...\n",bytesSent);
                        // clear the getFlag
                        memset(getFlag,0,sizeof(getFlag));
            
                    }

                    else
                    {
                        wrongCommandCount = 0; // client entered valid command reset connection counter
                        fileSize=  getFileSize(fileToSend); // get amount of bytes to send over
                        printf("The size of %s is: %d bytes...Sending file...\n",fileToSend, fileSize);
                        strcpy(getFlag, "success");
                        bytesSent = send(newsockfd,getFlag,strlen(getFlag), 0);
                        printf("Sending %d byte message to client...\n",bytesSent);
                        memset(getFlag,0,sizeof(getFlag));
  
                        
                        // send client file size
                        // send file size to server
                        int num = fileSize;
                        int x = htonl(num);
                        write(newsockfd, &x, sizeof(x));
                        
                        
                         printf("%d\n\n\n",x);
                        
                        // send file to client
                
                        char buf[PATH_MAX + 1];// for real path function
                        FILE *fPointer = fopen(realpath(fileToSend,buf), "r");      //open file
                        if(fPointer==NULL)
                        {
                            printf("Error opening file for reading..\n");
                            return -1;
                        }

                        unsigned char buff[256]; // declare a buffer to read from
                        int buffRead = 0;
                        int totalRead = 0;
                        
                        while (totalRead<fileSize) // while there are still bytes to send
                        {
                        buffRead = fread(buff,1,255,fPointer); // send 255 bytes at a time from the file
                        totalRead += buffRead; // keep track of how many bytes were sent

                        send(newsockfd, buff, buffRead,0); // send the buffer
                        }
                        fclose(fPointer);

                    }

                }
                else if (strstr(clientCommand, "put") != NULL)
                {
                    wrongCommandCount = 0; // client entered valid command reset connection counter
                    char ack[6];
                    char* fileToRecv = getFileName(clientCommand);
                    // send acknoledgement to client
                    printf("Creating file '%s' on the server....\n",fileToRecv);
                    strcpy(getFlag, "upload");
                    bytesSent = send(newsockfd,getFlag,strlen(getFlag), 0);
                    printf("Sent %d byte acknoledgement to client...\n",bytesSent);

                    // get file size
                    int y = 0;
                    read(newsockfd, &y, sizeof(y));
                    int x;
                    x = ntohl(y);

                    FILE *fPointer = fopen(fileToRecv, "a");
                    if(fPointer==NULL)
                    {
                        printf("Error opening file for writing..\n");
                        return -1;
                    }
                    
                    char buff[256]; // size of buffer to receive
                    int fileSize = 0; // start with the buffer size
                    int sum =0;
                    
        
                    while (sum<x)
                    {
                        bzero(buff, strlen(buff)); // clear out the buffer
                        
                        fileSize = recv(newsockfd, buff, 255,0); // receive 255 bytes from server
                        sum += fileSize;
                        fwrite(buff, 1,fileSize,fPointer);

                    }

                    
                    printf("Finished uploading...\n");
                    
                    fclose(fPointer);
                    
                }
                else
                {
                    wrongCommandCount++; // too many attempts will force close connection
                    int sentVal = strlen(clientCommand);
                    if(assertSend(newsockfd, clientCommand, &sentVal) ==-1)
                    {
                        printf("Bytes sent : %d\n",sentVal);
                        printError("Error send all the bytes..value sent is %d ");
                    }

                    //keep prompting client and sending messages until client receives an exit from server
                    if (wrongCommandCount > 10)
                    {
                        wrongCommandCount = 0;
                        printf("Client %s entered too many invalid commands...Terminating Connection for %s...\n",clientAddress,clientAddress);
                        terminateConnection(newsockfd);
                        break;
                    }
                  
                 
                }
            } while (strcmp(clientCommand, "exit") != 0);
            
        }
        else
        {
            //unsued by the parent
            close(newsockfd);
        }
    }
    // should never happen because of infinite loop
    close(sockfd); //close socket for port
    return 0;
}

