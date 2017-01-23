#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include <sys/types.h>
#include<sys/wait.h>
pid_t pid,pd;

int i,flag=0,status;
size_t size;

char *s,*t,*inp,*outp;
char *arr[1000];

int check(char *token[], char *ch)
{

//if(t==NULL || token[0]==NULL)
//return 0;
if(i>0)
{
/*if(flag==1)
{
waitpid(pd,&status,WUNTRACED);
return 0;
}*/
//printf("\n%s\n",token[0]);
if(!strcmp(token[0],"cd"))  // program for cd command.
{

inp = strtok(NULL," ");

//printf("input is %s ",inp);
//printf("\n%sasd\n",t);
	if(inp==NULL)
	{
	//chdir("/home");
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
else  if(pd==0)
            {
	            if(execvp(token[0],token)<0)
	            {
		            printf("Error: Command not found\n");
	            }
	            exit(0);
            }
            else
	            {
		            if(strcmp(ch,"&"))
		            {
			            waitpid(pd,NULL,0);	
		            }

	            }         

}

}

int main(void)
{
int k;

//void ampersand();
printf("*********Alfran shell executes************\n");


while(1)
{
flag =0;
s=malloc(100*sizeof(char));
printf("\nroot@alfran_shell:~");
getline(&s,&size,stdin);
s[strlen(s)-1] = '\0';


if(!strcmp(s,"exit"))
{
      printf("\nThanks for using Alfran's Shell! :)\n"); 
	exit(0);	// Exit on exit
	
}
if(feof(stdin))  // Exit on Ctrl + D
{ 
printf("\n");
printf("\nThanks for using Alfran's Shell! :)\n"); 
exit(0);
}

i=0;
t = strtok(s," ");  // taking string before space.
//printf("%s ",t);
arr[i] = t;
if(!strcmp(t,"cd"))
{
	//printf("cd typed!\n");
	check(arr,"cd");
	//if(x==0)
	  //    continue;
}
int j=0;
for(i=2; t!=NULL ;i++)	
{
flag =0;
outp = t;
t = strtok(NULL," ");

//printf("it is :%s ",t);
  // taking the string parts breaking through spaces.
//printf("hereds token is %s\n",t);


if(t==NULL)
{
      
	check(arr+j," ");
	//j=i+1;
	continue;
}
arr[i-1] = t;
if(!strcmp(t,"&"))
{
//	printf("here token is %s\n",t);
	arr[i-1]=NULL;
	//for(k=0;k<=i;k++)
      //	printf("%s ",arr[k]);
	check(arr+j,"&");
	//arr[i-1]="&";
	
	j=i;
	continue;
}

else if(!strcmp(t,"|"))
{
	check(arr+j,"|");
	j=i;
	continue;
}
else if(!strcmp(t,"cd"))
{
	//printf("cd typed!\n");
	check(arr+j,"cd");
	continue;
	//if(x==0)
	  //    continue;
}
else
{
      //check(arr+j," ");
}

}
}
printf("\nThanks for using Alfran's Shell! :)\n");

}


