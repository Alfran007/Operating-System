#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <random.h>
#include "tests/threads/tests.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

void thread1()      
{   
	printf("\n*********Thread 1 is executing**********\n");
	printf("1st Thread's Name: %s\n",thread_name()); 
	thread_print_stats();   
	thread_exit();
}
void thread2()      
{   
	int i=10000000;           
        while(i--)
        {
            /* Delaying The time */
        }
	printf("\n*********Thread 2 is executing***********\n");
        printf("2nd Thread's ID: %d\n",thread_tid());  
	thread_print_stats();   
        thread_exit();
}
void thread3()      
{   
	printf("\n**********Thread 3 is executing**********\n"); 
	printf("3rd Thread's Priority: %d\n",thread_get_priority()); 
	thread_print_stats();    
	thread_exit();
}
void thread_creation()
{
	const char *t1="threader1"; 
        const char *t2="threader2";
	const char *t3="threader3";
	thread_create(t1,1,(thread_func*) thread1,NULL); 
	thread_create(t2,2,(thread_func*) thread2,NULL);
	thread_create(t3,3,(thread_func*) thread3,NULL);
}
  
