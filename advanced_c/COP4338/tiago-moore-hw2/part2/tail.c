#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>


int main(int argc, char *argv[])
{
    //declare and initialize some variables
    FILE *file;
    int numlines = 0,menu,qflag=0,cflag =0,nflag=0,byteCount = 0;
    int counter= 0;
    char nextchar;
    while ((menu = getopt (argc, argv, "qc:n:")) != -1)
        switch (menu)
    {
        case 'q':
            qflag = 1;
            break;
        case 'c':
            cflag = 1;
            byteCount =atoi(optarg);
            break;
        case 'n':
            nflag=1;
            numlines =atoi(optarg);
            if (numlines == 0)
            {
                exit(0);// print nothing exit program
            }
            break;
        case '?':
            if (optopt == 'c'||optopt == 'n')
                fprintf (stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint (optopt))
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf (stderr,
                         "Unknown option character `\\x%x'.\n",
                         optopt);
            return 1;
        default:
            abort ();
    }
    
    if (nflag ==1)
    {
        //open file
        file= fopen(argv[optind], "r");
        if(file == NULL)
        {
            fprintf(stderr,"Error opening file: %s\n",argv[optind]);
            exit(1);
        }
        // declare variables to store positions
        off_t place;
        off_t position; // get starting position
        fseek(file,0,SEEK_END); // go to the end of file
        position= ftell(file);// put the psition there
        off_t endPosition= ftell(file); // store end position

        
        for(place = position; place >= 0; place --) // traverse ackwards from the end
        {
            nextchar= fgetc(file);
            if (nextchar == '\n' && (endPosition - place) > 1)
            {
                counter ++;
                if(counter == numlines) // when we reach number requested by user
                {
                    break;
                }
            }
            position--;
            fseek(file,position,SEEK_SET);
        }
        int count;
        char buff[2000];
        lseek(fileno(file),(position + 1),SEEK_SET);
        while((count= read(fileno(file),buff,2000)) > 0)
        {
            write(STDOUT_FILENO, buff, count);
        }
        fclose(file);
    }
    else if(cflag==1)
    {
        file= fopen(argv[optind], "r");
        if(file == NULL)
        {
            fprintf(stderr,"Error opening file: %s\n",argv[optind]);
            exit(1);
        }
        
        fseek(file, 0, SEEK_END);// set position to the end of the file
        long currentPosition = 0;
        currentPosition= ftell(file);
        fseek(file, currentPosition-byteCount, SEEK_SET);//set new position requested by user
        
        // output bytes
        char buffer[2000],c;
        int i;
        
        for( i = 0; i < byteCount; i ++)
        {
            c = fgetc(file);
            buffer[i] = c;
        }
        fclose(file);
        
        for (i=0; i<byteCount; i++)
        {
            printf("%c",buffer[i]);
        }
        
    }
    
    if (qflag==1)
    {
        char  nextChar;
        int numLinestoSkip = 0;
        int found = 0, j=0;
        
        //open file for reading
        file= fopen(argv[optind], "r");
        if(file == NULL)
        {
            fprintf(stderr,"Error opening file: %s\n",argv[optind]);
            exit(1);
        }
        
        nextChar  = getc(file); // character for traversing the file
        while(nextChar != EOF)
        {
            
            if (nextChar=='#')
            {
                found ++;
                numLinestoSkip ++; // gets the number of header lines to skip
            }
            if (found ==0 && nextChar == '\n')// account for lines with comments and everything else
            {
                numLinestoSkip++;
            }
            nextChar  = getc(file);         }
        // close file
        rewind(file);// go back to the beggining
        
        
        // print all the lines except the number of lines to skip
        nextChar  = getc(file);  // start again at the beggining
        while (nextChar!= EOF)
        {
            if (nextChar== '\n')
            {
                j++;
                if (j==numLinestoSkip)
                {
                    //  break put the remaining characters in an array
                    break;
                }
            }
            nextChar  = getc(file);
        }
        while (nextChar!=EOF)
        {
            printf("%c",nextChar);
            nextChar=getc(file);
            
        }
        
        fclose(file);
    }
    
    return 0;
}