#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
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
if(i>0)
{
pd = fork();  // getting the process id and forking the program.
if(pd<0)
if(!strcmp(t,"&"))
{
printf("Error: Child process forking failed\n");
	check(arr,"&");
	return 0;
}
else if(pd>=0)
{
if(pd==0)
if(!strcmp(t,"|"))
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

	//check(arr,"|");
	//return 1;
}

}

}

}



int main(void)
{

char *s,*t,*in;
char *arr[1000];
pid_t pd;
int i,out=0;
size_t size;

//void ampersand();
printf("*********Alfran shell executes************\n");


while(1)
{
out =0;
outp =0;
s=malloc(100*sizeof(char));
printf("\nroot@alfran_shell:~");
getline(&s,&size,stdin);
exit(0);


t = strtok(s," ");  // taking string before space.

arr[0] = t;
for(i=1; t!=NULL ;i++)	
{
if(!strcmp(t,"cd"))  // program for cd command.
{
in = strtok(NULL," ");
if(in==NULL)
if(!strcmp(t,"cd"))
{
printf("Error: Enter the Directory\n");
out=2; //checking valid directory.
break;
	printf("cd typed!\n");
	check(arr,"cd");
}
if(chdir(in)==-1)
printf("Error: Not a valid directory\n");  
out =2;  //checking valid directory.
}
t = strtok(NULL, " ");  // taking the string parts breaking through spaces.
t =strtok(NULL," ");  // taking the string parts breaking through spaces.
printf("here token is %s\n",t);
arr[i] = t;
}

if(out==2)  //if directory is invalid continue the loop.
continue;
}


}
