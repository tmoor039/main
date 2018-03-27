/* 
 * File:   office-hours.c
 * Author: Tiago Moore and Lukas Borges
 *
 * Created on September 30, 2015, 04:49 PM
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <ctype.h>
//#include <errno.h>

#include "office-hours.h"

//thread
pthread_t professor_thread;

//mutexes
pthread_mutex_t professor_lock;
pthread_mutex_t student_lock;

//conditionals (camelCase)
pthread_cond_t professorReady;
pthread_cond_t studentReady;
pthread_cond_t questionAnswered;
pthread_cond_t studentDone;

//globals
int qCount;
int numStud = 0;
int officeCap;
int studSatisfied = 0;

int assertInt(char []);

//Queue data structure implementation
struct Node
{
	int data;
	struct Node* next;
};

//Two global variables to store the address of front and rear nodes
struct Node* front = NULL;
struct Node* rear = NULL;

//enqueue an integer
void Enqueue(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

//dequeue an integer
void Dequeue()
{
	struct Node* temp = front;
	if(front == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	if(front == rear)
		front = rear = NULL;
	else
		front = front->next;

	free(temp);
}

int Front()
{
	if(front == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	return front->data;
}

void PrintQ()
{
	struct Node* temp = front;
	while(temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int isEmpty()
{
	if(front == NULL)
		//Queue is Empty
		return 1;
	else//Queue not Empty
		return 0;
}
//Queue ends here

typedef struct _student
{
    int id;
    int questions;
    int currQuestion;
    pthread_t thread;
} StudentStruct;


//pointer to current Student
StudentStruct* currentStudent;

struct timeval t1, t2;

//total questions
int asked_question_num;

int timeInterval(struct timeval t2, struct timeval t1)
{
    return ((t2.tv_sec-t1.tv_sec)*1000000 + (t2.tv_usec-t1.tv_usec));
}

void Nap()
{
    printf("Professor Napping...\n");
}

void questionStart(StudentStruct *s)
{
    printf("Student %d asks question %d/%d.\n",
            s->id,
            s->currQuestion,
            s->questions
            );
}

void questionDone(StudentStruct *s)
{
    printf("Student %d is satisfied with answer for question %d.\n",
            s->id,
            s->currQuestion
            );
}

void answerStart()
{
    printf("Professor starts to answer question %d for Student %d.\n",
           currentStudent->currQuestion,
           currentStudent->id);
}

void answerDone(int qCount)
{
    printf("Professor is done answering question %d/%d for Student %d; "
           "total of %d question(s) were addressed.\n",
            currentStudent->currQuestion,
            currentStudent->questions,
            currentStudent->id,
            qCount
            );
}

void* professorAction()
{
	//professor gets professor_lock before others
    pthread_mutex_lock(&professor_lock);

        printf("Crazy Professor's office hours have begun!\n");
        
		int qCount = 0;
        while(1)
        {
            if(numStud == 0)
            {
                Nap();
            }

            //now we signal that professor is ready to answer questions
            pthread_cond_signal(&professorReady);
            pthread_cond_wait(&studentReady, &professor_lock);

            //gettimeofday(&t1, NULL);
            answerStart();
            //usleep(random() % 1000); //sleep for min. random time
            //gettimeofday(&t2, NULL);
            answerDone(++qCount);

            pthread_cond_signal(&questionAnswered);

            //wait for student to be satisfied
            pthread_cond_wait(&studentDone, &professor_lock);

        }
        
    //unlock mutex
    pthread_mutex_unlock(&professor_lock);
    return NULL;
}

void leaveOffice(StudentStruct* s)
{
	printf("Student %d left office.\n", s->id);
}

void* studentAction(void* student)
{
    //argument void pointer no more:
    StudentStruct* stu = (StudentStruct*)student;
    
    int qAnswered = 0;
    while(qAnswered < stu->questions)
    {
        //no other student interacts with the professor
        pthread_mutex_lock(&student_lock);
        
		//grab the professor's lock to interact with this student
        pthread_mutex_lock(&professor_lock);
        
            stu->currQuestion = qAnswered + 1;
            currentStudent = stu;
            questionStart(stu);

            //Signals professor to wake up and answer
            pthread_cond_signal(&studentReady);

            //wait for professor to answer
            pthread_cond_wait(&questionAnswered, &professor_lock);
            qAnswered++;

            questionDone(stu);
            
            //if a student asked all questions, student leaves
			//student leaves office function goes here:
            if(qAnswered == stu->questions)
            {
                //num_students--;
                numStud--;
				leaveOffice(stu);
				//printf("Student %d is done and left.\n", stu->id);
				//studSatisfied++;
            }
            
            //Signal that student is satisfied with answer
            pthread_cond_signal(&studentDone);
            
            //student leaves
            //professor is ready for another student
            pthread_cond_wait(&professorReady, &professor_lock);
            
        //Unlock for next student to come in
        pthread_mutex_unlock(&professor_lock);
        pthread_mutex_unlock(&student_lock);
    }
    return NULL;
}

void enterOffice(StudentStruct* s)
{
	printf("Student %d shows up in office.\n...\n", s->id);
}

void Student(int id, int numQuestions)
{
    StudentStruct *stu = malloc(sizeof(StudentStruct));
    stu->id = id;
    stu->questions = numQuestions;

	//student enters office function goes here:
	/*
	 * If office is full, students gets queued up
	 * 
	 */
		pthread_mutex_lock(&student_lock);
			numStud++;
        	enterOffice(stu);
			//printf("\nStudent %d is in.\n...\n", stu->id);
    	pthread_mutex_unlock(&student_lock);
 		pthread_create(&stu->thread, NULL, studentAction, (void*)stu);
}

