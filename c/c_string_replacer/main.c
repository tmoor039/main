/*
//  main.c
    Name: Tiago Moore
    Created by T Moore on 2/28/15.
    Reviewed 10 April 2018
    File has many a modified string library for string manipulation in C

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Structure to hold our string
struct Sentence
{
    char line[1024]; // hard assumes the size of a line.. used for only the test file give.. should be dynamic 
    int lineLength;
};

//function prototypes

// return type: void
// parameters:2, one array of structs,  one int number of elements in the array
// purpose: prints the data that was read in into the array of structs
void printData(struct Sentence data[], int numberofLines);

//return type: boolean
//parameters: 2 strings , a sentence and a string to search in the sentence
//purpose: searches to see if a string is in the sentence
bool isFound( char sentence[],char*wordToSearch);

//return type: void
//parameters: two, one file pointer and one character string pointer, data array, and number of lines
//purpose: this will write an array to an output file
void createOutputFile(FILE *outputFile,char *outputFileName,struct Sentence data[],int numberofLines);

//return type: a pointer to a char , location
//parameters: 1  structs containing each line, and the string to search
//purpose: this will return the memory locaiton of the word in the line.
char *locateString(struct Sentence line , char *wordToSearch);

//return type: void
// parameters:a line that will be modified, a string to modifit it and the location of the string, and the size of the replaced word, difference
// purpose: replaces the cahracters in the array with wordToOverwrite starting at starting location
struct Sentence replace(struct Sentence Line, char*wordToOvewrite,int sizeOfReplacedWord, char *startingLocation,int difference);


int main(int argc, char * argv[])
{
    //declare and initialize variables
    FILE *inputFile ; // my input file pointer
    FILE *outputFile; // my output file pointer
    char *firstString; // the string to be found in the input file
    char *secondString; // to string to replace the first string with
    char *inputFileName; // name of input file to be taken from argv[3]
    char *outputFileName; //name of output file to be taken from argv[4]
    char nextChar; // character for traversing the text file
    int lineCount = 1; // numbers of lines ind ata file, starts at one because last new line is ignored
    char *wordlocation;
    int difference;
    
    if (argc < 5) // exit program if not enough command line arguments
    {
        printf("ERROR, the number of command line arguments is %d, you must enter 4\n", argc-1);
        exit(EXIT_FAILURE);
    }
    else if (argc > 5) // exit program if too many command line arguments
    {
        printf("ERROR, too many arguments, you entered %d, you must enter 4.\n", argc-1);
        exit(EXIT_FAILURE);
    }
    
    else
    {
        //rename our local variables
        //set the command line arguments to our local variables for easyer manipulation
        firstString = malloc(sizeof(char)*strlen(argv[1])); // allocate heap memory for the string
        strcpy(firstString, argv[1]);
        secondString = malloc(sizeof(char)*strlen(argv[2])); // allocate heap memory for the string
        strcpy(secondString, argv[2]);
        inputFileName = malloc(sizeof(char)*strlen(argv[3])); // allocate heap memory for the string
        strcpy(inputFileName, argv[3]);
        outputFileName = malloc(sizeof(char)*strlen(argv[4])); // allocate heap memory for the string
        strcpy(outputFileName, argv[4]);
        
        // open text file for reading 
        inputFile = fopen(inputFileName, "r");
        if(!inputFile)
        {
            perror("Failed to open text file.");
            exit(EXIT_FAILURE);
        }
        
        // count the number of lines to create our data 2D array
        nextChar = getc(inputFile);
        while (nextChar!=EOF)
        {
            if (nextChar == '\n')
            {
                lineCount++;
            }

            nextChar = getc(inputFile);
        }
        // reset the file index pointer
        rewind(inputFile);
        
        // create an array of structs to hold our data
        struct Sentence dataArray[lineCount];
        
        //input data into my data structure
        nextChar = getc(inputFile);
        for (int i = 0; i < lineCount && nextChar != EOF;i++)
        {
            dataArray[i].lineLength = 0;  // initialize the linelength of the line to zero;
            for (int j = 0; nextChar!= '\n'&& nextChar != EOF;j++)// until we read a new line character
            {
                dataArray[i].lineLength++;// count the number of characters that will be useful
                 dataArray[i].line[j] = nextChar; //fill the line with data
                nextChar = getc(inputFile); // increment the file index , copy into next char
            }
            // skip the new line character
            nextChar = getc(inputFile);
            // continue the loop writing the next line in our data array of structs containing a string (arra of characters)
        }
        
        // close the file pointer character stream to the beggining
        fclose(inputFile);
        
        //print data of file to console
        printData(dataArray, lineCount);
        
        // call function to find and replace all occuraces of string 2 in every sentence
        difference = (int)(strlen(secondString)-strlen(firstString));
        
        //go through all the lines and replace the letters
        for (int i = 0; i < lineCount;i++)
        {
            if (isFound(dataArray[i].line, firstString))// if the line contains the string to be replaced
            {
               wordlocation = locateString(dataArray[i], firstString); // find it
              dataArray[i]= replace(dataArray[i], secondString, (int)strlen(firstString), wordlocation,difference);// replace it
            }
        }

        printData(dataArray, lineCount);
        //output the array to a text file
        createOutputFile(outputFile, outputFileName,dataArray, lineCount);
        
    }    
    
    return 0;
}

void printData(struct Sentence data[], int numberofLines)
{
    
    printf("Data: \n");
    
    
    for(int i = 0 ; i < numberofLines;i++)
    {
        
        for (int j = 0; j <data[i].lineLength;j++ )
        {
            printf("%c", data[i].line[j]);
        }
        
        // print a new line character since the next line is at a different array index
        printf("\n");
    }
    
        printf("\n");
    
}

bool isFound(char sentence[],char*stringToSearch)
{
    //declare char variable to hold memory location of found character
    if(strstr(sentence,stringToSearch)== NULL)
    {
        return false;
    }
    // if it survived the loops, the string is in the sentence
    return true;
}

void createOutputFile(FILE *outputFile,char *outputFileName,struct Sentence data[],int numberofLines)
{
    outputFile = fopen(outputFileName, "w"); // declare file pointer to write
    
    
    for(int i = 0 ; i < numberofLines;i++)
    {
        
        for (int j = 0; j <data[i].lineLength;j++ )
        {
            fprintf(outputFile, "%c ",data[i].line[j]);
        }
        
        // print a new line character since the next line is at a different array index
        fprintf(outputFile,"\n");
    }

    fclose(outputFile); // close stream
    
}

// will return null if the character is not found, should never be null....
//**NOTE** This program will only replace the first occorance of the string in each sentence. 
char *locateString(struct Sentence line,char *wordToSearch)
{
    char *location = NULL ;
    
    //traverse the line array looking for the string
    for(int i = 0; i < line.lineLength;i++)
    {
        
        if (line.line[i] == *wordToSearch)
        {
            location = &line.line[i];// save the adress of the character in location
            
            //search for the remaining letters of the word were looking for
            for (int j = 1; j<strlen(wordToSearch); j++)
            {
                if (*(location+j)!= *(wordToSearch+j))
                {
                    //break out of this for loop, and search for the next occurance of the first letter
                    break;
                }
                if (j == (strlen(wordToSearch)-1)) // if we have not exited the loop because of a match fail
                {
                    // return the location containing the adress of the starting string we will need to replace
                    return location;
                }
            }
        }
    }
    
    
    return location;

}

struct Sentence replace(struct Sentence string, char*replacementWord,int sizeOfReplacedWord, char *startingLocation,int difference)
{

    // create a temporary array to hold our new string
    // the array will have the size of sentence plus the difference in the word being rewritten, if it is bigger
    char newLine[(string.lineLength+difference)];
    
    // get the end of the line and save it
    char *endOfLine = malloc(sizeof(char)*1024);// allocate 1024 bytes because thats what it will be at worse case(per assignment)
    
    strcpy(endOfLine,(startingLocation+sizeOfReplacedWord));// copies everythig after our replaced word to a temp string
    
    memcpy(startingLocation, replacementWord, sizeof(char)*strlen(replacementWord));// copies everything starting at a location
    
    // copy everything to new line
    strcpy(newLine, string.line);
    
    // add everything to the end of the line
    strcat(newLine, endOfLine);

    //update the stringlength to include the difference in characters
    
    string.lineLength += difference+1;
   
    struct Sentence line;
    strcpy(line.line, newLine);
    line.lineLength = (int)strlen(newLine);
    
    return line;
  
    
}






