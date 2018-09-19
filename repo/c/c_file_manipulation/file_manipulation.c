//

//  Created by Tiago Moore on 3/26/14.

//  Date : 04/16/2014
//Reviewed 8 April 2018
// program requires text file of nucleotides
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// funtion prototypes 

// return type: void
// Parameters: 1; the file to be read
// This function reads the DNA file into a a memory location(pointer) containing an character array
//void readFile( char *a[]);

// return type : void
// Parameters 2; the genome sequence( char array), and the number of nuecleotides
// Purpose:This function counts teh amount of nucleotides in the file, the first, last middle,
// as well as the amount for each nucleotide lowercase, uppercase, and other.
void countTides(char*nucleotide, int numberofTides);

// return type : int
// Parameters: 1 the number to add to
// Purpose: This function will add all numbers from 0 to 100 using a formula
int SumOfDigits(int n);

// return type: void
// Parameters: 1 the file being manipulated
// Purpose: Additional practice for manipulating text files
void createTextFile(FILE *f);

// return type: void
// Parameters: 1 the binary file being manipulated
// Purpose: This function manipulates a binary file
void createBinaryFile(FILE *f);

int main()
{
    // declare and initialize variables
    FILE *dnaFile ;    // my file pointer
    int dataSize =0, i = 0 ;
    char *dnaArray;
    // read in DNA file
    dnaFile = fopen("1200.dna", "r");
    int numToAddTo = 100;

    if(dnaFile == NULL)
    {
        printf("Cannot open the file ");
        exit(0);
    }
     char nextChar  = getc(dnaFile); // character for traversing the file
    // get size of data file
    while(nextChar != EOF)
    {
        dataSize++;
        nextChar = getc(dnaFile);
    }
    // close file
    fclose(dnaFile);
    
   //create an  array in heap the size of data
    dnaArray = malloc(sizeof(int)*dataSize);
    
    //reopen file
    dnaFile = fopen("1200.dna", "r");
    // check for sucess
    if(dnaFile == NULL)
    {
        printf("Cannot open the file ");
        exit(0);
    }
    nextChar  = getc(dnaFile); // character for traversing the file
  // read every char into the array just created with sufficient memory
    while(nextChar != EOF)
    {
        dnaArray[i] = nextChar;
        i++;
        nextChar = getc(dnaFile);
    }
    // close file
    fclose(dnaFile);
    // --------------------------------------- done reading file
    // call function to count everything
    countTides(dnaArray, dataSize);
    
    printf("The sum of the digits from 1 to 100 is %d\n",SumOfDigits(numToAddTo));
    
    FILE *textFile;
    FILE *binaryFile;
    
    createTextFile(textFile);
    createBinaryFile(binaryFile);
    
    return 0;
}

void countTides(char * nuecleotide, int numberofTides)
    {
    int upperA = 0, lowerA = 0, upperC = 0, lowerC = 0, upperT = 0 , lowerT = 0 , upperG = 0 , lowerG = 0, other = 0 ,count = 0;
    char current;
    // print total, first ,last middle
    printf("There are %d nuecluotides in the file.\n",numberofTides);
    printf("The first nueclueotide in the file is : %c\n", nuecleotide[0]);
    printf("The last nueclueotide in the file is : %c\n", nuecleotide[numberofTides-2]);
    printf("The nueclueotide  exacly in the middle is : %c\n", nuecleotide[(int)ceil(numberofTides/2)]) ;// use ceiling function
    // print individual nucleotides
    while( count != numberofTides)
    {
        // get the current nucleotide
        current = nuecleotide[count];
        
        if( current == 'A')
        {
            upperA ++;
        }
        else if( current == 'C')
        {
            upperC++;
        }
        else if(current == 'T')
        {
            upperT++;
        }
        else if( current == 'G')
        {
            upperG++;
        }
        else if( current == 'a')
        {
            lowerA++;
        }
        else if(current == 't')
        {
            lowerT++;
        }
        else if( current == 'g')
        {
            lowerG++;
        }
        else if (current == 'c')
        {
            lowerC++;
        }
        else
        {
            other ++;
        }
    
        count++;
    }
    
    printf("There are:\n%d A nucleotides\t%d a nucleotides\n%d C nucleotides\t%d c nucleotides\n%d G nucleotides\t%d g nucleotides\n%d T nucleotides\t%d t nucleotides\n",upperA,lowerA,upperC,lowerC,upperG,lowerG,upperT,lowerT);
        
        printf("There are %d 'other' characters in the file.\n",other );
}

int SumOfDigits(int n)
{
    //declare and initiliaze variables
    int total = 0;
    // apply the formula
    //(1 plus N quantity) times (N divided by 2)
    total = (n+1)*(n/2);
    return total;
}

void createTextFile(FILE *f)
{
    int count = 0;
    f = fopen("text.txt", "w");
    
    // write to the file one number per record
    for (count = 1;count<=5;count++)
    {
        fprintf(f,"%d\n",count);
    }
    // close file
    fclose(f);
    
    // open file for reading
    f = fopen("text.txt", "r");
    
    if(f == NULL)
    {
        printf("Cannot open text.txt");
        exit(0);
    }
    else
    {
        printf("File text.txt created\n");
    }
    // funciton gets a file pointer and returns an int reading a single char from file
    int  a = fgetc(f);
    while(a != EOF)// while not end of file
    {
        printf("%c",a);
        a = fgetc(f);
        if(a == '\n')  // if a is a new line character,
        a =' ';//replace it with a space
    }
    fclose(f);
    
}
    
void createBinaryFile(FILE *f)
{
    int i = 0;

    printf("\nBinary File binText.bin created");
    
    f = fopen("binText.bin", "wb");// open file for output
    if( f == NULL)
    {
        printf("Cannot open binText.bin");
        exit(0);
    }

    char *letters = "a\nb\nc\nd\ne";// declare char with letters
    
    fwrite(letters,sizeof(char),12,f); // write one letter of the char array per line
    
    fclose(f); // close file

    f = fopen("binText.bin", "rb+");// open file for reading
    if( f == NULL)
    {
        printf("Cannot open binText.bin");
        exit(0);
    }
    
    int j = 0;
    for(j = 0; j < 9 ; j++)
    {
        fread(&i,sizeof(char),1,f); // read each charater
        if(i == 10)// if its a new line
        {
        printf(" "); // replace it with a space
        }
        else
        {
        printf("%c",i);// print the character
        }
}
 
    printf("\n");
    
    fclose(f);
}



    
    
    
    

