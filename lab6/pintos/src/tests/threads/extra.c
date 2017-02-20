#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <random.h>
#include "tests/threads/tests.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "threads/malloc.h"
#include "devices/timer.h"
void thread1(void);
void thread2(void);
void thread3(void);
/* Global declarations and initialisations*/
char *a;
size_t n =20,i,j,temp;

void threadu1()      
{   
	
	random_bytes(a,n);
        printf("\n*********Thread 1 is executing***********\n");
	printf("Randomised Array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	thread_print_stats();

	thread_exit();
}
void threadu2()      
{   	
        printf("\n*********Thread 2 is executing***********\n");
	printf("Numbers are getting Sorted\n");
     	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
               			temp = a[i];
				a[i] = a[j];
				a[j] = temp;
           		}
      		}
	}
	i = 10000000;
	while(i--)
	{
		/* Giving Delay */
	}
	printf("\n********* Remaining Thread 2 is executing***********\n");
	thread_print_stats();
        thread_exit();
}
void threadu3()      
{   
        printf("\n*********Thread 3 is executing***********\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	thread_print_stats();
	thread_exit();
}
void thread_extra()
{
	const char *t1="threader1"; 
        const char *t2="threader2";
	const char *t3="threader3";
	a = (char *)malloc(sizeof(char)*n);
	thread_print_stats();
	thread_create(t1,1,(thread_func*) threadu1,NULL); 
	thread_create(t2,2,(thread_func*) threadu2,NULL);
	thread_create(t3,3,(thread_func*) threadu3,NULL);
}
  
