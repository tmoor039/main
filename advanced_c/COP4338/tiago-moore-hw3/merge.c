//
//  MergeSort.c
//  MergeSort
//
//  Created by T Moore on 4/2/15.
//  Copyright (c) 2015 Tiago Moore. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>


// declare a struct for the line
typedef struct
{
    int size;
    int *line;
}SEGMENT;

typedef struct
{
    SEGMENT segment1;
    SEGMENT segment2;
}MERGESEGMENT;



// declare a global variable for the array size
static const int ARRAYSIZE = 50;
int SPLITSIZE;

// this function is a helper method to pass into the qsort function
// if return value is positive it will swap then go to next pair
// if its negative it does not swap
int qSortHelper(const void *x, const void *y)
{
    int xPointer;
    int yPointer;
    
    xPointer = *(int*)x;// since parameter is void we must cast it
    yPointer = *(int*)y;
    
    return( xPointer-yPointer);
    
}

static void *sortingThread(void *arg)
{
    int *arr = (int*)arg;
    
    qsort(arr,SPLITSIZE,sizeof(int),qSortHelper); // last arg is a function pointer
    
    printf("Sorted %d elements.\n",SPLITSIZE);
    
    return (void*) arr;
    
}

static void *mergingThread(void *arg)
{
    
    MERGESEGMENT segs = *(MERGESEGMENT*)arg;
    
    // make local segment variables to be used for comparison
    SEGMENT x, y, mergedSegment;
    x.line = segs.segment1.line;
    x.size = segs.segment1.size;
    y.line = segs.segment2.line;
    y.size = segs.segment2.size;
    int offset =0; // to keep track of the  next position to write to the new segment
    int i ; // for the loop;
    int dupCount = 0;
    int sizeDifference = 0;
    int differenceCounter =0;
    int *sizeDifferencePointer;
    // allocate memory for merged segment
    mergedSegment.line = malloc((x.size*y.size)* sizeof(int));
    mergedSegment.size = x.size+y.size;
    // for the size of the new segment, place integers in specific memory location
    if (x.size!= y.size)
    {
        sizeDifference =1;// true;
    }
    
    for (i = 0; i <x.size; i++)
    {
        
        int a = *(x.line+i);
        int b = *(y.line+i);
        
        
        // break out of loop if there is a size differece, assuming segment one is the larger one
        
        if (differenceCounter== y.size)
        {
            // get location so we can tack the rest of segment one onto the final segment
            sizeDifferencePointer = (x.line+i);
            break;
        }

        // if they are equal
        if (a == b )
        {
            dupCount++;
            *(mergedSegment.line+offset) = a;
            offset++;
            *(mergedSegment.line+offset) = b;
            offset++;
        }
        
         if (a < b)
        {
            *(mergedSegment.line+offset) = a;
            offset++;
            *(mergedSegment.line+offset) = b;
            offset++;
        }
         if (a > b)
        {
            *(mergedSegment.line+offset) = b;
            offset++;
            *(mergedSegment.line+offset) = a;
            offset++;
        }
    
        differenceCounter ++;
    
    }
    // if segments are different sizes, then tack on the remainder of segment one into the merged segment
    for (i = 0; i < (mergedSegment.size-y.size); i++)
    {
        *(mergedSegment.line+offset+i)= *(x.line+(y.size)+i);
        
    }
   
    int temp;
    // do a final swap to get one list of sorted elements after they have merged
    for( i = 0; i < offset-1; i ++)
    {
        int leftElement = *(mergedSegment.line+i);
        int rightElement = *(mergedSegment .line+i+1);
 
        if (leftElement>rightElement) // if final merge out of order
        {
            // swap it
            temp = leftElement;
            *(mergedSegment.line+i) = rightElement;
            *(mergedSegment .line+i+1) = temp;
        }
        
    }
    printf("Merged %d elements with %d elements with %d duplicates\n",x.size,y.size,dupCount);
    /*
    for  (i = 0; i <= mergedSegment.size-1; i++)
    {
    printf( "%d ",*(mergedSegment.line+i));
    }
     */
    //free(mergedSegment.line); was having an issued if i free the memory
    return (void*)mergedSegment.line; // returns an integer pointer
}