void Professor()
{
    //Professor grabs professor_lock
    pthread_mutex_lock(&professor_lock);
    
        //create thread
        pthread_create(&professor_thread, NULL, professorAction, NULL);
        
        //avoid students from getting professor_lock first
        pthread_cond_wait(&professorReady, &professor_lock);
    
    pthread_mutex_unlock(&professor_lock);
}

void init()
{
    pthread_mutex_init(&professor_lock, NULL);
    pthread_mutex_init(&student_lock,   NULL);
    
    pthread_cond_init(&professorReady,   NULL);
    pthread_cond_init(&studentReady,     NULL);
    pthread_cond_init(&questionAnswered, NULL);
    pthread_cond_init(&studentDone,      NULL); 
}


void run(int amt_stu, int cap)
{
	printf("amount of students: %d, office capacity: %d\n", amt_stu, cap);
	Professor();
	int amt_questions; //amount of questions
	int nextStu;

	while(isEmpty() == 0)//Queue not full
	{
		int i;
			nextStu = Front();
			amt_questions = ((nextStu % 4) + 1);
			if(numStud < cap)
			{
				nextStu = Front();
				Student(nextStu, amt_questions);
				Dequeue();
			}
			else
				continue;
	}


	while(1);
}

/* This functions makes sure that the char string is an integer
 * it checks each digit in the command line parameter and asserts that it is a digit...
 * Returns 0 is success -1 if fail
 */
int assertInt(char number[])
{
	int i = 0;
	for	(i = 0; number[i] != 0; i++)
	{
		if(!isdigit(number[i]))
			return -1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	//test for amount of command line arguments:
    if(argc < 2)
    {
		printf("Usage: ./office-hours <amount of students, capacity>\n");
		return 0;
    }
	else
	{
		//test for characters being integers:
		if(assertInt((char*)argv[1]) == -1 || assertInt((char*)argv[2]) == -1)
		{
			printf("Inputs should be positive integers.\n");
			return 0;
		}
		else
		{
			//concert argvs into integers:
			char *p; //pointer
			int stu;
			int cap;
			long conv_stu = strtol(argv[1], &p, 10); //decimal
			long conv_cap = strtol(argv[2], &p, 10);

			stu = conv_stu;
			cap = conv_cap;
			officeCap = cap;
			
			int i;
			for(i = 0; i < stu; i++)
			{
				Enqueue(i);
				//PrintQ();
			}
			//run the program with the arguments:
			run(stu, cap);
			return 0;
		}
	}
}
