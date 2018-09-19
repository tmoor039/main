
// nich cardernas implementation -- coworker 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declare functions
void myName(char array[1][26]);
void pyramid(char array[1][26]);
void parsing(char array[1][26]);

int main()
{
    //create and initialize array
    char name[1][26];
    strcpy(name[0], "N & MN % C ");
    
    //echo print
    printf("\nMy name is %s and the length of the array is %zu\n", name[0], strlen(name[0]));
    
    //call function myName
    myName(name);
    
    //call function pyramid
    pyramid(name);
    
    //reinitialize array
    strcpy(name[0], "Nicholas & MN % Cardenas ");
    
    //call function parsing
    parsing(name);
    
    //create 10x10 array
    int grid[10][10] = {};
    int totalRows = 0;
    int totalColumns = 0;
    printf("\n");
    
    //assign each index in 10x10 array.
    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            //multiply by x and y coordinate on grid and assign it to the proper index
            grid[i][j] = (i+1)*(j+1);
            
            //store multiple in variable for total calculations
            int outInt = grid[i][j];
            printf("[%3d] ", outInt);
            
            //check for rows 3,5,and 7
            if(j == 2 || j == 4 || j == 6)
            {
                totalRows = totalRows + outInt;
            }
            //check for rows 2,4, and 6
            if(i == 1 || i == 3 || i == 5)
            {
                totalColumns = totalColumns + outInt;
            }
            
        }
        
        printf("\n");
    }
    
    //output of arithmetic
    printf("\nThe total of rows 3, 5, and 7: %d", totalRows);
    printf("\nThe total of columns 2, 4, and 6: %d", totalColumns);
    printf("\nTotal of Rows - Total of Columns = %d\n", (totalRows-totalColumns));
    
    return(0);//exit program
}

void myName(char array[1][26])
{
    int length = strlen(array[0]);
    for(int i = 0; i < length; i++)
    {
        char c = array[0][i];
        if(c == '&' || c == '%')
        {
            printf("Character [%c] located at position %d is a symbol.\n", c, i);
        }
        else if(c == ' ')
        {
            printf("Character [%c] located at position %d is a space.\n", c, i);
        }
        else if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            printf("Character [%c] located at position %d is a vowel.\n", c, i);
        }
        else // if c is a consonant upper or lower case.
        {
            printf("Character [%c] located at position %d is a consonant.\n", c, i);
        }
        
    }
    
}

void pyramid(char array[1][26])
{
    //pointer to array for array manipulation to print pyramid
    char *p = array[0];
    int length = strlen(array[0]);
    
    for(int i = 0; i <= length+1; i++ )
    {
        if(i % 2 != 0 )
        {
            p[strlen(p)-1] = 0;
        }
        else
        {
            printf("\n");
            for(int j = 0; j < (length - strlen(p))/2; j++)
            {
                printf(" ");
            }
            
            printf("%2zu [%s]",strlen(p),p);
            p++;
        }
        
    }
    
    printf("\n");
}

void parsing(char array[1][26])
{
    int length = strlen(array[0]);
    
    //print array uppercase
    char temp = 0;
    char outChar = 0;
    printf("\nAll Caps: ");
    
    for(int i = 0; i < length; i++)
    {
        temp = array[0][i];
        if('a'<= temp || temp >= 'z')//if lower case
        {
            outChar = temp - ('a'-'A');
        }
        else //if not lower case
        {
            outChar = temp;
        }
        
        printf("%c", outChar);
    }
    
    printf("\n");
    
    //print array lower case
    temp = 0;
    outChar = 0;
    printf("All Lowercase: ");
    for(int i = 0; i < length; i++)
    {
        
        temp = array[0][i];
        if(temp >= 'A' && temp <= 'Z')
        {
            outChar = temp + ('a'-'A');
        }
        else
        {
            outChar = temp;
        }
        
        printf("%c", outChar);
    }
    
    printf("\n");
    
    //print array without spaces
    temp = 0;
    printf("No Spaces: ");
    for(int i = 0; i < length; i++)
    {
        
        temp = array[0][i];
        if(temp != ' ')
        {
            printf("%c", temp);
        }
    }
    
    printf("\n");
    
    //print vowels in uppercase and consonants in lower case
    outChar = 0;
    temp = 0;
    printf("Vowels Caps, Consonants Lower Case: ");
    for(int i = 0; i < length; i++)
    {
        
        temp = array[0][i];
        if(temp == '&' || temp == '%')
        {
            outChar = temp;
        }
        else if(temp == ' ')
        {
            outChar = temp;
        }
        else if((temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') && ('a'<= temp || temp >= 'z'))
        {
            outChar = temp - ('a'-'A');
        }
        else if('a'<= temp || temp >= 'z')
        {
            outChar = temp;
        }
        else if(temp >= 'A' && temp <= 'Z')
        {
            outChar = temp + ('a'-'A');
        }
        
        printf("%c", outChar);
    }
    
    printf("\n");
    
    //print array backwards
    temp = 0;
    printf("Backwards: ");
    for(int i = length - 1 ; i >= 0; i--)
    {
        temp = array[0][i];
        printf("%c", temp);
    }
    printf("\n");
    
    //print array in ascii
    temp = 0;
    printf("In ASCII: ");
    for(int i = 0; i < length; i++)
    {
        temp = array[0][i];
        int ascii = temp;
        printf("%d ", ascii);
        
    }
    printf("\n");
    
}
