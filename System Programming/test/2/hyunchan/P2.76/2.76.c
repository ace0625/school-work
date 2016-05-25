#include <stdio.h>

int main()
{
   int x;
   printf("Multiply a number by a constant K(17, -7, 60, -112)");
   printf(" only using operations +,- and <<\n");
   printf("x = ");
   scanf("%d", &x);
   
   printf("\nK=17 using ((x << 4) + x)\n");
   printf("%d x 17 = %d\n", x, ((x << 4) + x));
   
   printf("\nK=-7 using (x - (x << 3))\n");
   printf("%d x -7 = %d\n", x, (x - (x << 3)));

   printf("\nK=60 using ((x << 6) - x - x - x - x)\n");
   printf("%d x 60 = %d\n", x, ((x << 6) - x - x - x - x));

   printf("\nK=-112 using (x - (x << 6) - (x << 5) - (x << 4) - x)\n");
   printf("%d x -112 = %d\n", x, (x - (x << 6) - (x << 5) - (x << 4) - x));

   return 0;
}