int main(int argc, const char * argv[])
{
    
    // make sure user entered a single command line argument
    assert(argc==2);
    
    // declare and initialize variables
    int randArray[ARRAYSIZE]; // static array of size 50 with all values with an initial value of 0
    int numOfSplits = atof(argv[1]); // number of threads required
    pthread_t splitThreads[numOfSplits];
    int i, j;// variables for loop
    int arrPos = 0; // variable to keep count of index when splitting random array into segments
    int sizeOfEachSegment = ARRAYSIZE/numOfSplits; // the length of each segment
    SPLITSIZE = sizeOfEachSegment;
    int splitArray[numOfSplits][sizeOfEachSegment]; //declare a 2D array to hold all of our numbers
    int *sortedArr[numOfSplits];// an array of integer pointers to hold the sorted segments
    int *sortedSegment; // temporary integer pointer to be put in sortedArr
    int *finalSegment; // for the final list
    SEGMENT segments[numOfSplits]; // array of structs to hold each segment
    
    //test to see if valid command line arguments
    if (numOfSplits != 2 && numOfSplits != 5 && numOfSplits != 10)
    {
        printf("ERROR:As instructed. You must test the program with 2, 5 or 10.");
        exit(1);
    }
    
    //generates array with  random numbers
    for (i = 0; i < ARRAYSIZE; i++)
    {
        randArray[i]= rand()%100+1;
    }
    // split the random array into a 2D array , each row containing a different segement that will be sorted by threads
    for (i = 0; i<numOfSplits; i++)
    {
        for (j = 0; j <sizeOfEachSegment; j++) {
            
            splitArray[i][j] = randArray[arrPos];
            arrPos++;// keep track of where we are in randArray
        }
    }
    // print the array
    printf("Original segments: \n");
    for (i = 0; i<numOfSplits; i++)
    {
        for (j = 0; j <sizeOfEachSegment; j++) {
            
            printf("%d ",splitArray[i][j]);
        }
        printf("\n");
    }
    
    // sort each individual segmentwith threads
    for (i = 0; i<numOfSplits; i++)
    {
        sortedSegment = splitArray[i];
        segments[i].line = sortedSegment;
        segments[i].size = SPLITSIZE;
        pthread_create(&splitThreads[i], NULL, &sortingThread,sortedSegment);
    }
    
        // wait for threads to finish, store each return value in an array in integer pointers
        for(i = 0; i < numOfSplits; ++i)
        pthread_join(splitThreads[i], (void**)&sortedArr[i]);
    
    printf("Segments after multithreaded sort:\n");
    // print segments

    for (i = 0; i < numOfSplits; i++)
    {
        for (j = 0; j< sizeOfEachSegment; j++)
        {
            printf("%d ",segments[i].line[j]);
        }
        printf("\n");
    
    }

     
    // place the segments in  their prespective mergeset structures to be merged.
    // for this specific program, there are 3 test cases, implementation would need to be changed
    // if program was tested with anything other than 2, 5, and 10 splits.
    if (numOfSplits == 2)
    {
        pthread_t mergeThread; //for the number of threads
        // create mergesegment
        MERGESEGMENT newMerge;
        SEGMENT final;
        // allocate memory for the line
        // newmerge.segment1.line = malloc(sizeOfEachSegment*sizeof(int));
        newMerge.segment1.line = segments[0].line;
        newMerge.segment1.size = segments[0].size;
        // allocate memory for the line
       // newmerge.segment2.line = malloc(sizeOfEachSegment*sizeof(int));
        newMerge.segment2.line = segments[1].line;
        newMerge.segment2.size = segments[1].size;
     // allocate memory for the final segment that will be returned as an integer pointer from the thread function
        finalSegment = malloc((2*SPLITSIZE)* sizeof(int));

        // launch a thread to merge the two splits
        pthread_create(&mergeThread, NULL,&mergingThread,(void*)&newMerge);
    
        // wait for the thread to terminate, get value
    
        pthread_join(mergeThread, (void**)&final.line);
        final.size = 2*SPLITSIZE;

        //print final sorted list
        for  (i = 0; i <final.size; i++)
        {
            printf( "%d\n",*(final.line+i));
        }
        
        
        
    }
    else if (numOfSplits == 5)
    {
        pthread_t mergeThread[4]; //for the number of threads
        SEGMENT roundOneResult;
        SEGMENT roundTwoResult;
        SEGMENT roundThreeResult;
        SEGMENT finalResult;
 
        MERGESEGMENT newMerge[4]; // for three threads to sort first four rows
        
        // ROUND 1
        newMerge[0].segment1.line = segments[0].line;
        newMerge[0].segment2.line = segments[1].line;
        newMerge[0].segment1.size = segments[0].size;
        newMerge[0].segment2.size = segments[1].size;

        // round one will sort first two rows and return sorted list
        pthread_create(&mergeThread[0], NULL,&mergingThread,(void*)&newMerge[0]);

        //ROUND 2
        
        // do the same for rows 3 and 4 with a thread
        newMerge[1].segment1.line = segments[2].line;
        newMerge[1].segment2.line = segments[3].line;
        newMerge[1].segment1.size = segments[2].size;
        newMerge[1].segment2.size = segments[3].size;
        
        // round two will sort first two rows and return sorted list
        pthread_create(&mergeThread[1], NULL,&mergingThread,(void*)&newMerge[1]);
        
        // wait for the first thread to terminate, get value
        pthread_join(mergeThread[0], (void**)&roundOneResult.line);
        // wait for the second thread to terminate, get value
        pthread_join(mergeThread[1], (void**)&roundTwoResult.line);

        // manually set the sizes for the new merged segment (bad implementation)
        roundOneResult.size = SPLITSIZE+SPLITSIZE;
        roundTwoResult.size = SPLITSIZE+SPLITSIZE;
        
        //ROUND 3
        
        // do the same for rows 3 and 4 with a thread
        // store round one and two results in a new segment to be merged together
        newMerge[2].segment1.line = roundOneResult.line;
        newMerge[2].segment2.line = roundTwoResult.line;
        newMerge[2].segment1.size = roundOneResult.size;
        newMerge[2].segment2.size = roundTwoResult.size;

        // round three will sort first two rows and return sorted list
        pthread_create(&mergeThread[2], NULL,&mergingThread,(void*)&newMerge[2]);
        // wait for the thread to terminate, get value
        pthread_join(mergeThread[2], (void**)&roundThreeResult.line);

        roundThreeResult.size= SPLITSIZE*4;
        
        //FINAL ROUND, MERGING WITH LAST ROW
    
        newMerge[3].segment1.line = roundThreeResult.line;
        newMerge[3].segment2.line = segments[4].line;
        newMerge[3].segment1.size = roundThreeResult.size;
        newMerge[3].segment2.size = segments[4].size;
   
          finalResult.line = malloc((SPLITSIZE*5) * sizeof(int));

        // final will sort last two rows and return final sorted list
        pthread_create(&mergeThread[3], NULL,&mergingThread,(void*)&newMerge[3]);
        // wait for the thread to terminate, get value
        pthread_join(mergeThread[3], (void**)&finalResult.line);
        finalResult.size = (SPLITSIZE*4)+SPLITSIZE;
        // print the return value
        
        
        for  (i = 0; i <finalResult.size; i++)
           {
             printf( "%d \n",*(finalResult.line+i));
           }
      
        
    }

    else // num of splits has to be 10
    {
        // we will need  8 threads for this case
        pthread_t mergeThread[9]; //for the number of threads
        
        SEGMENT result[9];
  
        MERGESEGMENT newMerge[9];// 8 merges 1 for each thread
        
        // ROUND 1
        // this round will have five consecutive threads merging the first 10 lines
        //lines 1 and 2
        newMerge[0].segment1.line = segments[0].line;
        newMerge[0].segment2.line = segments[1].line;
        newMerge[0].segment1.size = segments[0].size;
        newMerge[0].segment2.size = segments[1].size;
       //lines 3 and 4
        newMerge[1].segment1.line = segments[2].line;
        newMerge[1].segment2.line = segments[3].line;
        newMerge[1].segment1.size = segments[2].size;
        newMerge[1].segment2.size = segments[3].size;
        //lines 5 and 6
        newMerge[2].segment1.line = segments[4].line;
        newMerge[2].segment2.line = segments[5].line;
        newMerge[2].segment1.size = segments[4].size;
        newMerge[2].segment2.size = segments[5].size;
        //lines 7 and 8
        newMerge[3].segment1.line = segments[6].line;
        newMerge[3].segment2.line = segments[7].line;
        newMerge[3].segment1.size = segments[6].size;
        newMerge[3].segment2.size = segments[7].size;
        //lines 9 and 10
        newMerge[4].segment1.line = segments[8].line;
        newMerge[4].segment2.line = segments[9].line;
        newMerge[4].segment1.size = segments[8].size;
        newMerge[4].segment2.size = segments[9].size;
        
        
        
        pthread_create(&mergeThread[0], NULL,&mergingThread,(void*)&newMerge[0]);
        pthread_create(&mergeThread[1], NULL,&mergingThread,(void*)&newMerge[1]);
        pthread_create(&mergeThread[2], NULL,&mergingThread,(void*)&newMerge[2]);
        pthread_create(&mergeThread[3], NULL,&mergingThread,(void*)&newMerge[3]);
        
        
        pthread_create(&mergeThread[4], NULL,&mergingThread,(void*)&newMerge[4]);
        pthread_join(mergeThread[0], (void**)&result[0].line);
     //  result[0].size = (numOfSplits/sizeOfEachSegment)*2;
        // in a loop. wait for all threads to terminate and store the strings in an array
        for (i = 0; i<5; i++)
        {
            // wait for the first thread to terminate, get value
            pthread_join(mergeThread[i], (void**)&result[i].line);
            // manually set the sizes for the new merged segment (bad implementation)
           result[i].size = sizeOfEachSegment*2;
        }

        // ROUND 2
        
        // entails two parallel threads which sort result 1 2 3 4.. (5  will be done with the last sort)
        //lines 3 and 4
        newMerge[5].segment1.line = result[0].line;
        newMerge[5].segment2.line = result[1].line;
        newMerge[5].segment1.size = result[0].size;
        newMerge[5].segment2.size = result[1].size;
        
        pthread_create(&mergeThread[5], NULL,&mergingThread,(void*)&newMerge[5]);
        //lines 3 and 4
        newMerge[6].segment1.line = result[2].line;
        newMerge[6].segment2.line = result[3].line;
        newMerge[6].segment1.size = result[2].size;
        newMerge[6].segment2.size = result[3].size;
        
        pthread_create(&mergeThread[6], NULL,&mergingThread,(void*)&newMerge[6]);
        
        // wait for these two trheads to finish and store the result in array positoin 6 and 7
        // wait for the first thread to terminate, get value
        pthread_join(mergeThread[5], (void**)&result[5].line);
        // wait for the second thread to terminate, get value
        pthread_join(mergeThread[6], (void**)&result[6].line);
        
        // manually set the sizes of the two lines
        result[5].size = sizeOfEachSegment*4;
        result[6].size = sizeOfEachSegment*4;
        

        //ROUND 3
        
        // lauch  a single merge  thread with rows 6 and 7 and store result in position 8,
        // then merge 8 and 5  in round 6 to get final result
        // store round one and two results in a new segment to be merged together
        newMerge[7].segment1.line = result[5].line;
        newMerge[7].segment2.line = result[6].line;
        newMerge[7].segment1.size = result[5].size;
        newMerge[7].segment2.size = result[6].size;
        
        // round three will sort first two rows and return sorted list
        pthread_create(&mergeThread[7], NULL,&mergingThread,(void*)&newMerge[7]);
        // wait for the thread to terminate, get value
        pthread_join(mergeThread[7], (void**)&result[7].line);
        
        result[7].size = sizeOfEachSegment*8;
        
        //FINAL ROUND, MERGING WITH LAST ROW
        newMerge[8].segment1.line = result[7].line;
        newMerge[8].segment2.line = result[4].line;
        newMerge[8].segment1.size = result[7].size;
        newMerge[8].segment2.size = result[4].size;
        
        result[8].line = malloc((SPLITSIZE*10) * sizeof(int));
        
        // final will sort last two rows and return final sorted list
        pthread_create(&mergeThread[8], NULL,&mergingThread,(void*)&newMerge[8]);
        // wait for the thread to terminate, get value
        pthread_join(mergeThread[8], (void**)&result[8].line);
        result[8].size = (SPLITSIZE*10);
        // print the return value
 
        for  (i = 0; i <result[8].size; i++)
        {
            printf( "%d \n",*(result[8].line+i));
        }
        
        
    }

    
        return 0;
    
}




