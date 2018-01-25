#include "tcpheader.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    int sockfd, portno; // n is the amount of bytes returned by send function
    struct hostent* server;
    struct sockaddr_in serv_addr;
    char buffer[256];
    void *serverIP;
    char serverAddress[INET6_ADDRSTRLEN]; // used to store ip address of the client
    char *acceptedString;
    int acptStringLength;
    int originalMsgLength;
    DIR *folder; // reference to represent directory stream
    struct dirent *directoryStruct; //store directory information
    int remoteFlag =0; // if the client command is lsmote... set flag
    int putFlag = 0;
    char *fileToRecv = NULL;
    char *fileToUpload = NULL;


  if(argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }
  server = gethostbyname(argv[1]); // set the settings of the server
  if(!server)
  {
    fprintf(stderr, "printError: no such host: %s\n", argv[1]);
    return 2;
  }
  portno = atoi(argv[2]); // get port number from command line

  sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if(sockfd < 0)
  {
      printError("Cannot establish a valid socket..");
  }
    
  printf("Creating socket..\n");

    // set the server adress struct to pass in connect system call
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr = *((struct in_addr*)server->h_addr);
  serv_addr.sin_port = htons(portno);
  struct in_addr ip = serv_addr.sin_addr;
  serverIP= &ip.s_addr;
  //convert to string
  inet_ntop(AF_INET, serverIP, serverAddress, sizeof serverAddress);

  if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
  {
    printError("Cannot establish server connection...");
  }
  printf("Connecting to server at %s:%d...\n",serverAddress,portno);

    // promt and send until message returned is "exit"
    
   do
   {
    // reset remote flag
    remoteFlag =0;
       
       bzero(buffer, strlen(buffer));
  //Read in command from client to send to the user
  printf("%s:%d>",argv[1],portno);
  fgets(buffer, 255, stdin);
  originalMsgLength = strlen(buffer);
  char* originalMsg = malloc(strlen(buffer)*sizeof(char)); // turns to garbadge string parser functions modifies memory 
  strcpy(originalMsg, buffer);

    if(originalMsgLength>0 && buffer[originalMsgLength-1] == '\n')
    {
        buffer[originalMsgLength-1] = '\0'; // forces the terminating character to the end of string(replaces /n with /0
    }
    
   int sentVal = strlen(buffer);
   if(assertSend(sockfd, buffer, &sentVal) ==-1)
      {
          printf("Bytes sent : %d\n",sentVal);
          printError("Error send all the bytes.");
      }

       printf("Sending command to server...\n");
       printf("Waiting for reply...\n");

        acceptedString = buffer;
       // set flags for client reception
       if (strcmp(acceptedString, "ls-remote")==0)
       {
           remoteFlag =1 ;
       }
       
       if (strstr(acceptedString ,"get")!= NULL) // if client wants get command... get file name to retrieve
       {
           fileToRecv = getFileName(originalMsg);

           // get rid of new line character
            char p[strlen(originalMsg)];
           strcpy(p, fileToRecv);
           int len = strlen(p);
           p[len-1] = '\0';
           strcpy(fileToRecv, p);
           
           
       }
       
       if (strstr(acceptedString ,"put")!= NULL) // if client wants get command... get file name to retrieve
       {
           putFlag=1;
           fileToUpload = getFileName(originalMsg);
           
           // get rid of new line character
           char p[strlen(originalMsg)];
           strcpy(p, fileToUpload);
           int len = strlen(p);
           p[len-1] = '\0';
           strcpy(fileToUpload, p);
           
           
       }

       
    //waiting to receive
    
       // for now buffer length is set to 255....
     
       bzero(buffer, strlen(buffer));
       
       acceptedString = acceptMsg(sockfd, buffer, 255,&acptStringLength); // ack from server
       
       // bring the message accepted by server for debugging purposes 
      // printf("Received %d bytes from server...\n",acptStringLength);
       
       // print the list of files in
       if (remoteFlag==1)
       {
           printf("%s",acceptedString);
       }
       // if the reply for server is a command to the client...
       if (strcmp(acceptedString, "ls-local")==0)
       {
           acceptedString  = listFiles(directoryStruct, folder);
           printf("%s",acceptedString);
       }
       
       if (strcmp(acceptedString, "fail")==0)
       {
           printf("Command declined... file does not exist in current server directory.\n");
       }
       
       else if(strcmp(acceptedString, "success")==0)
       {

           // get the file size
           // get file size
           int y = 0;
           read(sockfd, &y, sizeof(y));
           int x;
           x = ntohl(y);
           
           printf("%d\n\n\n",x);
           
           //open file to write to
           FILE *fPointer = fopen(fileToRecv, "a");
           if(fPointer==NULL)
           {
               printf("Error opening file for writing..\n");
               return -1;
           }
           
           char buff[256]; // size of buffer to receive
           int fileSize = 0; // start with the buffer size
           int sum = 0;
           while (sum < x)
           {
           bzero(buff, strlen(buff)); // clear out the buffer
               
            fileSize = recv(sockfd, buff, 255,0); // receive 255 bytes from server
            sum += fileSize;
           fwrite(buff, 1,fileSize,fPointer);
           }
           fclose(fPointer);
           
       }
       
       if (strcmp(acceptedString,"upload")==0) // received handhsake from server.. send file
       {
          

           char buf[PATH_MAX + 1];// for real path function
           FILE *fPointer = fopen(realpath(fileToUpload,buf), "r");      //open file
           if(fPointer==NULL)
           {
               printf("Error opening file for reading..\n");
               return -1;
           }

           int  fileSize=  getFileSize(fileToUpload); // get amount of bytes to send over
           
           
           // send file size to server
           int num = fileSize;
           int x = htonl(num);
           write(sockfd, &x, sizeof(x));
           
           printf("%d\n\n",x);
           
           
           printf("The size of %s is: %d bytes...Sending file to server...\n",fileToUpload,fileSize);
           
           unsigned char buff[256]; // declare a buffer to read from
           int buffRead = 0;
           int totalRead = 0;
           
           while (totalRead<fileSize) // while there are still bytes to send
           {
               buffRead = fread(buff,1,255,fPointer); // send 255 bytes at a time from the file
               totalRead += buffRead; // keep track of how many bytes were sent
               
               send(sockfd, buff, buffRead,0); // send the buffer
           }
           fclose(fPointer);


           
       }

       
       
       
       
       
       
       
    
   }while (strcmp(acceptedString, "exit") != 0);
    
  printf("Goodbye...Terminating Connection...\n");
    
    
  close(sockfd);
  return 0;
}


