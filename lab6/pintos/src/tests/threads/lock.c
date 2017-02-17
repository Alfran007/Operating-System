#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <random.h>
#include "tests/threads/tests.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include <list.h>
#include "threads/malloc.h"
#include "devices/timer.h"

void test_random_sort_api(void);
struct sort_random {
	struct list_elem elem;
	int val;
};
void test_random_sort_api(void){
struct list_elem *e;
struct list sort_random_list;
list_init (&sort_random_list);
printf("Running Thread's Name: %s",thread_name());
struct sort_random *b;
bool
value_less (const struct list_elem *a_, const struct list_elem *b_,
            void *aux UNUSED) 
{
  const struct sort_random *a = list_entry (a_, struct sort_random, elem);
  const struct sort_random *b = list_entry (b_, struct sort_random, elem);
  
  return a->val < b->val;
}

/* To get the proper integer values used char*/
char *a;
size_t n=10,i;
a = (char *)malloc(sizeof(char)*n);
random_bytes(a,n);

/* Printing the random numbers */
printf("\nRandom Array is:\n");
for(i=0;i<n;i++) 
{
	b= (struct sort_random *) malloc (sizeof (struct sort_random));
	b -> val = a[i];
	list_push_back (&sort_random_list, &b->elem);
	printf("%d ",a[i]);
}

/* sorting */

list_sort(&sort_random_list,value_less,NULL);
printf("\nSorted Array is:\n");
for (e = list_begin (&sort_random_list) ;
			 	e != list_end (&sort_random_list) ;
			 	e = list_next(e)) {
	
		b = list_entry (e, struct sort_random, elem);
		 /*printing*/
		printf (" %d", b->val);
	}
	printf("\nThread End's name is : %s\n\n",thread_name());
	thread_exit();
}

void its_different()
{
	const char *t1="threader"; 
	printf("Running Thread's Name: %s\n\n",thread_name());
	struct lock l;
	lock_init(&l);
	lock_acquire(&l);
	thread_create(t1,1,(thread_func * )test_random_sort_api,NULL);
	lock_release(&l);
	thread_yield();
	printf("Running Thread's Name: %s\n",thread_name());
}
  
