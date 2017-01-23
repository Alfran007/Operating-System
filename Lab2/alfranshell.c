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
      if(i>=0)
      {
            if(!strcmp(token[0],"cd"))  // program for cd command.
            {

                  inp = strtok(NULL," ");
	            if(inp==NULL)
	            {
	                return 0;
	            }

	            else if(chdir(inp)==-1) //checking valid directory.
	            {
	                  printf("Error: Not a valid directory\n");  
	                  return 0;  
	            }
	            printf("directory changed\n");
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

int main(int argc,char *argv[])
{
      int k;
      int j=0;
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
            j=0;
            t = strtok(s," ");  // taking string before space.
            arr[i] = t;
            if(!strcmp(arr[i],"cd"))
            {
	            check(arr+j,"cd");    
            }
            
            for(i=2; t!=NULL ;i++)	
            {
                  flag =0;
                  outp = t;
                  t = strtok(NULL," ");
                  


                  if(t==NULL)
                  {
                        
                        arr[i-1] = NULL;
	                  check(arr+j," ");
	                  arr[i-1]=t;
	                  j =i;
	                  continue;
                  }
                  arr[i-1] = t;
                  if(!strcmp(arr[i-1],"&"))
                  {
	                  arr[i-1]=NULL;
	                  check(arr+j,"&");
	                  arr[i-1]="&";
	                  j=i;
	                  break;
                  }

                  else if(!strcmp(t,"|"))
                  {     
	                  check(arr+j,"|");
	                  j=i;
	                  continue;
                  }
             

            }
      }
      printf("\nThanks for using Alfran's Shell! :)\n");
      return 0;

}


