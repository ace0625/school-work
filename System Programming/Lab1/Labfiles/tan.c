/* main returns an integer */

#include <stdio.h>
#include <math.h>

int
main(int argc, char *argv[])
{
    /* printf is our output function;
       by default, writes to standard out */
    /* printf returns an integer, but we ignore that */ 
    printf("hello, world\n");
    printf("the tangent of 90 is: %f\n", tan(90));

    /* return 0 to indicate all went well */
    return(0); 
}

