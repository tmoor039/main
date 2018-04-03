/* main.c
 ReversePolishCalculator
 Name: Tiago Moore
 
 Date: 2/5/2015
 Revision date: 3 April 2018
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

