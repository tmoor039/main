//
//  main.c
//  homework4
//
//  Created by tmoore on 11/21/15.
//  Copyright © 2015 tmoore. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "cipherHeader.h"

int main(int argc, const char * argv[]) {
    
    //declare and initilize variables
    int dFlag = 0;
    char*  inputFile ;
    char*  outputFile;
    char   initKey[11] ;
    char* initVector = malloc(8);
    long fileSize;
    unsigned char rightM = 15; // 00001111 to isolate right side
    // isolate the left side of the IP function into a byte
    unsigned char leftM =  240;   // 11110000 // to  isolate lemft side
    unsigned char ipRight=0;
    unsigned char ipLeft=0;
    unsigned char ipRight2=0; // for the second round fk function
    unsigned char ipLeft2=0;// for the second round fk function
    unsigned char secondFresult=0;
    unsigned char firstFresult=0;
    unsigned char cryptedByte;// the encripted byte written
    unsigned char initVec = '\0';
    unsigned char nextByte = 0;
    unsigned char cipher;
    unsigned char temp ;
    int written; // number of bytes written to file
    FILE *ifp;
    FILE *ofp;
    
    //check if argument count and argument size is correct
    if( argc > 6 || argc < 5)
    {
        printf("usage: %s [-d] <init_key> <init_vector> <original_file> <result_file>\n",argv[0]);
        return -1;
    }
    //check for decription
    if(argc == 6 && strcmp(argv[1],"-d") == 0)
    {
        dFlag = 1;

        if (strlen(argv[2]) != 10)
        {
            printf("mycipher:invalid key %s. Key must be 10 bits \n",argv[2]);
            printf("mycipher:check command line parameters. \n");
            printf("usage: %s [-d] <init_key> <init_vector> <original_file> <result_file>\n",argv[0]);
            exit(1);
            
        }
        if (strlen(argv[3]) != 8)
        {
            printf("mycipher: invalid initial vector %s. Vector is 8 bits. \n",argv[3]);
            printf("mycipher:check command line parameters. \n");
            printf("usage: %s [-d] <init_key> <init_vector> <original_file> <result_file>\n",argv[0]);
            exit(1);
        }
        // set values to local variables
        strcpy(initKey, argv[2]);
        strcpy(initVector, argv[3]);
        
        // convert the init vector to an unsinged char
        unsigned int l = (unsigned int)strtol(initVector, NULL, 2);
        initVec = l;
    }
    else if(argc == 6 && strcmp(argv[1],"-d") != 0)
    {
        printf("mycipher: unknown option %s. use -d for decription\n",argv[1]);
        exit(1);
    }
    
    if (!dFlag)
    {
        if (strlen(argv[1]) != 10)
        {
            printf("mycipher:invalid key %s. Key must be 10 bits \n",argv[1]);
            printf("mycipher:check command line parameters. \n");
            printf("usage: %s [-d] <init_key> <init_vector> <original_file> <result_file>\n",argv[0]);
            exit(1);
        }
        if (strlen(argv[2]) != 8)
        {
            printf("mycipher: invalid initial vector %s. Vector is 8 bits. \n",argv[2]);
             printf("mycipher:check command line parameters. \n");
             printf("usage: %s [-d] <init_key> <init_vector> <original_file> <result_file>\n",argv[0]);
            exit(1);
        }
        // set values to local variables
        strcpy(initKey, argv[1]);
        strcpy(initVector, argv[2]);

        // convert the init vector to an unsinged char
        unsigned int l = (unsigned int)strtol(initVector, NULL, 2);
        initVec = l;
    }
    
    //check if file is valid
    if( (ifp = fopen(argv[argc-2],"rb")) == NULL)
    {
        printf("mycipher: error opening file %s\n",argv[argc-2]);
        exit(1);
    }
    else
    {
        fclose(ifp);
        // get file size
        inputFile = malloc(50);
        strcpy(inputFile, argv[argc-2]);
        fileSize = getFileSize(inputFile);
        
        if (fileSize< 1)
        {
            printf("mycipher:file must have at least 1 byte\n");
        }
    }
    
    //declare the output file
    if( (ofp = fopen(argv[argc-1],"wb+")) == NULL )
    {
        printf("mycipher: could create output file.. %s\n",argv[argc-2]);
        return -1;
    }
    else
    {
           outputFile = malloc(50);
           // get output file name
           strcpy(outputFile, argv[argc-1]);
    }

    ///// MAIN PROGRAM STARTS HERE
    
    
    // if encryptioin
    if (!dFlag)
    {
    printf("%s contains %ld bytes\n",inputFile,fileSize);
    char buf[PATH_MAX + 1];// for real path function
    ifp = fopen(realpath(inputFile,buf), "rb");
    int buffRead = 0 ; // number of bytes read from the file
    char buff[fileSize];
    int i;

    unsigned char k1;
    unsigned char k2;
    // Key geration funcions
    permuteTen(initKey);
    //printf("%s\n",initKey);
    k1 = getK1(initKey);
    k2 = getK2(initKey);
    
    // read intire file into buffer
    buffRead= fread(buff,sizeof(char),fileSize,ifp);

    for (i = 0; i < fileSize; i++)
    {
   // nextByte = 0;
    nextByte = buff[i];
    // xor the first byte with the initialization vector
    cipher = xOr(initVec, nextByte);
  
    // perform ip on the output of the plane text and vector
        cryptedByte = 0;
            
    cryptedByte = ipFunction(cipher);
            ipRight = 0;
            ipLeft = 0;
    ipRight = cryptedByte & rightM;// gives us the left four bits
    ipLeft = cryptedByte & leftM;
    // expand and permutate ipright
            firstFresult = 0;
            
    firstFresult =  epFunction(ipRight); // check
    
    // xor the first ep result with k1
    firstFresult = xOr(firstFresult, k1);
    
    // throw the first result that was xored with k1 and thow into sbox
    //sBoxFunction
    firstFresult = fKay1(firstFresult,ipLeft,ipRight);
    
    // repeat the proceadure but using the second key
            ipRight2 = 0; // reset values to blank
            ipLeft2 = 0;
    ipRight2 = firstFresult & rightM;// gives us the left four bits
    ipLeft2 = firstFresult & leftM;
    
            secondFresult = 0 ;
    secondFresult = epFunction(ipRight2); // check
    
    // xor the first ep result with k1
    secondFresult = xOr(secondFresult, k2);
    
    // throw the second result that was xored with k1 and thow into sbox
    //sBoxFunction
    secondFresult = fKay2(secondFresult,ipLeft2,ipRight2);

    cryptedByte = 0; // reset the cripted byte
    
    //apply inverse function for final step
    
    cryptedByte = ipInverseFunction(secondFresult);

    initVec = 0;
    initVec |= cryptedByte; // set the initial vector to the ciphertext for CBC
        
    // write the crypted byte to an output file
    putc((unsigned char)cryptedByte, ofp);
        
      }
    
    }
    
    else if(dFlag) //if decryption
    {
        // open encripted file
        printf("%s contains %ld bytes\n",inputFile,fileSize);
        char buf[PATH_MAX + 1];// for real path function
        ifp = fopen(realpath(inputFile,buf), "rb");
        int buffRead = 0 ; // number of bytes read from the file
        char buff[fileSize];
        int i;
    
        unsigned char k1;
        unsigned char k2;
        // Key geration funcions
        permuteTen(initKey);
        //printf("%s\n",initKey);
        k1 = getK1(initKey);
        k2 = getK2(initKey);
        // DONE with key generation
        
        // read intire file into buffer
        buffRead= fread(buff,sizeof(char),fileSize,ifp);

        for (i = 0; i < fileSize; i++)
        {
            // nextByte = 0;
            nextByte = buff[i];
            // xor the first byte with the initialization vector
            //cipher = xOr(initVec, nextByte);
            
            // perform ip on the output of the plane text and vector
            cryptedByte = 0;
            
            cryptedByte = ipFunction(nextByte);
            ipRight = 0; // reset form last round
            ipLeft = 0;
            ipRight = cryptedByte & rightM;// gives us the left four bits
            ipLeft = cryptedByte & leftM;
            // expand and permutate ipright
            firstFresult = 0; // reset form last round
            
            firstFresult =  epFunction(ipRight); // check
            
            // xor the first ep result with k1
            firstFresult = xOr(firstFresult, k2);
            
            // throw the first result that was xored with k1 and thow into sbox
            //sBoxFunction
            firstFresult = fKay1(firstFresult,ipLeft,ipRight);
            
            // repeat the proceadure but using the second key
            ipRight2 = 0; // reset values to blank
            ipLeft2 = 0;
            ipRight2 = firstFresult & rightM;// gives us the left four bits
            ipLeft2 = firstFresult & leftM;
            
            secondFresult = 0 ; // reset from last round
            secondFresult = epFunction(ipRight2); // check
            
            // xor the first ep result with k1
            secondFresult = xOr(secondFresult, k1);
            
            // throw the second result that was xored with k1 and thow into sbox
            //sBoxFunction
            secondFresult = fKay2(secondFresult,ipLeft2,ipRight2);
            
            cryptedByte = 0; // reset the cripted byte
            
            //apply inverse function for final step
            
            cryptedByte = ipInverseFunction(secondFresult);
            
            // xor the first byte with the initialization vector
            cipher = 0;
            cipher = xOr(initVec, cryptedByte);
            
            initVec = 0;
            initVec |= nextByte; // set the initial vector to the ciphertext for CBC
            
            // write the crypted byte to an output file
            putc((unsigned char)cipher, ofp);
            
        }
 
    }
 
    fclose(ofp);
    return 0;
}

