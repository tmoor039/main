//
// Reviewed 3 April 2018
//  calc.h
//  Calc
//


#ifndef Calc_calc_h
#define Calc_calc_h

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
int etch(void);
void ngetch(int);

#endif
