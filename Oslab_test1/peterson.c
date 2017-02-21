#include<stdio.h>
#include<stdlib.h>
int f[2] = {0, 0};
int t;
/* Process 1 */
void pro1(int f[],int t){
         f[0] = 1;
         t = 1;
         while (f[1]==1 && t == 1)
         {
         }
         printf("Process 1 is executing\n");
         f[0] =0;
         return;
}
/* Process 2 */
void pro2(int f[],int t){
    f[1] = 1;
    t = 0;
    while (f[0]==1 && t == 0)
    {
    }
    printf("Process 2 is executing\n");
    f[1] = 0;
    return;
}
int main (void)
{
int k = 10;
/* Loop to execute the processes*/
while(k--)
{
    if(f[0]==0 && t==0)
    pro1(f,t);
    if(f[1]==0 && t==0)
    pro2(f,t);
}
return 0;
}
