#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "udpheader.h"

void syserr(char *msg) { perror(msg); exit(-1);}

int main(int argc, char *argv[])
{
    int ackArr[1000] = {0};
    int check = 0; // for the checksum of the data received
    char receivedData [1024];
    double packetsExpected = 0;
    double currentAck = 0;
    int firstpacket = 0;
    char * fileName;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, clt_addr;
    socklen_t addrlen;
    
    
    //items for 60 second timeout
    fd_set          readfds;    // descriptor set
    struct timeval  timeout;    // Time out value
    
    if(argc != 3) {
        fprintf(stderr,"Usage: %s <port> <file>\n", argv[0]);
        return 1;
    }
    

    // open file for reading
    char buf[PATH_MAX + 1];
    fileName = malloc(sizeof(char)*(strlen(argv[2])));
    strcpy(fileName, argv[2]);
    
    FILE *fPointer = fopen(fileName, "wb");      //open file
    if(fPointer==NULL)
    {
        printError("Error opening file for writing..\n");
        
    }

    portno = atoi(argv[1]);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) syserr("can't open socket");
    printf("create socket...\n");
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        syserr("can't bind");
    printf("bind socket to port %d...\n", portno);
    
    
    printf("Waiting on port %d...\n", portno);
    addrlen = sizeof(clt_addr);
    
    packet dataPacket; // packet to receive from sender
    packet ackPacket; // packet to send back
    memset(&ackPacket, 0, sizeof(ackPacket)); // clear out the packet
    
    FD_ZERO( &readfds );        // Reset all bits
    FD_SET ( sockfd, &readfds );     // Set the bit that corresponds to
    // socket s
    
    
    timeout.tv_sec = 60;         // Set the time out value (60 sec)
    timeout.tv_usec = 0;
    
    double pct=0;
    double prvpct = -1;
       
       while(1) // receive packets and discard until we have the packet we want
       {
           
           
            // block for 60 seconds  until receives packets from client
           if ( select ( sockfd+1, &readfds, NULL, NULL, &timeout ) == 0 )
           {
               // if we have been waiting for 60 seconds and not received anything..
               // determine if we have received all pakcets and exit program accordingly
               if ((packetsExpected ==currentAck) && firstpacket)
               {
                   printf("All packets sucessfully transmitted.\n");
                   exit(0);
               }
               else
               {
                   printf("Did not receive all packets.");
                 //  exit(1);
               }
               timeout.tv_sec = 60;         // Set the time out value (60 sec)
               timeout.tv_usec = 0;
            }
           
        else
        {
                bzero(receivedData, 1024);
                // declare a packet to receive
                memset(&dataPacket, 0, sizeof(dataPacket)); // clear out the packet
                memset(&ackPacket, 0, sizeof(ackPacket)); // clear out the packet
            
                // sender is still sending more data
                n = recvfrom(sockfd, &dataPacket, sizeof (dataPacket), 0, (struct sockaddr *) &clt_addr, &addrlen);
                // validate packet reception
                if(n < 0) syserr("Error receiving packet\n");
                

                dataPacket.totalPacketNum = ntohs(dataPacket.totalPacketNum);
                dataPacket.packetNum = ntohs(dataPacket.packetNum);
                dataPacket.checkSum = ntohs(dataPacket.checkSum);
                dataPacket.dataLength = ntohs(dataPacket.dataLength);
                memcpy(receivedData, dataPacket.data,dataPacket.dataLength);
                // make sure no data was corrupted
                check = calculateCheckSum(receivedData);

            
                // first incomming packet.. record total num of packets
                if (firstpacket == 0)
                {
                    // should only enter here once
                    firstpacket = 1;
                    packetsExpected = dataPacket.totalPacketNum;
                    
                }
            
                   // if it is the packet in the sequence
                   if (currentAck == dataPacket.packetNum && check == dataPacket.checkSum)
                   {
                     //  printf("ACK %d: \n",currentAck);

                       // send packet ACK pack to sender
                        
                       ackPacket.type = 1; // received
                       ackPacket.packetNum = dataPacket.packetNum;

                           // convert to host to network order
                           ackPacket.type = htons(ackPacket.type);
                           ackPacket.packetNum = htons(ackPacket.packetNum);
                           
                        // send ACK
                       int x =  sendto(sockfd, &ackPacket, sizeof(ackPacket), 0, (struct sockaddr *) &clt_addr,addrlen);
                                    
                       // write packet data to user specified file
                           
                       // increment the packet sequence number we desire
                
                    int written = fwrite(receivedData, 1,strlen(receivedData),fPointer);
                     //  printf("%s",receivedData);
                       currentAck++;
                       
                   
                   }
               else
                   
               {
                  //  printf("NACK %d, packet: %d: \n",currentAck,dataPacket.packetNum );
                   
                   // send packet NACK to sender
                   ackPacket.type = 0; // 0 for NACK
                   ackPacket.packetNum = currentAck;
                   
                   
                      // convert to host to network order
                       ackPacket.type = htons(ackPacket.type);
                       ackPacket.packetNum = htons(ackPacket.packetNum);
                   
                   // send back NACK
                 int y =  sendto(sockfd, &ackPacket, sizeof(ackPacket), 0, (struct sockaddr *) &clt_addr,addrlen);
                   
               }
            
            pct = (currentAck/packetsExpected)*100;
           if (prvpct != pct)
            {
                printf("File %.2f%% received...\n",pct);
            }
            prvpct = pct;

        }
           
   
       }
           

    close(sockfd);
    return 0;
}
