#include <random.h>
#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"


void
test_random_sort(void){
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
}
