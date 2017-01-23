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
//printf("\n%s\n",token[0]);
if(!strcmp(token[0],"cd"))  // program for cd command.
{
if(t==NULL)
return 0;
inp = strtok(NULL," ");
//printf("\n%sasd\n",t);
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
return 0;
}
pd = fork();  // getting the process id and forking the program.
if(pd<0)
{
printf("Error: Child process forking failed\n");
	
	return 0;
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
		if(strcmp(ch,"&"))
		{
			wait(NULL);	
		}

	}

	

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
if(!strcmp(t,"cd"))
{
	//printf("cd typed!\n");
	int x =check(arr,"cd");
	if(x==0)
	continue;
}
int j=0;
for(i=1; t!=NULL ;i++)	
{
t =strtok(NULL," ");

  // taking the string parts breaking through spaces.
//printf("hereds token is %s\n",t);
arr[i] = t;

if(t==NULL)
{
printf("hello\n");
	check(arr," ");
	//j=i+1;
	continue;
}

if(!strcmp(t,"&"))
{
	printf("here token is %s\n",t);
	arr[i]=NULL;
	check(arr,"&");
	printf("adsrajaf\n");
	//arr[i]="&";
	
	//j=i+1;
	continue;
}

if(!strcmp(t,"|"))
{
	check(arr,"|");
	//j=i+1;
	continue;
}

}
}
printf("\nThanks for using Alfran's Shell! :)\n");
}


