
---------------------------------------------------------------------------------------


**Question 1**

1. **malloc()** : The malloc() is used to dynamicaly allocate memory of a specified size at the time of execution of a program.
It return a pointer to the allocated memory.
The memory is not initialised i.e. it may have garbage value.Garbage value is some unused and unrequired value at some memory location.
 .malloc() function can return NULL if we try to allocate 0 Bytes size for a variable.
		
Syntax: void *realloc(size_t size)
It allocates size Bytes of memory and returns a pointer which can be type casted to appropriate pointer type.
			
__Usage in program:__	
		
int *ptr  = (int *)malloc(sizeof(int));

Here the pointer ptr is allocated size of int i.e. 4 bytes during the execution of this statement.				
Using malloc continous allocation of memory is done.
		
2. **calloc()** : The calloc() function is used to dynamically allocate memory for an array of N elements of M bytes each at the time of execution of the program. 
It returns a pointer to the begining of the allocated memory. The memory is initialised to zero (or in case of char to NULL). 

calloc() accepts two arguments. First the number of elements(N) and second the size of each element(M). 
If N or M is 0, then calloc() returns either NULL, or a unique pointer value.
		
Syntax : void *calloc(size_t n, size_t size)
__n__ is the number of elements to be allocated.	
__size__ is the size of each of the elements.

__Usage in program__
		
#define LARGE 50
int *ptr = (int *)calloc(LARGE,sizeof(int));

Here 50 blocks of memory each of size 4 Bytes are allocated and __ptr__ points to the begining of the ptr.
			
Using calloc continous allocation of memory is done.
		
The difference between malloc() and calloc() is that
1. malloc() allocates single block of memory whereas calloc() allocates multiple blocks of memory each of same size 
2. calloc() sets all bytes to zero.
		
3. **realloc()** : The  realloc() function changes the size of the memory block pointed to by ptr to size bytes. 
The contents will be unchanged in the range from the start of the region up to the minimum of the old and new sizes.
If the new size is larger than the old size, the added memory will not be initialized.
If  ptr  is  NULL,  then  the call is equivalent to malloc(size). 
If size is equal to zero, and ptr is not NULL, then the call is equivalent to making size 0 that is freeing all the allocated memory.
		
Syntax: void *realloc(void *ptr, size_t size)
ptr: This is the pointer to a memory block previously allocated with malloc, calloc and is to to be reallocated.
If this is NULL, a new block is allocated and a pointer to it is returned by the function.

size:  This is the new size for the memory block, in bytes.
If it is 0 and ptr points to an existing block of memory, the memory block pointed by ptr is deallocated and a NULL pointer is returned.

		
__Usage in program__
			
#define LARGE 90
#define SMALL 10
			
int *arr = (int *)calloc(SMALL,sizeof(int));
			
arr = (int *)realloc(arr,LARGE);
			
Precautions:
If continous memory equal to the new size is not present the pointer returned may be a pointer to another location where continous memory is availablle.
That is the pointer may point to another location different from the previously allocated physical address. This may result in the loss of old values. 
			
4. free() : The free() function frees (deallocates) the memory space pointed to by ptr, which must have been returned by a previous call to malloc(), calloc(), or realloc().
If ptr is NULL, no operation is performed.
If free(ptr) has already been called before, undefined behavior occurs. 
			
Syntax:void free(void *ptr)
ptr -- This is the pointer to a memory block previously allocated with malloc, calloc or realloc to be deallocated.
			
__Usage in program__
			
int *a = (int *)malloc(sizeof(int));
	
/* Some computation with a */			
free(a);
			
			
Precaution:
free should not be used to deallocate a pointer which was already deallocated.
			
5. alloca() : The  alloca() function allocates size Bytes of space in the stack segment of the caller.
This temporary space is automatically  freed  when the function that called alloca() returns to its caller.

The header file for alloca() is "alloca.h"

Syntax: void *alloca(size_t size);
			
size is the number of Bytes of memory you want to allocate. 


__Usage in program__
				
#define LARGE 100
char *str = (char *) alloca(LARGE);
			  
Precautions:
If the allocation causes stack overflow, program behavior is undefined. Therefore care should be taken while using alloca();

	
6. longjmp()
	
Syntax: void longjmp(jmp_buf env, int val);
env − This is the object of type jmp_buf containing information to restore the environment at the setjmp's calling point.
value − This is the value to which the setjmp expression evaluates.		

The header file for longjmp() is "setjmp.h"
		
