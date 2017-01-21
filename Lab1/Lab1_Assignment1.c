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

printf("\n\n*************************\n\n");

printf("\n\n*************************\n\n");

/*Version2 : Dynamic*/


/*The percentage of time the processor(s) spend in user mode, system mode, and

the percentage of time the processor(s) are idle*/

float sum=0,j,a[1000];
fp = fopen("/proc/stat","r");
fscanf(fp,"%s",s);
for(i=0;i<10;i++)
{
fscanf(fp,"%f",&a[i]);
sum = sum + a[i];
}
printf("User Mode:  %.2f\n",(a[0]/sum)*100);
printf("System Mode:  %.2f\n",(a[2]/sum)*100);
printf("IdealMode:  %.2f\n",(a[3]/sum)*100);

printf("\n\n*************************\n\n");
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

printf("\n\n*************************\n\n");
fclose(fp);

/* The rate (number of blocks per second) of disk read/write in the system*/

int sum1=0,sum2=0;
char b[10000];
fp = fopen("/proc/diskstats","r");
while(!feof(fp))
{
while(1)
{
fscanf(fp,"%c",&b[i]);

if(b[i]=='s')
{
	fscanf(fp,"%s",b);
	fscanf(fp,"%s",b);

	sum1 = sum1 + atoi(b); 

	fscanf(fp,"%s",b);
	fscanf(fp,"%s",b);
	fscanf(fp,"%s",b);
	fscanf(fp,"%s",b);

	sum2 = sum2 + atoi(b);
}
break;
i++;
}
}
printf("\nDisk Read: %d\nDisc Write: %d\n",sum1,sum2);

fclose(fp);

printf("\n\n*************************\n\n");

/*The rate (number per second) of context switches in the kernel*/
fp = popen("cat /proc/stat | grep 'ctxt' | uniq","r");
fscanf(fp,"%s",s);
fscanf(fp,"%s",s);
i = atoi(s);
printf("Context Switches: %d\n",i);


/*The rate (number per second) of process creations in the system*/
fp = popen("cat /proc/stat | grep 'processes' | uniq","r");
fscanf(fp,"%s",s);
fscanf(fp,"%s",s);
i = atoi(s);
printf("Processes: %d\n",i);
}









