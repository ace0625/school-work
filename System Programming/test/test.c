#include <stdio.h>
 #define NORMAL_BUFFER_SIZE 32


int getbuf();

void test();

int main()
{
	test();
	return 0;
}

int getbuf()
 {
 char buf[NORMAL_BUFFER_SIZE];
 Gets(buf);
 return 1;
 }


void test()
/*  test function:*/
{
int val;
/* Put canary on stack to detect possible corruption */
volatile int local = uniqueval();
 
val = getbuf();
 
/* Check for corrupted stack */
if (local != uniqueval()) {
printf("Sabotaged!: the stack has been corrupted\n");
 }
 
 else if (val == cookie) {
 printf("Boom!: getbuf returned 0x%x\n", val);
 validate(3);
 } else {
 printf("Dud: getbuf returned 0x%x\n", val);
 }
}
