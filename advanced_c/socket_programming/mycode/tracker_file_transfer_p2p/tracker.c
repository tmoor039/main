//
//  tracker.c
//  p2p
//
//  Created by tmoore on 10/3/15.
//  Copyright © 2015 tmoore. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "p2pheader.h"
#include <assert.h>
#include <limits.h>
#include <pthread.h>

 pthread_mutex_t lock;
// declare global variables
int peerCount ;


int main(int argc, char *argv[])
{
    
    //declare required local variables for socket connection
    int sockfd; // file descriptor
    int newsockfd; // file descriptor for new connection
    int portno; // the port number for the socket
    char clientAddress[INET6_ADDRSTRLEN]; // used to store ip address of the client
    struct sockaddr_in serv_addr, clt_addr; // struct used for the socket to connect
    socklen_t addrlen; // the length of the soccer
    pthread_t thread_id[200]; // supports 200 peer connectoins
    char *clientCommand; // string returned by buffer
    clientCommand = (char*)malloc(255 * sizeof(char));
   
    // sanity check
    if(argc != 2)
    {
        printf("Port not specified...\nSpecifying default port to 5000\n");
        portno = 5000;
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
        printf("Tracker is running on port %d...\n", portno);
        
        printf("Waiting for peers...\n");
        
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
        
        Server newServer;
        // save this IP in the struct
        strcpy(newServer.ip, clientAddress);
        newServer.servCount = peerCount; // tell the trhead monitor what peer we are talking about
        newServer.fd = newsockfd;
        
        
        // spawn new therad to handle new connection.. data
        if( pthread_create( &thread_id[peerCount],NULL, connection_handler , (void*)&newServer )<0)
        {
            printError("Could not create peer thread..\n\n");
        }
        // pthread_join( thread_id[peerCount] , NULL); // wait for thread to finish and populate peer connection data structure
         peerCount++;
        if(peerCount>200)
        {
            //exceeded thread limit ... terminate tracker  program
            exit(1);
        }
    }
    // should never happen because of infinite loop
    close(sockfd); //close socket for port
    return 0;
}

