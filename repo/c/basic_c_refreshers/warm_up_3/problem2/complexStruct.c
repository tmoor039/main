#include<complex.h>
#include<stdio.h>
#include<ctype.h>

 struct cStruct
{

    complex double x;
    
};

struct cStruct make_complex(double arg1, double arg2);

struct cStruct add_complex(struct cStruct arg1, struct cStruct arg2);

int main(void)
{
     struct cStruct c1,c2,c3;
    
    c1 = make_complex(13.231, 14.342432);
    c2 = make_complex(1321.32423, 1241234.4342);
    c3 = add_complex(c1, c2);

    printf("c1 real = 13.231 \nc1 fake = 14.342432\n c2 real = 1321.3242\nc2 fake  1241234.4342\n c1+c2 = %f,%f",creal(c3.x),cimag(c3.x));
return 0;
}

/*
This struct stores two arguments the real and imaginary values
Returns the structure with the two values
*/
struct cStruct make_complex(double realArg1,double imagArg2)
{
    struct cStruct s1;
    
    s1.x = realArg1+ imagArg2*I;
    
    return s1;
}


/*
This fuction will add the values of both structs and
Return a single one
*/
struct cStruct add_complex(struct cStruct arg1, struct cStruct arg2)
{
    struct cStruct s1;
    
    // Add the real number and imaginary number of both sturcts and pass it to a third struct
    //which the program will return
    s1.x = (creal(arg1.x)+creal(arg2.x)) + (cimag(arg1.x)+cimag(arg2.x))*I;
    
    return s1;
}


