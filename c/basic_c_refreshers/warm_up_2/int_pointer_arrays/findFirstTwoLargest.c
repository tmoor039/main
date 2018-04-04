// Reviewed 4 April 2018
// THis program is incomplete.... 
// NO main method, and double declaration is implemented as a vooid ? 



#include<stdio.h>

double find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main()
{

return 0;
}

// can only return two values!  need a to be an array?
void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
   
    
    *largest = *a;  // set the first element of the array to the largest
    *second_largest = *a; // set the first element of the array to the second largest
    
    int count = 0;
    
    while(count < n) // while there are still elements in the array
    {
        if(*(a+count)>*largest) // if the current element being visit is larger than the largest
        {
            *largest =*(a+count); //replace it with that presepective element
            count++; // increment the counter
        }
        else if(*(a+count)>*second_largest) // otherwise if the current element is larger than the second largest
        {
            *second_largest =*(a+count); // replace the second largest with the current element
            count++; // increment the counter
        }
        else // otherwise if the current element is not bigger than the largerst
        {
            count++; // do nothing and only increment the counter 
        }
     
    }

}

