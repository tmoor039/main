//
//  getch.c
//  Calc
//
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