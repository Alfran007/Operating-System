#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
/*Processor type*/
FILE *fp;

printf("\n\n*************************\n\n");


system("cat /proc/cpuinfo | grep 'model name' | uniq");
printf("\n\n*************************\n\n");
/*Kernel version*/
int i=0;
char s[1000];
fp = fopen("/proc/version","r");
printf("Kernel Version is : ");
fscanf(fp,"Linux version %s",s);
printf("%s\n",s);
fclose(fp);

printf("\n\n*************************\n\n");


/*The amount of memory configured into this computer*/
system("cat /proc/meminfo | grep MemTotal | uniq");

printf("\n\n*************************\n\n");


/*Amount of time since the system was last booted*/
printf("System was last booted since:\n");
system("cat /proc/uptime");
}
