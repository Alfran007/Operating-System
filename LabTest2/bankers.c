
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void main() {
	int k=0,d=0,t=0,i,pno,j,r,c=0;
	int x=10,y=5;

    /* Dynamic Allocation of arrays*/
    int *a[x];
    for (i=0; i<x; i++)
         a[i] = (int *)malloc(y * sizeof(int));
    int *need[x];
    for (i=0; i<x; i++)
         need[i] = (int *)malloc(y * sizeof(int));
    int *MAX[x];
    for (i=0; i<x; i++)
         MAX[i] = (int *)malloc(y * sizeof(int));

    int *p=(int *)malloc(x*sizeof(int));
    int *ins=(int *)malloc(y*sizeof(int));
    int *b=(int *)malloc(y*sizeof(int));
    int *op=(int *)malloc(x*sizeof(int));


	printf("\nEnter the number of resources : ");
	scanf("%d", &r);
	printf("\nEnter the max instances of each resources:\n");
	for (i=0;i<r;i++) {
		b[i]=0;
		printf("%c= ",(i+97));
		scanf("%d",&ins[i]);
	}
	printf("\nEnter the number of processes : ");
	scanf("%d", &pno);
	printf("\nEnter the allocation matrix \n     ");
	for (i=0;i<r;i++)
	printf(" %c",(i+97));
	printf("\n");
	for (i=0;i <pno;i++) {
		p[i]=i;
		printf("p[%d]  ",p[i]);
		for (j=0;j<r;j++) {
			scanf("%d",&a[i][j]);
			b[j]+=a[i][j];
		}
	}
	printf("\nEnter the MAX matrix\n    ");
	for (i=0;i<r;i++) {
		printf(" %c",(i+97));
		b[i]=ins[i]-b[i];
	}
	printf("\n");
	for (i=0;i <pno;i++) {
		printf("p[%d] ",i);
		for (j=0;j<r;j++)
		 scanf("%d", &MAX[i][j]);
	}
	printf("\n");
	A: d=-1;
	for (i=0;i <pno;i++) {
		c=0;
		t=p[i];
		for (j=0;j<r;j++) {

			need[t][j] = MAX[t][j]-a[t][j];

			if(need[t][j]<=b[j])
			 c++;



		}
		if(c==r) {
			op[k++]=p[i];
			for (j=0;j<r;j++)
			b[j]+=a[t][j];
		} else
		 p[++d]=p[i];
	}
	if(d!=-1) {
		pno=d+1;
		goto A;
	}

	for (i=0;i<k;i++)
	printf("p[%d] ",op[i]);
	printf("\n");

}
