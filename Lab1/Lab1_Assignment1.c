#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
int main(int argc, char * argv[])
{


/* Error Handling */
if(argc==3)
{
char c = argv[1][0];
if((c<='z' && c>='a') || (c<='Z' && c>='A'))
{
printf("Error: Please Enter possitive numbers\n"); // Checking for first argument not to be an alphabet.
return 1;
}
c = argv[2][0];
if((c<='z' && c>='a') || (c<='Z' && c>='A'))
{
printf("Error: Please Enter possitive numbers\n"); // Checking for second argument not to be an alphabet.
return 1;
}
int m =atoi(argv[1]);
int n = atoi(argv[2]);

if(m<=0 || n<=0)
{
printf("Error: Enter only possitive values\n");  //Checking the numbers to be possitive.
return 1;
}


if(n%m!=0)
{
printf("Error: Enter n as a multiple of m\n"); //Checking the second number should be divided by first.
return 1;
}
}

/* Declaration of Vriables*/
int i=0,count=0;
float sum=0,j,a[1000],percent=0,sum3=0,User = 0,System=0,Idle=0,sum1=0,sum2=0,sum_i=0,sum_p=0,p=0,f=0; 
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

int m =atoi(argv[1]);
int n = atoi(argv[2]);
int k = n/m,o=k;

while(1)
{
sum1=0;
sum2=0;
k = n/m;
if(k<=0)
break;
while(k>0)
{
/*The percentage of time the processor(s) spend in user mode, system mode, and
the percentage of time the processor(s) are idle*/
if(k<=0)
break;
sum3 =0;
fp = fopen("/proc/stat","r");
fscanf(fp,"%s",s);
for(i=0;i<10;i++)
{
fscanf(fp,"%s",s);
a[i] = (float)atoi(s);
sum3 = sum3 + a[i];
}

User = User + (a[0]/sum3)*100;
System = System + (a[2]/sum3)*100 ;
Idle = Idle + (a[3]/sum3)*100 ;

fclose(fp);
/*The amount and percentage of available (or free) memory*/



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

fp = fopen("/proc/diskstats","r");

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


/*The rate (number per second) of context switches in the kernel*/
fp = popen("cat /proc/stat | grep 'ctxt' | uniq","r");
fscanf(fp,"%s",s);
fscanf(fp,"%s",s);
i = atoi(s);
sum_i = sum_i + i;
fclose(fp);


/*The rate (number per second) of process creations in the system*/
fp = popen("cat /proc/stat | grep 'processes' | uniq","r");
fscanf(fp,"%s",s);
fscanf(fp,"%s",s);
p = atoi(s);
sum_p = p + sum_p;
fclose(fp);

sleep(m);
k--;

}
count++;

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
printf("\n\n*************************....(%d)\n\n",count);
}
}
}
return 0;
}