longjmp() restores  the  environment saved by the last call of setjmp(3) with the corresponding env argument.  After longjmp() is completed, program execution  continues  as  if  the corresponding call of setjmp(3) had just returned the value val.
longjmp() cannot cause 0 to be  returned.   
		
__Usage in program__
			
int main()
{
  	int val;
	jmp_buf env_buffer;
	val = setjmp( env_buffer );
			   
	if( val != 0 ) 
	{
		printf("Returned from a longjmp() with value = %s\n", val);
		exit(0);
	}
	printf("Jump function call\n");
	jmpfunction( env_buffer );
			   
	return(0);
}

void jmpfunction(jmp_buf env_buf)
{
	longjmp(env_buf, "tutorialspoint.com");
}
			
			
7. brk()
	
Syntax : int brk(void *addr);
			
brk() change the location of the program break, which defines the end of the process's data segment (i.e., the program break is the first 
location after the end of the uninitialized data segment).  Increasing the program break has the effect of allocating memory to the process. 
Decreasing the break deallocates memory.	
brk() sets the end of the data segment to the value specified by addr, when the system has enough memory, and the process does not exceed its maximum data size.


The header file for brk() is "alloca.h"
		
8. mmap()
	
Syntax: void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
                 
map files or devices into memory.
                  
mmap() creates a new mapping in the virtual address space of the calling process. The starting address for the new mapping is specified in addr.
The length argument specifies the length of the mapping.

If addr is NULL, then the kernel chooses the address at which to create the mapping; this is the most portable method of creating a new mapping.
If addr is not NULL, on Linux, the mapping will be created at a nearby page boundary.
The address of the new mapping is returned as the result of the call.
		
The header file for mmap() is "sys/mman.h"
	
9. munmap()

Syntax: int munmap(void *addr, size_t length);

Use to unmap files or devices into memory.

The munmap() system call deletes the mappings for the specified address range, and causes further references to addresses within the 
range to generate invalid memory references.  The region is also automatically unmapped when the process is terminated.  On the other hand,
closing the file descriptor does not unmap the region.
			
The header file for munmap() is "sys/mman.h"
	
	
Precaution to avoid memory corruption:
		
1)To avoid corruption in multithreaded applications, mutexes are used internally to protect the memory-management data structures employed by these functions.
2)In a multithreaded application in which threads simultaneously allocate and free memory, there could be contention for these mutexes.
3)To scalably handle memory allocation in multithreaded applications, glibc creates additional memory allocation arenas if mutex contention is detected.
4)Each arena is a large region of memory that is internally allocated by the system (using brk(2) or mmap(2)), and managed with its own mutexes.

---------------------------------------------------------------------------------------






---------------------------------------------------------------------------------------

**Question 2**
 
a) A memory leak is a type of resource leak that occurs when a computer program incorrectly manages memory allocations in such a way that memory which is no longer needed is not released or freed up.

b)Memory leak occurs when we create a dynamic memory allocation in heap and don't delete it. 

FOR EXAMPLE : I have allocated memory in the below example using calloc.
**************************************************************
/* Function with memory leak */

#include<stdio.h>
#include <stdlib.h>

int main(void)
{
void function()
{
   int *ptr = (int *)calloc(n,sizeof(int));
   /* Do some work */
   return; /* Return without freeing ptr*/
}
}
****************************************************************

In this program the pointer *ptr was created. And it is returning without freeing the pointer *ptr and hence memory leak exists in the above program.

c) The problem of memory leak would be fixed by freeing the memory that is allocated dynamically after the use of memory.

**************************************************************
/* Function without memory leak */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
void function()
{
   int *ptr = (int *)calloc(n,sizeof(int));
   /* Do some work */
   free(ptr); /* Freeing up the pointer and thus the problem can be solved */
   return; 

}
}
****************************************************************

d)
1. Always write "free" just after dynamic after memory allocation when all the computation related to that memory has done.

****************************************************************
Example:
int *p = (int*)malloc(sizeof(int)*n);

// ... do stuff

free(p);
****************************************************************

2. Never use pointer directly instead make a copy of pointer to work with that memory location otherwise if we work with the same pointer then it may cause changing the pointer and returning the wrong address over to free.

****************************************************************
Example:
int *p_allocated = (int*) malloc ( sizeof(int) * n );
int *p_copy = p_allocated;
// do your stuff with p_copy, not with p_allocated!
// e.g.:
while (n--) { *p_copy++ = n; }
...
free (p_allocated);
****************************************************************

