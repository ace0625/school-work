//CS201, Exercise#2, problem#3
//Hyunchan Kim

#include <stdio.h>

int main()
{
   int a, b, c;
   unsigned int x, y ,z;

   a = -2; b = 10, c = 200; //int values
   x = -2; y = 33, z = 233; //unsigned values
   printf("int values: a=-2, b=10, c=200\n");
   printf("unsigned values: x=-2, y=10, z=200\n\n");

   printf("\t\t  <int>\t\t <unsigned>\n");
   printf("=1 left shift=\t a = %d\t\t x = %u\n", a<<1, x<<1);
   printf("\t\t b = %d\t\t y = %u\n", b<<1, y<<1);
   printf("\t\t c = %d\t z = %u\n", c<<1, z<<1);

   printf("=2 left shift=\t a = %d\t\t x = %u\n", a<<2, x<<2);
   printf("\t\t b = %d\t\t y = %u\n", b<<2, y<<2);
   printf("\t\t c = %d\t z = %u\n", c<<2, z<<2);

   printf("\n=1 right shift=\t a = %d\t\t x = %u\n", a>>1, x>>1);
   printf("\t\t b = %d\t\t y = %u\n", b>>1, y>>1);
   printf("\t\t c = %d\t z = %u\n", c>>1, z>>1);

   printf("=2 right shift=\t a = %d\t\t x = %u\n", a>>2, x>>2);
   printf("\t\t b = %d\t\t y = %u\n", b>>2, y>>2);
   printf("\t\t c = %d\t\t z = %u\n", c>>2, z>>2);

 
   
   return 0;
}
