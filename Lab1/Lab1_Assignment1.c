#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{

/*Version1 : Static*/

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





/*Version2 : Dynamic*/


/*The percentage of time the processor(s) spend in user mode, system mode, and

the percentage of time the processor(s) are idle*/

float sum,j;
/*fp = fopen("/proc/stat","r");
fscanf(fp,"%s",s);
for(i=0;i<)*/

/*The amount and percentage of available (or free) memory*/

fp = fopen("/proc/meminfo","r");

fscanf(fp,"%s",s);//Taking the string MemTotal
fscanf(fp,"%s",s); // taking the number in string format
j = (float)atoi(s); //converting the string to integer and typecasting it to float
fscanf(fp,"%s",s); // for taking kB

fscanf(fp,"%s",s);//taking the string MemFree
fscanf(fp,"%s",s); // taking the number in string format

sum = (float)atoi(s);//converting the string to integer and typecasting it to float

printf("Amount of free memory is :%.2f \nPercentage of available memory is:%.2f \n",sum,(sum/j)*100);

fclose(fp);
}









