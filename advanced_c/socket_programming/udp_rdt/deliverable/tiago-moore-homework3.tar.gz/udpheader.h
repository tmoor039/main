//
//  udpheader.h
//  homework3
//
//  Created by tmoore on 10/29/15.
//  Copyright © 2015 tmoore. All rights reserved.
//

#ifndef udpheader_h
#define udpheader_h

#include <stdio.h>

#endif /* udpheader_h */


/*
 This struct defines a segment to be sent over the network
 */
typedef struct Segment
{
    int type; //for ack.. 0 = NACK 1 = ACK
    int totalPacketNum;
    int packetNum;
    int checkSum;
    char data [1024];
    int dataLength;
    
}packet;

/*
 ***********************************************************
                        RDT UDP FUNCTIONS
 ***********************************************************
*/

// Purpose: This functions gives us the size of a file given the file name
// Parameters: 1 character String - The name of the file
// Returns: The size of the file as an integer (# of bytes)
int getFileSize(char *fileName);


// Purpose: this function outputs the error message and exits with a failure code
void printError(char *msg);

//Purpose: This function will calculate the checksum
int calculateCheckSum(char data[]);




