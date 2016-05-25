#include <stdio.h>

int odd_ones(unsigned x); //return 1 when x contains an odd number of 1s;
			  // 0 otherwise.

int main()
{
   int x;

   printf("x = ");
   scanf("%d", &x);
   
   printf("\nreturn %d\n", odd_ones(x));

   return 0;
}

int odd_ones(unsigned x)
{
   x ^= x >> 16;
   x ^= x >> 8;
   x ^= x >> 4;
   x ^= x >> 2;
   x ^= x >> 1;
   x &= 1;
   return x;
} 
