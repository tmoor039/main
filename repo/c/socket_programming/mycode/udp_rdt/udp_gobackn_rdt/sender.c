//
//  sender.c
//  homework3
//  Created by tmoore on 10/29/15.
//  Copyright © 2015 tmoore. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include "udpheader.h"

void syserr(char* msg) { perror(msg); exit(-1); }

int main(int argc, char* argv[])
{
    // declare and initialize variables
    int byteSent= 0 ; // to keep track of bytes being sent to receiver
    int windowSize = 100; // the size of the sliding window
    int totalRecv = 0; // total amount of acknowledgements received
    int numPackets = 0;  // the total number of packets based on the file
    double npckt =0 ; // for the percentage
    int fileSize = 0; // the size of the file being sent
    char* fileName; // the file name command line argument
    char buffer[1024]; // buffer for  reading / sending data
    int position = 0; // the start position of the window
    int send = 1;
    double maxAck =0; // the maximum ack received before NACK
    clock_t start_time, stop_time;
    fd_set          readfds;    // descriptor set
    struct timeval  timeout;    // Time out value
    
    int sockfd, portno, n;
    struct hostent* receiver;
    struct sockaddr_in recvr_addr; // receiver socket struct
    socklen_t addrlen;
    struct sockaddr_in sendrAddr;
    socklen_t len = sizeof sendrAddr;
 
    
    if(argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <filename>\n", argv[0]);
        return 1;
    }
    receiver = gethostbyname(argv[1]);
    if(!receiver) {
        fprintf(stderr, "ERROR: no such host: %s\n", argv[1]);
        return 2;
    }
    portno = atoi(argv[2]);
    
    // allocate memory for the file name variable
    fileName = malloc(sizeof(char)* strlen(argv[2]));
    // validate file and and copy parameter into a variable
    strcpy(fileName,argv[3]);
    char buf[PATH_MAX + 1];
    FILE *filePointer = NULL;
    
    // get the size of the file
    fileSize = getFileSize(fileName);
    
    // get the total number of packets

    numPackets = (fileSize/1024); // devide the fize size evenly
    int smallFile=0;
    // check fo file size under 1 KB
    if (numPackets == 0)
    {
        smallFile = 1;
        numPackets = 1; // only 1 file to send
       
    }
    
    // check for an odd packet and for the leftovers
    
         if( fileSize%2 != 0 && !smallFile) // if its an ood file size
         {
             numPackets++; // increase the size of file by one
         }
    
    // create an array of packets  with the size =  number of packets
    packet packetArray[numPackets];
    
    // create another  integer array  size numpackets to hold our ack values
    // int ackArray[675]= {0}; // all packets set to 0 - not received ack
    
    
    //open file for reading
    filePointer = fopen(realpath(fileName, buf), "rb");
    if (filePointer==NULL) // validate file name
    {
        printf("File does not   exist in sender directory.\n");
        exit(1); // termiate on error
    }
    
    // populate the data structure
    int i;
    int buffRead; // to keep track of bytes read from file
    for( i = 0; i < numPackets; i ++)
    {
         packetArray[i].packetNum  = i;
         packetArray[i].totalPacketNum = numPackets;
        
        // read 1 kb from the file
        buffRead = fread(buffer,1,1023,filePointer);
        packetArray[i].dataLength = buffRead;
        buffer[buffRead] = '\0';
        // store it in the data segment
        memcpy(packetArray[i].data, buffer,1024);
        packetArray[i].data[buffRead] = '\0'; // null terminate the data array
        // calculate checkSum
        packetArray[i].checkSum = calculateCheckSum(packetArray[i].data);
      //  printf("%d\n",packetArray[i].checkSum);
        // zero out the buffer
        bzero(buffer, 1024);
        buffRead = 0;
        
    }
    
    // create sender socket
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd < 0) syserr("can't open socket");
    printf("create socket...\n");
    
    memset(&recvr_addr, 0, sizeof(recvr_addr));
    recvr_addr.sin_family = AF_INET;
    recvr_addr.sin_addr = *((struct in_addr*)receiver->h_addr);
    /*memcpy(&receiver->h_addr, &recvr_addr.sin_addr.s_addr, receiver->h_length);*/
    recvr_addr.sin_port = htons(portno);
    
    /* -----------------------------------------
     Setup the descriptor set for select()
     ----------------------------------------- */
    FD_ZERO( &readfds );        // Reset all bits
    FD_SET ( sockfd, &readfds );     // Set the bit that corresponds to
    
    // setup timeout value
    timeout.tv_sec = 0;
    timeout.tv_usec = 10000; // Set the time out value (10 ms)
    
    
    // implementation for sending data to receiver
    
    // declare an acknoledgement packet
    packet dataPacket;
    packet ackPacket;
    
    // keep track of time it took to send first packe to get last ack
    
    start_time = clock();
    
    if (numPackets< windowSize) // if we have less than the window... readjut the window
    {
        windowSize = numPackets;
    }
    
    double pct= 0;
    double pvrpct=-1;
    npckt = numPackets;
    while (maxAck != numPackets-1 || smallFile)
    {
        pct = (double)(maxAck/npckt)*100;
        
        if (pvrpct != pct)
        {
            printf("File %.2f%% sent...\n",pct);
        }
        pvrpct = pct;

        
        smallFile =0; // only sending once
        
        if (send == 1) // slide the window
        {
             // set the base at the last acknoledgement packet
            position = maxAck;

            // send  all packets in  full window size
            for ( i = 0; i < windowSize; i++)
            {
                
                if(position <= (numPackets-windowSize))// check for out of bounds when sliding
                {
                    printf("sending %d \n\n\n\n",position+i);
                    dataPacket = packetArray[position+i]; // the position indicates the position in the array
                }
                
                // if within the last 100.. send the last window
                else
                {
                    dataPacket = packetArray[(numPackets-windowSize)+i];
                }
                
            int dataSize = dataPacket.dataLength; // get the size of the char array to send (could be less than 1k for last packet )
            // covert interger values to host to network for portability
            dataPacket.packetNum = htons(dataPacket.packetNum);
            dataPacket.checkSum = htons(dataPacket.checkSum);
            dataPacket.totalPacketNum = htons(dataPacket.totalPacketNum);
            dataPacket.dataLength = htons(dataPacket.dataLength);
                
            byteSent = sendto(sockfd, &dataPacket, (sizeof (int) * 5) + dataSize, 0, (struct sockaddr *) &recvr_addr,sizeof (recvr_addr));
            
            //printf("sent %d byte packet to receiver..\n",strlen(dataPacket.data));
                if(byteSent != (sizeof (int) * 5) + dataSize)
                {
                    printf("Error sending all packet bytes");
                }
            }
        }
        // receive acknologments packet for window sent

        if ( select ( sockfd+1, &readfds, NULL, NULL, &timeout ) == 0 ) // if we do not receive an ack
        {
                // resend the data
                // send  all packets in full window size
              position = maxAck;
                for ( i = 0; i < windowSize; i++)
                    {
                    if(position <= (numPackets-windowSize))// check for out of bounds when sliding
                    {
                        dataPacket = packetArray[position+i]; // the position indicates the position in the array
                    }
                    
                    // if within the last 100.. send the last window
                    else
                    {
                        dataPacket = packetArray[(numPackets-windowSize)+i];
                    }
                    
                    int dataSize = dataPacket.dataLength; // get the size of the char array to send (could be less than 1k for last packet )
                    // covert interger values to host to network for portability
                    dataPacket.packetNum = htons(dataPacket.packetNum);
                    dataPacket.checkSum = htons(dataPacket.checkSum);
                    dataPacket.totalPacketNum = htons(dataPacket.totalPacketNum);
                    dataPacket.dataLength = htons(dataPacket.dataLength);
                    
                    byteSent = sendto(sockfd, &dataPacket, (sizeof (int) * 5) + dataSize, 0, (struct sockaddr *) &recvr_addr,sizeof (recvr_addr));
                    
                    //printf("sent %d byte packet to receiver..\n",strlen(dataPacket.data));
                    if(byteSent != (sizeof (int) * 5) + dataSize)
                    {
                        printf("Error sending all packet bytes");
                    }
                 
                }
            // reset timeout value
            timeout.tv_sec = 0;
            timeout.tv_usec = 10000;
            
        }
        else
        {
            // slide window to the first NACK
            send = 0;
            
            // keep receiving until we get an NACK
            int n = recvfrom(sockfd, &ackPacket, sizeof (ackPacket), 0, (struct sockaddr *) &sendrAddr,&len);
            // validate packet reception
            if(n < 0) syserr("Error receiving ACK\n");
            
            // we have received an ack
            ackPacket.packetNum = ntohs(ackPacket.packetNum);
            ackPacket.type = ntohs(ackPacket.type);
            
            // check the ack type
            
            if (ackPacket.type == 1) // received positive ack
            {
                printf("Recv ACK %d: \n",ackPacket.packetNum);

                if (maxAck<=ackPacket.packetNum) // if this ack is the highest packet received
                {
                    maxAck  = ackPacket.packetNum; // let the sender know so it can slide window
                }
                
                if (maxAck == (windowSize+position-1)) // all packets in the window were sussefully sent
                {
                    position = maxAck; // set the position
                    send =1;
                }

            }
            else if (ackPacket.type == 0) // we have an NACK
            {
                
               // printf("Recv NACK %d: \n",ackPacket.packetNum);

                // check to see if we have a max ack greater than the NACK
                if (maxAck<= ackPacket.packetNum)
                {
            
                    //set window to NACK position and resend
                    maxAck = ackPacket.packetNum;
                    send = 1; // flag to slide the window
                }
                
                // if ack packet got lost, but we have a higher ack packet
                // we know receiver got the data, so ignore the fact NACK
            }
            else
            {
                printf("Error receiving ack..\n\n");
            }
    
            
        }
    }
    stop_time = clock();
    // total time it took to get first packet, to the time it took to get last packet
    //
    double diff = (double)( stop_time - start_time ) / CLOCKS_PER_SEC;
    // bytes of file times 8 for bits devided by time gives ur bits per second 
    double throughput = (fileSize*8)/diff;
    
    throughput = throughput/1024;

    if(maxAck == numPackets-1)
    {
        position = maxAck;
        for ( i = 0; i < windowSize; i++)
        {
            if(position <= (numPackets-windowSize))// check for out of bounds when sliding
            {
                dataPacket = packetArray[position+i]; // the position indicates the position in the array
            }
            
            // if within the last 100.. send the last window
            else
            {
                dataPacket = packetArray[(numPackets-windowSize)+i];
            }
            
            int dataSize = dataPacket.dataLength; // get the size of the char array to send (could be less than 1k for last packet )
            // covert interger values to host to network for portability
            dataPacket.packetNum = htons(dataPacket.packetNum);
            dataPacket.checkSum = htons(dataPacket.checkSum);
            dataPacket.totalPacketNum = htons(dataPacket.totalPacketNum);
            dataPacket.dataLength = htons(dataPacket.dataLength);
            
            byteSent = sendto(sockfd, &dataPacket, (sizeof (int) * 5) + dataSize, 0, (struct sockaddr *) &recvr_addr,sizeof (recvr_addr));
            
            //printf("sent %d byte packet to receiver..\n",strlen(dataPacket.data));
            if(byteSent != (sizeof (int) * 5) + dataSize)
            {
                printf("Error sending all packet bytes");
            }
            
        }

         printf("File 100%% sent\n");
    }
    
    printf("Throughput time = %.0f Kbps\n", throughput);
    
    close(sockfd);
    return 0;
}
