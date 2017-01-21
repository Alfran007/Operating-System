#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
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
int i=0;
float sum=0,j,a[1000],percent=0,sum3=0,User = 0,System=0,Idle=0,sum1=0,sum2=0,count=0,sum_i=0,sum_p=0,p=0,f=0; 
char s[1000];


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
//printf("\n\n*************************\n\n");
int m =atoi(argv[1]);
int n = atoi(argv[2]);
int k = n/m,o=k;
//printf("k is :%d\n",k);
//while(1)
{
sum1=0;
sum2=0;
while(k--)
{

/*The percentage of time the processor(s) spend in user mode, system mode, and
the percentage of time the processor(s) are idle*/

sum3 =0;
fp = fopen("/proc/stat","r");
fscanf(fp,"%s",s);
for(i=0;i<10;i++)
{
fscanf(fp,"%s",s);
a[i] = (float)atoi(s);
//printf("a[%d] is %f\n",i,a[i]);
sum3 = sum3 + a[i];
}

User = User + (a[0]/sum3)*100;
System = System + (a[2]/sum3)*100 ;
Idle = Idle + (a[3]/sum3)*100 ;



fclose(fp);
/*The amount and percentage of available (or free) memory*/
//printf("\n\n*************************\n\n");


fp = fopen("/proc/meminfo","r");

fscanf(fp,"%s",s);//Taking the string MemTotal
fscanf(fp,"%s",s); // taking the number in string format
j = (float)atoi(s); //converting the string to integer and typecasting it to float
fscanf(fp,"%s",s); // for taking kB

fscanf(fp,"%s",s);//taking the string MemFree
fscanf(fp,"%s",s); // taking the number in string format
sum = sum + (float)atoi(s);//converting the string to integer and typecasting it to float
percent = percent + ((float)atoi(s)/j)*100;


fclose(fp);

/* The rate (number of blocks per second) of disk read/write in the system*/
//printf("\n\n*************************\n\n");

fp = fopen("/proc/diskstats","r");
f=0;
//while(1)
//{
//fscanf(fp,"%c",&b[f]);
//printf("%c",b[f]);
//if(b[f]=='s')
	for(f=0;f<3;f++)
	{
	fscanf(fp,"%s",s);
	}
	fscanf(fp,"%s",s);

	sum1 = sum1 + atoi(s); 

	for(f=0;f<3;f++)
	{
	fscanf(fp,"%s",s);
	}
	fscanf(fp,"%s",s);

	sum2 = sum2 + atoi(s);




fclose(fp);

//

/*The rate (number per second) of context switches in the kernel*/
fp = popen("cat /proc/stat | grep 'ctxt' | uniq","r");
fscanf(fp,"%s",s);
fscanf(fp,"%s",s);
i = atoi(s);
sum_i = sum_i + i;



/*The rate (number per second) of process creations in the system*/
fp = popen("cat /proc/stat | grep 'processes' | uniq","r");
fscanf(fp,"%s",s);
fscanf(fp,"%s",s);
p = atoi(s);
sum_p = p + sum_p;

sleep(m);
count++;
}


printf("\n\n*************************\n\n");
printf("User Mode:  %.2f\n",User/(float)o);
printf("\n\n*************************\n\n");
printf("System Mode:  %.2f\n",System/(float)o);
printf("\n\n*************************\n\n");
printf("IdleMode:  %.2f\n",Idle/(float)o);
printf("\n\n*************************\n\n");
printf("Amount of free memory is :%.2f \nPercentage of available memory is:%.2f \n",sum/(float)o,percent/(float)o);
printf("\n\n*************************\n\n");
printf("\nDisk Read: %.2f\nDisk Write: %.2f\n",sum1/o,sum2/o);
printf("\n\n*************************\n\n");
printf("Context Switches: %.0f\n",sum_i/o);
printf("\n\n*************************\n\n");
printf("Processes: %.0f\n",sum_p/o);
printf("\n\n*************************\n\n");
}

}


}

return 0;
}










