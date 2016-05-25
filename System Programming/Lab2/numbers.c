
#include <stdio.h>


#define NOSIGN 47U
#define YESSIGN 47


int
main ()
{
	int i, j;
	unsigned int x, y;
	const int J = -53;
	const unsigned int K = 63;
	
	i = -255;
	j = 10;
	x = 512;
	y = 20;

	printf ("i: %d, j: %d, x: %u, y: %u, J: %d, K:  %u\n", i, j, x, y, J, K);
	printf (" NOSIGN %du, YESSIGN %d \n", NOSIGN, YESSIGN);


	char c = 'a';
	printf ("c = %c; i = %d \n", c, i);
	i = c;
	c = i;
	printf ("c = %c; i = %d \n", c, i);
	c = 'a';
	i = -255;
	printf ("c = %c; i = %d \n", c, i);
	c = i;
	i = c;
	printf ("c = %c; i = %d \n", c, i);

}
