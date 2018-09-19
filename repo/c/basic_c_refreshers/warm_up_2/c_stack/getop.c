//
//  getop.c
//  Calc
//

#include<stdio.h>
#include<ctype.h>
#include "calc.h"

int etch(void);
void ngetch(int);

int getop(char s[])
{
    int i,c;
    
    while((s[0] = c = etch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;
    
    if(c=='-')
    {
        if(isdigit(c=etch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ngetch(c);
            return '-';
        }
    }
    if(isdigit(c))
        while(isdigit(s[++i] =c =etch()))
            ;
    
    if(c=='.')
        while(isdigit(s[++i] = c=etch()))
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ngetch(c);
    return NUMBER;
}
