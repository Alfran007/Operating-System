#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char * argv[])
{

if(argc==3)
{
int m =atoi(argv[1]);
int n = atoi(argv[2]);

/* Error Handling */

if(m<=0 || n<=0)
{
printf("Error: Enter only possitive values\n");
return 1;
}


if(n%m!=0)
{
printf("Error: Enter n as a multiple of m\n");
return 1;
}
}

/* Declaration of Vriables*/

int sum1=0,sum2=0,i=0;
float sum=0,j,a[1000]; 
char b[10000],s[1000];

FILE *fp; //Declaring a file pointer



/*Version1 : Static*/
if(argc==1)
{

/*Processor type*/
printf("\n\n*************************\n\n");

system("cat /proc/cpuinfo | grep 'model name' | uniq");

/*Kernel version*/
printf("\n\n*************************\n\n");

fp = fopen("/proc/version","r");
printf("Kernel Version is : ");
fscanf(fp,"Linux version %s",s);
printf("%s\n",s);
fclose(fp);

/*The amount of memory configured into this computer*/
printf("\n\n*************************\n\n");

system("cat /proc/meminfo | grep MemTotal | uniq");

/*Amount of time since the system was last booted*/
printf("\n\n*************************\n\n");

printf("System was last booted since:\n");
system("cat /proc/uptime");
printf("\n\n*************************\n\n");
}

else
{
if(argc==2)
{
	printf("Error: Please Enter 2 values\n");
	return 1;
}
else
{
/*Version2 : Dynamic*/
printf("\n\n*************************\n\n");
int m =atoi(argv[1]);
int n = atoi(argv[2]);
int k = n/m;
printf("k is :%d\n",k);
while(k--)
{

/*The percentage of time the processor(s) spend in user mode, system mode, and
the percentage of time the processor(s) are idle*/


fp = fopen("/proc/stat","r");
fscanf(fp,"%s",s);
for(i=0;i<10;i++)
{
fscanf(fp,"%f",&a[i]);
sum = sum + a[i];
}
printf("User Mode:  %.2f\n",(a[0]/sum)*100);
printf("System Mode:  %.2f\n",(a[2]/sum)*100);
printf("IdleMode:  %.2f\n",(a[3]/sum)*100);

/*The amount and percentage of available (or free) memory*/
printf("\n\n*************************\n\n");


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

/* The rate (number of blocks per second) of disk read/write in the system*/
printf("\n\n*************************\n\n");

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

}
}
return 0;
}