3. Always start by allocating more memory than needed.  After debugging, go back and cut on memory use. If array of 1000 integers is needed, allocate 2000, and only after you make sure everything else is OK – only then go back and cut it down to 1000.

4.  Always carry array length within the array. Let's say at a[0] the length n would be stored.
so that you have idea of what size should be the limit , if you enter more than the available size your system would crash. For Example:
If int is 32 bits, this should be enough to get away with array size of no more than 4GB but if the data was in mere Byte-size, then an array of 257 chars would cause system crash.

---------------------------------------------------------------------------------------

---------------------------------------------------------------------------------------
**Question 3**
My code is :
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
int main()
{
	printf("Code Address:");
	/*main's address*/
	printf("%p\n",(void *)main);
	printf("Stack Address:");
	int var;
	/*var is an auto variable that is allocated in stack*/
	printf("%p\n",(void *)&var);
	//printf("%p\n",(void *)&main);
	printf("Heap Address:");
	int *p;
	p=(int *)malloc(sizeof(int)*SIZE);
	/*p is again a auto variable which is stored in stack, and points to a memory whose allocation is on on the heap*/ 
	printf("%p\n",(void *)p);
	free(p);
	return 0;
}

 O/P in 3 terminals:

__Terminal 1__
Code Address:0x400626
Stack Address:0x7ffdd2ced7cc
Heap Address:0x215f420

__Terminal 2__
Code Address:0x400626
Stack Address:0x7fff8da2461c
Heap Address:0x1b48420

__Terminal 3__
Code Address:0x400626
Stack Address:0x7ffc5ed28f2c
Heap Address:0x1425420
 
**Conclusion:**
We can clearly observe from the above output that the code Address is same for all the executions.
but the pointer to stack is changing itself and pointing at different memory locations so the stack address changes randomly whereever it has free memory avaliable it gets allocated.
Same case for heap as of stack but when the memory is allocated dynamically.Its address changes as in each execution it  gets allocated at different memory locations. 

---------------------------------------------------------------------------------------


---------------------------------------------------------------------------------------

**Question 4**
In this part I first run 

ques_4.c:
#include<stdio.h>
int main(void)
{
	int x = 2;
	int *a;
	printf("Hello Os!\n");
	return 0;
}

