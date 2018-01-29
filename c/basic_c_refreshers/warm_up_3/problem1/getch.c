//
//  getch.c
//  offhandhw3problem1
//
//  Created by T Moore on 2/16/15.
//  Copyright (c) 2015 T Moore. All rights reserved.
//

//
//  getch.c
//  Calc
//
#include<stdio.h>
#define BUFSIZE 100


char buf[BUFSIZE];
int bufp = 0;

int etch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ngetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
