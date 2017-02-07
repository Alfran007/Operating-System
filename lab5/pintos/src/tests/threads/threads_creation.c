#include "tests/threads/tests.h"
#include <debug.h>
#include <string.h>
#include <stdio.h>
#include"threads/thread.h"
#include <random.h>
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"


thread_func *
test_random_sort_new(void){
/* To get the proper integer values*/
char *a;
size_t n=10,i,j;
a = (char *)malloc(sizeof(char)*n);
random_bytes(a,n);
/* Printing the random numbers */
printf("Random Array is:\n");
for(i=0;i<n;i++) 
{
printf("%d ",a[i]);
}
/* sorting */
for(i=0;i<n;i++)  
{
	for(j=i;j<n;j++)
	{
		if(a[i]>a[j])
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
}
printf("\n");
 /*printing*/
printf("Sorted Array is:\n");
for(i=0;i<n;i++) 
{
printf("%d ",a[i]);
}
thread_exit();
printf("Thread Exiting\n");
}

void test_thread_call(void)
{
printf("Thread called\n");
thread_create("Thread2",PRI_DEFAULT +1,test_random_sort_new,NULL);
}




