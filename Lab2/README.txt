My shell named "alfran_shell"  runs all the basic commands like top,ps,ls,cat,strace and all the other basic commands that the linux shell - bash runs.

It supports opening files with using multiple '&' ampersand i.e for eg. ls & pwd which gives information of both the commands at the same time.

It take commands in a getline() format which is further checked for the new line and converted the last character to NULL, also the output is in a good format similar to the bash and in a new line.

Also one can open multiple files using gedit it also supports amperssand , such as command "gedit file1.txt &" would result in let the child process end and again start the parent process i.e. like normal terminal , u won't have to open the file again for compliling it.

It recognises the command like exit and Ctrl + D to exit the process i.e. exit the child process which is toyshell in this case and tends to parent process.

The shell waits until the started program complete unless the user runs it at the background (with &) 

To parse the input line into words separated by white space, i have used strtok() function which takes the string and split it according to the second argument.

In addition, the shell waits until the previously started program to complete unless the user runs them at the background (with &). For that i have used wait function and checked for the process id to be possitive that is running than wait other wise not using the function Wait(Null).

The shell runs programs use two core system calls: fork() and execvp(). fork creates a child process and i have used a datatype pid_t for the process id's and assigned the return value of fork() function to that chill process ID.
execvp() takes two arguments in my program one for the command to execute same as in the original shell and the other as the whole string of the command entered by the user.


Than my program do some additional condition checking for & , cd (which also further have checked for the directory existance and the arguments (path) passed and reacted accordingly), pipe '|' which seperates 2 processes and runs one child process into another child process such that output of one process is the input for another child process, and hence the threads are needed to be created(partially undone). 



