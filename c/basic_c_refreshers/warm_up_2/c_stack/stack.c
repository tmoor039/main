//
//  stack.c
//
//  Calc
//

#include <stdio.h>
#include "calc.h"


int position = 0;
double stackArray[MAXVAL];

void push(double value)
{
    if(position < MAXVAL)
        stackArray[position++] = value ;
    else
        printf("Error:stack full, cant push %g\n",value);
}

double pop(void)
{
    if(position>0)
        return stackArray[--position]; // going to return the last bvalue of the array pased on the position value 
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
