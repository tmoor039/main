#ifdef __APPLE__

#ifndef PTHREAD_BARRIER_H_
#define PTHREAD_BARRIER_H_

#include <pthread.h>
#include <errno.h>
typedef int pthread_barrierattr_t;
typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int tripCount;
} pthread_barrier_t;

int pthread_barrier_init(pthread_barrier_t *barrier, const pthread_barrierattr_t *attr, unsigned int count)
{
    if(count == 0)
    {
        errno = EINVAL;
        return -1;
    }
    if(pthread_mutex_init(&barrier->mutex, 0) < 0)
    {
        return -1;
    }
    if(pthread_cond_init(&barrier->cond, 0) < 0)
    {
        pthread_mutex_destroy(&barrier->mutex);
        return -1;
    }
    barrier->tripCount = count;
    barrier->count = 0;
    
    return 0;
}

int pthread_barrier_destroy(pthread_barrier_t *barrier)
{
    pthread_cond_destroy(&barrier->cond);
    pthread_mutex_destroy(&barrier->mutex);
    return 0;
}

int pthread_barrier_wait(pthread_barrier_t *barrier)
{
    pthread_mutex_lock(&barrier->mutex);
    ++(barrier->count);
    if(barrier->count >= barrier->tripCount)
    {
        barrier->count = 0;
        pthread_cond_broadcast(&barrier->cond);
        pthread_mutex_unlock(&barrier->mutex);
        return 1;
    }
    else
    {
        pthread_cond_wait(&barrier->cond, &(barrier->mutex));
        pthread_mutex_unlock(&barrier->mutex);
        return 0;
    }
}
#endif // PTHREAD_BARRIER_H_
#endif // __APPLE__


//
//  main.c
//  lab2
//
//  Created by tmoore on 9/27/15.
//  Copyright © 2015 tmoore. All rights reserved.
//
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "threading.h"

int sharedVariable = 0;
pthread_mutex_t lock;
pthread_barrier_t barrier;


//Function to make sure command line parameter is an actual integer
int assertInt(char []);

static void* simpleThread(int which)
{
    int num, val;

    for(num = 0; num < 20; num++)
    {

#ifdef PTHREAD_SYNC
	
        pthread_mutex_lock(&lock);
        if (random() > RAND_MAX / 2)
        usleep(10);
        val = sharedVariable;
        sharedVariable = val + 1;
        pthread_mutex_unlock(&lock);
        printf("*** thread %d sees value %d\n",which, val);
  	pthread_barrier_wait (&barrier);
	 syscall(__NR_moore_borges);
#else
        if (random() > RAND_MAX / 2)
        usleep(10);
        val = sharedVariable;
        sharedVariable = val + 1;
        printf("*** thread %d sees value %d\n",which, val);
#endif
	  syscall(__NR_moore_borges);
    }
   // place a wait so for all threads to complete before  printing their final result

    
    val = sharedVariable;
    printf("Thread %d sees final value %d\n", which, val);

    pthread_exit(NULL);
    return NULL;
}

int main (int argc, const char  * argv[])
{
    int numThreads = 0;
    //command line check for valid parameter input
    if(argc!= 2)
    {
        printf("Usage: ./threading <Positive integer>\n");
        exit(1);
    }
    //validate the command line parameter is a positive  integer
    numThreads = atoi(argv[1]);
    if (numThreads<= 0 )
    {
        printf("Invalid parameter.... must be an iteger greater than 0..\n");
        exit(1);
    }
	// Assert that the parameter is not a character
    if (assertInt((char*)argv[1]) == -1)
    {
        printf("Invalid parameter... must be an integer greater than 0..\n");
	exit(-1);
    }
   

    pthread_t tid[numThreads];
    pthread_barrier_init(&barrier, NULL, numThreads);
    int i;
    pthread_t pids[numThreads];
    for (i = 0; i < numThreads; i ++)
    {
        
     pids[i] = pthread_self();
   	 pthread_create(&(tid[i]),NULL,(void*)&simpleThread,(void*)&pids[i]);
   //  pthread_join(tid[i],NULL);
    }


	// make system calls here before we temrinate all threads

	// wait for each thread to finish 
	
    for (i = 0; i < numThreads; i ++)
    {
    	pthread_join(tid[i],NULL);
    }
   // pthread_mutex_destroy(&lock);
    return 0;
}

//This function makes sure that the char string is an integer
//It checks each digit in the command line parameter and asserts that it is a digit..
// Returns 0 is sucess -1 if fail
int assertInt(char number[])
{
    int i = 0;
    for (i = 0; number[i] != 0; i++)// while were not at the null terminating character
    {
        if (!isdigit(number[i])) // check if number is a digit within 0 and 9
            return -1;
    }
    return 0;
}


  
