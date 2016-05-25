#include <stdio.h>

int main()
{
    int x;
   
    printf("Any bit of x equals 1\n");
    printf("x = ");
    scanf("%d",&x);

    if( x & (~0))
	printf("result = 1\n");
     else  
	printf("result = 0\n");

    printf("Any bit of x equals 0\n");
    printf("x = ");
    scanf("%d",&x);

    if( ~x & (~0))  
	printf("result = 1\n");
     else  
	printf("result = 0\n");
    

    printf("Any bit in the least significant byte of x equals 1\n");
    printf("x = ");
    scanf("%d",&x);
    if( x & 0xFF)  
	printf("result = 1\n");
     else  
	printf("result = 0\n");

    printf("Any bit in the most significant byte of x equals 0\n");
    printf("x = ");
    scanf("%d",&x);

    if( ~x&0xFF) 
    	printf("result = 1\n");
     else  
	printf("result = 0\n");

//    x && printf("Any bit of x equals 1\n");
  //  ~x && printf("Any bit of x equals 0\n");
   // (x&0xFF) && printf("Any bit in the least significant byte of x equals 1\n");
   // (~&0xFF) && printf("Any bit in the most significant byte of x equals 0\n");

     return 0;

}
