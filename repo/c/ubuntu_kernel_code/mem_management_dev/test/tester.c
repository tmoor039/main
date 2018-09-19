#include <stdio.h>
#include <stdlib.h>
#include "tester.h"


//We make 2500 allocations 255  of random 16 bytes 

int main(int argc, char *argv[])
{
	double diffPct;
	long avg_claimed, avg_free;
	double endingAvg, begginingAvg;
	int size; 
		int i;
		for(i = 0; i <2500; i++)
		{
			size = (rand() % 255)+16; 
			
			//kmalloc call
			syscall(__NR_sys_slob_user_alloc,size);
			avg_claimed = syscall(__NR_sys_get_slob_amt_claimed);
			avg_free = syscall(__NR_sys_get_slob_amt_free);
			//get the starting average free
			if(i == 0)
			{
				begginingAvg = avg_free;
				printf("Statistics before 1000 allocations of 1 and 255 bytes\n");
				printf("Average Claimed: %ld Average Free: %ld\n",avg_claimed,avg_free);
			}				
		}
		endingAvg = avg_free;
		//percentage difference from end to start 
		diffPct = ((endingAvg - begginingAvg)/begginingAvg)*100; 
			printf("Statistics after 1000 allocations of 1 and 255 bytes:\n");
			printf("Memory difference: %0.2f\n", endingAvg - begginingAvg);
			printf("Before: %.2f\nAfter: %.2f\nPercent difference: %0.5f%%\n", begginingAvg, endingAvg, diffPct);




	return 0;
}

