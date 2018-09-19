/*---Start of mycall.c----*/

#include<linux/linkage.h>
#include<linux/syscalls.h>
#include<linux/time.h> // for get time of day system call
#define SECONDS_IN_YEAR 31556926
#define SECONDS_IN_MONTH 2629743
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600

//struct for system time 
struct Date 
{
	int year;
	int month;
	int day;
	int hours;
	int minutes;
	int seconds;
};


asmlinkage long sys_tiago_moore (int pantherid)
{
printk ("sys_tiago_moore called from process %d with panther ID %d.\n",
current->pid, pantherid);

	//declare and initilize variables
	int epochTime;
	struct Date myDate;


struct timeval timeValueStruct; // used in gettimeofday function

do_gettimeofday(&timeValueStruct);//calls system wall clock time

epochTime = timeValueStruct.tv_sec;

myDate.year = (epochTime/SECONDS_IN_YEAR)+1970;// formula for current year
myDate.month = (epochTime/SECONDS_IN_MONTH)%12+1;// forumla for month integer division required 
myDate.day = (epochTime/SECONDS_IN_DAY)%31;// formula for days..integer division required
myDate.hours =((epochTime/3600)+20)%24; // formula for hour 
myDate.minutes =(epochTime/60)%60;
myDate.seconds = epochTime%60;

printk ("Epoch time: %d\n", epochTime); // output the final string
printk ("Human readable time: %d:%d:%d , %d/%d/%d\n",myDate.hours,myDate.minutes,myDate.seconds,myDate.month,myDate.day,myDate.year);

return 0;
}






/*---End of mycall.c------*/
