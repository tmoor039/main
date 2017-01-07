//
//  main.c
//  BMP
//
//  Created by T Moore on 3/23/15.
//  Copyright (c) 2015 Tiago Moore. All rights reserved.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bmplib.h"

/*
 * This method enlarges a 24-bit, uncompressed .bmp file
 * that has been read in using readFile()
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the original number of rows
 * cols     - the original number of columns
 *
 * scale    - the multiplier applied to EACH OF the rows and columns, e.g.
 *           if scale=2, then 2* rows and 2*cols
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows (scale*rows)
 * newcols  - the new number of cols (scale*cols)
 */
int enlarge(PIXEL* original, int rows, int cols, int scale,
            PIXEL** new, int* newrows, int* newcols)
{
    *newrows = scale*rows;
    *newcols = scale*cols;
    *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
    
    int row,col,rowx,coly;
    
    for(row=0;row<rows;row++)
    {
        for(col=0;col<cols;col++)
        {
            PIXEL *o = original+ row*cols + col;
    for(rowx=row*scale; rowx<row*scale+scale;rowx++)
    {
        for(coly=col*scale;coly<col*scale+scale;coly++)
        {
            PIXEL *n = *(new)+(rowx*(*newcols))+coly;
            *n=*o;
        }
    }
        }
    }

    return 0;
}






/*
 * This method rotates a 24-bit, uncompressed .bmp file that has been read
 * in using readFile(). The rotation is expressed in degrees and can be
 * positive, negative, or 0 -- but it must be a multiple of 90 degrees
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 * rotation - a positive or negative rotation,
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows
 * newcols  - the new number of cols
 */
int rotate(PIXEL* original, int rows, int cols, int rotation,
           PIXEL** new, int* newrows, int* newcols)
{
    int row, col;
    newrows= &row;
    newcols = &col;
    PIXEL *n = original;
    PIXEL *o = original;
    
    if ((rows <= 0) || (cols <= 0)) return -1;
    
    *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));
    for(row = 0; row < rows; row++)
    {
        for(col = 0; col < cols; col++ )
        {
            o = original +(row*cols) + col;
            
            if (rotation<0)
            {
                n  = (*new)+(col*rows) + (rows-row-1);
            }
            if (rotation>0)
            {
                n = (*new)+((cols-col-1)*rows) + row;
            }
            *n = *o;
        }
    }
    *newcols = rows;
    *newrows = cols;
    
    return 0;
}

/*
 * This method horizontally flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile().
 *
 * THIS IS GIVEN TO YOU SOLELY TO LOOK AT AS AN EXAMPLE
 * TRY TO UNDERSTAND HOW IT WORKS
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */
int flip (PIXEL *original, PIXEL **new, int rows, int cols)
{
    int row, col;
    
    if ((rows <= 0) || (cols <= 0)) return -1;
    
    *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));
    
    for (row=0; row < rows; row++)
        for (col=0; col < cols; col++) {
            PIXEL* o = original + row*cols + col;
            PIXEL* n = (*new) + row*cols + (cols-1-col);
            *n = *o;
        }
    
    return 0;
}

int main (int argc, char **argv)
{
    printf("NOTE: YOU MUST USE THE FOLLOWING FORMAT WHEN INPUTTING COMMAND LINE ARGUMENTS:\n AS NOTED IN INSTRUCTIONS: The program should take the follow command-line options in order:\n  imagetool [-s scale | -r degree | -f ] [-o output_file] [input_file] ");
    
    
    // declare and initialize variables
    int r=0, c=0,i;
    int*row,*col;
    
    row = malloc(sizeof(int));
    col = malloc(sizeof(int));
    
    PIXEL *ORIGINAL, *NEWPIXEL;
    int scale = 0,degree =0;
    int aflag = 0;
    int bflag = 0;
    int cflag = 0;
    int dflag = 0;
    char *cvalue = NULL;
    int index;
    int x;
    char  *outputFile =  NULL , *inputFile = NULL;
    
    opterr = 0;
    
    while ((x = getopt (argc, argv, "s:r:o:f")) != -1)
        switch (x)
    {
        case 's':
            aflag = 1;
            scale = atoi(optarg);
            break;
        case 'r':
            degree = atoi(optarg);
            bflag = 1;
            break;
        case 'o':
            if (optarg!= NULL)
            {
                outputFile= optarg;
            }
            else if (optarg== NULL)
            {
                outputFile= NULL;
            }
            cflag = 1;
            break;
        case 'f':
            dflag = 1;
            break;
            
        case '?':
            if (optopt == 's'|| optopt == 'r'||optopt == 'o')
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
    
    i = optind;
    if (optind==1)
    {
        inputFile=NULL;
    }
    else
    {
        inputFile =argv[optind];
    }
    
    
    if (bflag==1)
    {
        if (degree>0)
        {
            readFile(inputFile, &r, &c, &ORIGINAL);
            rotate(ORIGINAL, r, c, 1, &NEWPIXEL, row,col);//flip clockwise
            writeFile(outputFile, r, c, NEWPIXEL);
            
        }
        
        else if (degree<0)
        {
            //flip counterclockwise
            readFile(inputFile, &r, &c, &ORIGINAL);
            rotate(ORIGINAL, r, c, -1, &NEWPIXEL, row,col);//flip clockwise
            writeFile(outputFile, r, c, NEWPIXEL);
        }
        
    }
    else if (aflag==1)
    {
        readFile(inputFile, &r, &c, &ORIGINAL);
        enlarge(ORIGINAL, r, c, scale, &NEWPIXEL, row, col);
        writeFile(outputFile, r, c, NEWPIXEL);
    }
    
    else if (dflag ==1)
    {
        readFile(inputFile, &r, &c, &ORIGINAL);
        flip(ORIGINAL, &NEWPIXEL, r, c);
        writeFile(outputFile, r, c, NEWPIXEL);
    }
    
    
    
    
    free(ORIGINAL);
    free(NEWPIXEL);
    
    return 0;
    
}
