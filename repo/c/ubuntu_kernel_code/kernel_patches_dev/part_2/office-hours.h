/* 
 * File:   office-hours.h
 * Author: Tiago Moore and Lukas Borges
 *
 * Created on September 30, 2015, 04:49 PM
 */

#ifndef OFFICE_HOURS_H
#define OFFICE_HOURS_H

#include <pthread.h>
/*
typedef struct _student
{
    int id;
    int num_questions;
    pthread_t thread;
} StudentStruct;
*/
void Professor();
void Student(int, int); //added a third int for capacity
void init_shared_variables();

#endif
