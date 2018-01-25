#include "p2pheader.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    
    int trackerSockFd,peerSockFd, trackerPort,peerPort; // n is the amount of bytes returned by send function
    struct hostent* tracker;
    struct hostent* peer;
    struct sockaddr_in trackerSockAddr_in;
    struct sockaddr_in peersockaddr_in;
    char buffer[512];
    void *trackerIP;
    char trackerAddress[INET6_ADDRSTRLEN]; // used to store ip address of the client
    char *acceptedString;
    char *fileList;
    int acptStringLength; // the amount of by bytes received by the read function
    int originalMsgLength;
    DIR *folder; // reference to represent directory stream
    struct dirent *directoryStruct; //store directory information
    pthread_t thread_id;
  // check command line parameters
    if(argc <3)
    {
        fprintf(stderr, "Usage: %s <tracker-hostname> <tracker-port-number> <peer-port-number>\n", argv[0]);
    return 1;
    }
    
    if (strcmp(argv[1], "localhost")==0||strcmp(argv[1], "127.0.0.1")==0)
    {
        printf("Cannot connect to tracker as localhost.. you must enter a network IP. Ex: 192.168.x.x\n");
        exit(-1);
    }
    
    
    
  tracker = gethostbyname(argv[1]); // set the settings of the server
  if(!tracker)
  {
    fprintf(stderr, "printError: no such host: %s\n", argv[1]);
    return -1;

  }
   trackerPort = atoi(argv[2]); // get port number from command line


    
    if(argc <4)
    {
        //start internal serve port on port 6000
        printf("Peer port not specified ... server running on port 6000\n");
        peerPort = 6000;
    }
    else
    {
        //Store internal serve port
        peerPort = atoi(argv[3]);
    }
    
  trackerSockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if(trackerSockFd < 0)
  {
      printError("Cannot establish a valid socket for tracker..");
  }
    
  printf("Creating socket for tracker..\n");

    // set the server adress struct to pass in connect system call
  memset(&trackerSockAddr_in, 0, sizeof(trackerSockAddr_in));
  trackerSockAddr_in.sin_family = AF_INET;
  trackerSockAddr_in.sin_addr = *((struct in_addr*)tracker->h_addr);
  trackerSockAddr_in.sin_port = htons(trackerPort);
  struct in_addr ip = trackerSockAddr_in.sin_addr;
  trackerIP= &ip.s_addr;
  //convert to string
  inet_ntop(AF_INET, trackerIP, trackerAddress, sizeof trackerAddress);
    
  // make a connection to the tracker...
  if(connect(trackerSockFd, (struct sockaddr*)&trackerSockAddr_in, sizeof(trackerSockAddr_in)) < 0)
  {
    printError("Cannot establish connection to the tracker...");
  }
    
    // sucessfully connected to tracker
    printf("Connecting to tracker: %s:%d, successful.\n",trackerAddress,trackerPort);

    // send peer server port to tracker
    
    // send file size to server
    int tmp = peerPort;
    int portno = htonl(tmp);
    write(trackerSockFd, &portno, sizeof(portno)); // write the server port number to tracker fd
    
    // send file string "ls local " to tracker
    fileList  = listFiles(directoryStruct, folder);

    if(send(trackerSockFd , fileList, strlen(fileList),0)<0) // send the file list to tracker
    {
        printError("Error sending file list to tracker....terminating peer...\n");
    }
    printf("Sent file list to tracker, successful.\n");
    
    // send the number regular of files in the directory
    
    int numFiles = countFiles(fileList, directoryStruct, folder);
    
    
    Server server; // declare server to pass into thread
    server.fd = peerSockFd;
    server.port = peerPort;
    
    // run the server to service requests
    
    if( pthread_create( &thread_id, NULL ,(void*) runServer, (void*)&server) < 0)
    {
        printError("Could not create peer thread..\n\n");
    }
    

    
    printf("Now awaiting your command...\n");
    
    do // promp util exit command
    {
        do // promp util exit command
        {
            bzero(buffer, strlen(buffer)); // clear buffer
            //Read in command from client to send to the user
            printf("%s:%d>",argv[1],trackerPort);
            fgets(buffer, 512, stdin);
            
        } while (strcmp(buffer,"\n")== 0); // ingnore "Enter"
        
    originalMsgLength = strlen(buffer);
    char* originalMsg = malloc(strlen(buffer)*sizeof(char)); // turns to garbadge string parser functions modifies memory
    if(originalMsgLength>0 && buffer[originalMsgLength-1] == '\n')
    {
    buffer[originalMsgLength-1] = '\0'; // forces the terminating character to the end of string(replaces /n with /0
    }
    
    strcpy(originalMsg, buffer);
       
       
      int sentVal = strlen(buffer); // the amount of bytes sent
      if(assertSend(trackerSockFd, buffer, &sentVal) ==-1)
      {
          printf("Bytes sent : %d\n",sentVal);
          printError("Error sending all the bytes.");
      }

       printf("Sending command to tracker...\n");
       printf("Waiting for reply...\n");
    
        bzero(buffer, strlen(buffer));
        acceptedString = acceptMsg(trackerSockFd, buffer, 512,&acptStringLength); // ack from server

        
        
        // check if tracker sent back a valid command 
        
        

       if(strcmp(acceptedString, "list") == 0 ) // if the command by user is list.. recieve file list
       {
           char buff[4096];
           // wait and listen for the list of files from the server
           bzero(buff, 4096);
           acceptedString = acceptMsg(trackerSockFd, buff, 4096,&acptStringLength); // ack from server
           
           // printf("%d\n",acptStringLength);
           // accept the list from server and print it all to the client
           
           printf("%s",acceptedString);
           
       }
       else if(strstr(acceptedString, "download") != NULL ) // if the first line of the command has download..
       {
           char buff[50];
           // wait and listen for the list of files from the server
           bzero(buff, 50);
           // receive the line from tracker with peer info from server
          acceptedString = acceptMsg(trackerSockFd, buff, 50,&acptStringLength); // ack from server
           
           printf("Line requested is:%s\n",acceptedString);
           
           // if file name is "error"
           if (strcmp(acceptedString, "error")== 0)
           {
               printf("File requested does not exist in the tracker... \n");
           }
           
           else
           {
           // put all critial items in a struct
           Line filesToGet;
            int flag = 0;
           filesToGet = parseLineInfo(acceptedString);
            int i;
               // traverse te file list see if already exists
               char *p = malloc(strlen(fileList)*sizeof(char));
               char *delimiter = "\n"; // Asumming string is "HEY YOU"
               p = strtok(fileList, delimiter);

               for ( i = 0; i < numFiles; i++)
               {
  
               // check if file already exists in peer
               if (strcmp(filesToGet.filename,p)== 0)
               {
                   printf("You already have this file.\n");
                   flag = 1;
                   break;
               }
                   // Segment will point to "YOU".
                   p = strtok(NULL, delimiter);
                   
               }
               if (flag !=1)

                {
                    pthread_t peer_id;
                    // start code for "client and connect to IP needed
           
                    // spawn new thread to request a file

                    printf(" Making server request... \n")  ;
           
                    if( pthread_create( &peer_id, NULL ,(void*) requestFile, (void*)&filesToGet) < 0)
                    {
                        printError("Could create downloading thread for downloading.\n\n");
                    }
                    // wait for download to happen
                    pthread_join(peer_id , NULL);

                }
            
       }
       }
    //   acceptedString = acceptMsg(trackerSockFd, buffer, 255,&acptStringLength); // ack from server
       
   }while (strcmp(acceptedString, "exit") != 0);
    
    

    
  printf("Goodbye...Terminating Connection...\n");
     close(peerSockFd);

  close(trackerSockFd);

  return 0;
}



