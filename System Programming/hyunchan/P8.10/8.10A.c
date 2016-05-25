#include <stdio.h>


int main()
{
   
   printf("<<A. fork() >>\n");
   if(fork() == 0)
       printf("from child \n");
   else
	printf("from parent \n\n");



  return 0;
}

