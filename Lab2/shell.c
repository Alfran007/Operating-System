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
int i,out=0;
size_t size;
printf("*********Alfran shell executes************\n");
while(1)
{
out =0;
s=malloc(100*sizeof(char));
printf("\nroot@alfran_shell:~");
getline(&s,&size,stdin);
s[strlen(s)-1] = '\0';


if(!strcmp(s,"exit"))
{
	exit(0);	// Exit on exit
	printf("\nThanks for using Alfran's Shell! :)\n"); 
}
if(feof(stdin))  // Exit on Ctrl + D
{ 
printf("\n");
printf("\nThanks for using Alfran's Shell! :)\n"); 
exit(0);
}


t = strtok(s," ");  // taking string before space.
arr[0] = t;
for(i=1; t!=NULL ;i++)	
{
if(!strcmp(t,"cd"))  // program for cd command.
{
in = strtok(NULL," ");
if(in==NULL)
{
printf("Error: Enter the Directory\n");
out=2; //checking valid directory.
break;
}
if(chdir(in)==-1)
printf("Error: Not a valid directory\n");  
out =2;  //checking valid directory.
}
t = strtok(NULL, " ");  // taking the string parts breaking through spaces.
arr[i] = t;
}

if(out==2)  //if directory is invalid continue the loop.
continue;


if(i>0)
{
pd = fork();  // getting the process id and forking the program.
if(pd<0)
{
printf("Error: Child process forking failed\n");
}
else if(pd>=0)
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
printf("\nThanks for using Alfran's Shell! :)\n");

}
