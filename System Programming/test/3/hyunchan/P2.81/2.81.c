/* CS201
 * problem #2.81
 * Hyunchan Kim
 * 1/28/2014
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   //arbitrary values
    int x = rand();
    int y = rand();

    //convert to unsigned
    unsigned int ux;
    ux = (unsigned int) x;
    unsigned int uy;
    uy = (unsigned int) y;



    printf("ux = %u, uy = %u\n\n", ux, uy);
    printf("A. (x < y) == (-x > -y) :  %u\n", (x < y) == (-x > -y));
    printf("B. ((x + y) << 4) + y-x == 17*y+15*x :  %u\n", ((x + y) << 4) + y-x == 17*y+15*x);
    printf("C. ~x + ~y + 1 == ~(x+y) :  %u\n", ~x + ~y + 1 == ~(x+y));
    printf("D. (ux-uy) == -(unsigned)(y-x) :  %u\n", (ux-uy) == -(unsigned)(y-x));
    printf("E. ((x >> 2) << 2) <= x :  %u\n", ((x >> 2) << 2) <= x);



    return 0;
}
