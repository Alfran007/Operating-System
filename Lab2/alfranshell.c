#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#include <sys/types.h>
#include<sys/wait.h>


pid_t pid,pd;

int i,flag=0,status;
size_t size;

char *s,*t,*inp,*outp;
static char *arr[1000];
int cp[2];
static void split(char*);
void clear(int);
int run(char*, int, int, int);
static int take(int flag1, int flag2, int last)
{
	int fd[2];
 
	pipe(fd);	
	pid = fork();
	if (pid == 0) {
		if (flag2 == 1 && last == 0 && flag1 == 0) {
			dup2( fd[1], STDOUT_FILENO );
		} else if (flag2 == 0 && last == 0 && flag1 != 0) {
			dup2(flag1, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
		} else {
			dup2( flag1, STDIN_FILENO );
		}
 
		if (execvp( arr[0], arr) == -1)
			_exit(EXIT_FAILURE); // If child fails
	}
 
	if (flag1 != 0) 
		close(flag1);
 
	close(fd[1]);
 
	if (last == 1)
		close(fd[0]);
 
	return fd[0];
}


 

static void check(char *token[], char *ch)
{
       if(token[0] == NULL)
            return;
      
      if(i>=0)
      {
            if(!strcmp(token[0],"cd"))  // program for cd command.
            {

                  inp = strtok(NULL," ");
	            if(inp==NULL)
	            {
	                return;
	            }

	            else if(chdir(inp)==-1) //checking valid directory.
	            {
	                  printf("Error: Not a valid directory\n");  
	                  return ;  
	            }
	            printf("directory changed\n");
                  return ;
            }

            pd = fork();  // getting the process id and forking the program.
            if(pd<0)
            {
                  printf("Error: Child process forking failed\n");
	
	            return;
            }
            else if(pd==0)
            {
                  if(execvp(token[0],token) < 0)
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

static int n = 0; 
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
            if(!strcmp(s,"\n")) continue;
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
           
            if(!strcmp(t,"|"))
                  {     
                        
		           int  flag1 = 0;
		            int flag2 = 1;
 
		            char* cmd = s;
		            char* nxt = strchr(cmd, '|'); 
 
		            while (nxt != NULL) {
			      *nxt = '\0';
			      flag1 = run(cmd, flag1, flag2, 0);
 
			      cmd = nxt + 1;
			      nxt = strchr(cmd, '|');
			      flag2 = 0;
		      }
		      flag1 = run(cmd, flag1, flag2, 1);
		      clear(n);
		      n = 0;
		      continue;
	            }
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
	                 continue;// break;
                  }

              }
             

            }
      
      printf("\nThanks for using Alfran's Shell! :)\n");
      return 0;

}

 int run(char* cmd, int flag1, int flag2, int last)
{
	split(cmd);
	if (arr[0] != NULL) {
		if (strcmp(arr[0], "exit") == 0) 
			exit(0);
		n += 1;
		return take(flag1, flag2, last);
	}
	return 0;
}

 
static char* rm_w(char* s)
{
	while (isspace(*s)) ++s;
	return s;
}
  void clear(int n)
{
	int i;
	for (i = 0; i < n; ++i) 
		wait(NULL); 
}

 

static void split(char* cmd)
{
	cmd = rm_w(cmd);
	char* nxt = strchr(cmd, ' ');
	int i = 0;
 
	while(nxt != NULL) {
		nxt[0] = '\0';
		arr[i] = cmd;
		++i;
		cmd = rm_w(nxt + 1);
		nxt = strchr(cmd, ' ');
	}
 
	if (cmd[0] != '\0') {
		arr[i] = cmd;
		nxt = strchr(cmd, '\n');
		nxt[0] = '\0';
		++i; 
	}
 
	arr[i] = NULL;
}

