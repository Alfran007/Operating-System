#include "sqrt.h"
int main(int argc,char *argv[])
{
      if(argc ==1 || argc ==0)
            {
                  printf("Error: Enter the number!\n");
            }
	else if(argc==2)
	      {
	            if(argv[1]<0)
	            {
	                  printf("Error:Enter a possitive number!");
	            }
	            else
	            {
		            printf("%.2f\n",sqrt(atoi(argv[1])));
		      }
		}
	else
	      {
	            printf("Error: Enter only one argument!\n");
	      }
	return 0;
}