gcc -g ques_4.c   : For compiling. (-g to produce debugging information in the operating system's native format)
gdb ques_4

O/P : 

GNU gdb (Ubuntu 7.11.1-0ubuntu1~16.04) 7.11.1
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
"/home/mnit/ques_4.c": not in executable format: File format not recognized
(gdb)

Now as file format is not recognised i did:
(gdb) file a.out

O/P:

Reading symbols from a.out...done.

Then I disassembled the main:
(gdb) disas main

O/P:

Dump of assembler code for function main:
   0x0000000000400526 <+0>:	push   %rbp
   0x0000000000400527 <+1>:	mov    %rsp,%rbp
   0x000000000040052a <+4>:	sub    $0x10,%rsp
   0x000000000040052e <+8>:	movl   $0x2,-0x4(%rbp)
   0x0000000000400535 <+15>:	mov    $0x4005d4,%edi
   0x000000000040053a <+20>:	callq  0x400400 <puts@plt>
   0x000000000040053f <+25>:	mov    $0x0,%eax
   0x0000000000400544 <+30>:	leaveq 
   0x0000000000400545 <+31>:	retq   
End of assembler dump.


Then i get the file information using:

(gdb) info files

O/P:

Symbols from "/home/mnit/a.out".
Local exec file:
	`/home/mnit/a.out', file type elf64-x86-64.
	Entry point: 0x400430
	0x0000000000400238 - 0x0000000000400254 is .interp
	0x0000000000400254 - 0x0000000000400274 is .note.ABI-tag
	0x0000000000400274 - 0x0000000000400298 is .note.gnu.build-id
	0x0000000000400298 - 0x00000000004002b4 is .gnu.hash
	0x00000000004002b8 - 0x0000000000400318 is .dynsym
	0x0000000000400318 - 0x0000000000400355 is .dynstr
	0x0000000000400356 - 0x000000000040035e is .gnu.version
	0x0000000000400360 - 0x0000000000400380 is .gnu.version_r
	0x0000000000400380 - 0x0000000000400398 is .rela.dyn
	0x0000000000400398 - 0x00000000004003c8 is .rela.plt
	0x00000000004003c8 - 0x00000000004003e2 is .init
	0x00000000004003f0 - 0x0000000000400420 is .plt
	0x0000000000400420 - 0x0000000000400428 is .plt.got
	0x0000000000400430 - 0x00000000004005c2 is .text
	0x00000000004005c4 - 0x00000000004005cd is .fini
	0x00000000004005d0 - 0x00000000004005de is .rodata
	0x00000000004005e0 - 0x0000000000400614 is .eh_frame_hdr
	0x0000000000400618 - 0x000000000040070c is .eh_frame
	0x0000000000600e10 - 0x0000000000600e18 is .init_array
	0x0000000000600e18 - 0x0000000000600e20 is .fini_array
	0x0000000000600e20 - 0x0000000000600e28 is .jcr
---Type <return> to continue, or q <return> to quit---q
Quit

Then by changing to this 64 bits range of memory locations DATA in stack to CODE :
I disassemble each range and get to know that memory location of .text which range from 0x0000000000400430 to 0x00000000004005c2 
has my main of c program __ques-4__ . When i disassembled it using :

(gdb) disas 0x0000000000400430,0x00000000004005c2

O/P:

Dump of assembler code from 0x400430 to 0x4005c2:
   0x0000000000400430 <_start+0>:	xor    %ebp,%ebp
   0x0000000000400432 <_start+2>:	mov    %rdx,%r9
   0x0000000000400435 <_start+5>:	pop    %rsi
   0x0000000000400436 <_start+6>:	mov    %rsp,%rdx
   0x0000000000400439 <_start+9>:	and    $0xfffffffffffffff0,%rsp
   0x000000000040043d <_start+13>:	push   %rax
   0x000000000040043e <_start+14>:	push   %rsp
   0x000000000040043f <_start+15>:	mov    $0x4005c0,%r8
   0x0000000000400446 <_start+22>:	mov    $0x400550,%rcx
   0x000000000040044d <_start+29>:	mov    $0x400526,%rdi
   0x0000000000400454 <_start+36>:	callq  0x400410 <__libc_start_main@plt>
   0x0000000000400459 <_start+41>:	hlt    
   0x000000000040045a:	nopw   0x0(%rax,%rax,1)
   0x0000000000400460 <deregister_tm_clones+0>:	mov    $0x60103f,%eax
   0x0000000000400465 <deregister_tm_clones+5>:	push   %rbp
   0x0000000000400466 <deregister_tm_clones+6>:	sub    $0x601038,%rax
   0x000000000040046c <deregister_tm_clones+12>:	cmp    $0xe,%rax
   0x0000000000400470 <deregister_tm_clones+16>:	mov    %rsp,%rbp
   0x0000000000400473 <deregister_tm_clones+19>:	jbe    0x400490 <deregister_tm_clones+48>
   0x0000000000400475 <deregister_tm_clones+21>:	mov    $0x0,%eax
   0x000000000040047a <deregister_tm_clones+26>:	test   %rax,%rax
---Type <return> to continue, or q <return> to quit---q
Quit




I get to know by looking above output that there is a call to __libc_start_main at memory location 0x0000000000400454 where it's relative position in stack is +36.

The call to __libc_start_main gets as its first argument a pointer to main(). So, the last argument in the stack just immediately before the call is your main() address.

    0x000000000040044d <_start+29>:	mov    $0x400526,%rdi
    0x0000000000400454 <_start+36>:	callq  0x400410 <__libc_start_main@plt>

So i putted a breakpoint at above memory location by:
(gdb) break *0x400410

O/P:

Breakpoint 1 at 0x400410

Then I run the gdb using:

(gdb) run

O/P:

Starting program: /home/mnit/a.out 
\
Breakpoint 1, 0x0000000000400410 in __libc_start_main@plt ()

(gdb) n
Single stepping until exit from function __libc_start_main@plt,
which has no line number information.
0x00000000004003f0 in ?? ()

Then i continued the process:
(gdb) c

O/P:
Continuing.
Hello Os!
[Inferior 1 (process 2931) exited normally]

To get the information of register I used:
(gdb) i r

O/P:

The program has no registers now.

Hence, we can see the address by diassembling the DATA into CODE and if after some memory address location the operation is __nop__ then that means that address is after our **limit register address**. Our code is hence in the range of base to limit register address zone.
To check the information of register we use "i" for information and "r" for register.

---------------------------------------------------------------------------------------

