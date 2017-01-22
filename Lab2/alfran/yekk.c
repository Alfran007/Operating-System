#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void)
{

char *s,*t,*in;
char *arr[1000];
pid_t pd;
int i;
size_t size;
printf("*********Alfran shell executes************\n");
while(1)
{

s=malloc(100*sizeof(char));
printf("\nroot@alfran_shell:~");
getline(&s,&size,stdin);
s[strlen(s)-1] = '\0';


if(!strcmp(s,"exit\n"))
{
	exit(0); // Exit on exit
}
if(feof(stdin))  // Exit on Ctrl + D
{ 
printf("\n");
exit(0);
}


t = strtok(s," ");
arr[0] = t;
for(i=1; t!=NULL ;i++)	
{
if(!strcmp(t,"cd"))
{
in = strtok(NULL," ");
chdir(in);
}
t = strtok(NULL, " ");
arr[i] = t;
}


if(i>0)
{
pd = fork();
if(pd<0)
{
printf("Error: Child process forking failed");
}
if(pd>=0)
{
if(pd==0)
{
	if(execvp(arr[0],arr)<0)
	{
		printf("Error: Command not found\n");
	}
}
else
	{
		wait(NULL);
	}

}
}
}

}
