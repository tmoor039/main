/* main.c
 ReversePolishCalculator
 
 I understand that this homework assignment cannot be joint work with another st$
 
 During the assignment, I only consulted the following book or online sources: ($
 
 By putting my name below, I understand that the course adopts a zero tolerance $
 
 Name: Tiago Moore
 
 Date: 2/5/2015
 */


#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int main(int argc, const char * argv[]) {
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

