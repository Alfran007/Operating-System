#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include <sys/types.h>
#include<sys/wait.h>
pid_t pid,pd;

int i,outp=0;
size_t size;

char *s,*t,*inp;
char *arr[1000];

int check(char *token[], char *ch)
{
if(i>0)
{
printf("\n%s\n",token[0]);
if(!strcmp(token[0],"cd"))  // program for cd command.
{
inp = strtok(NULL," ");
printf("\n%s\n",inp);
	if(inp==NULL)
	{
	printf("Error: Enter the Directory\n");
	return 0;
	}

	else if(chdir(inp)==-1) //checking valid directory.
	{
	printf("Error: Not a valid directory\n");  
	return 0;  
	}
}

}



int main(void)
{


//void ampersand();
printf("*********Alfran shell executes************\n");


while(1)
{
outp =0;
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
if(!strcmp(t,"cd"))
{
	printf("cd typed!\n");
	check(arr,"cd");
}
t =strtok(NULL," ");  // taking the string parts breaking through spaces.
printf("here token is %s\n",t);
arr[i] = t;
if(!strcmp(t,"&"))
{
	check(arr,"&");
	continue;
}
if(!strcmp(t,"|"))
{
	check(arr,"|");
	continue;
}
if(!strcmp(arr[i],"/0"))
{
continue;
}
}

printf("\nThanks for using Alfran's Shell! :)\n");
}
}
