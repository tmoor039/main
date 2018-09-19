#include<stdlib.h>
#include<stdio.h>


int *create_array(int n,int initial_value);
void printArray(int *array, int size);


int main()
{
    int n = 50;
    int initial_value= 0;
    
    int *p;
    
    p = create_array(n, initial_value);
    
    printArray(p, n);
    
    return 0;
}



int *create_array(int n,int initial_value)
{
    
    int *array = malloc(n);
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i <n; i++)
    {
        *(array+i) = initial_value;
       
    }
    
        return array;
}


void printArray (int *array, int size)
{
    
    int count = 0;
    int totalElements = 0;
    while (count <size)
    {
        printf("%d\n",*(array+count));
        count++;
        totalElements++;
    }
    
    printf("As coded, there are %d total elements in the array.\n,",totalElements);
    
    
}
