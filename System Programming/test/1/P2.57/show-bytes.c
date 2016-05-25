/*
 ============================================================================
 Name        : show-bytes.c
 Problem #2.57
 Description : This code implements the byte representations of short, long, and double.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef unsigned char *pointer;

void show_bytes(pointer start, int len);
void show_short(short a);
void show_long(long a);
void show_double(double a);

int main(int argc, char *argv[]) {
	
	  int val = 0;
	  short sval = 0;
	  long lval = 0;
	  double dval = 0;
	 
	    do{
	    printf("Enter a integer value(type 0 to exit): ");
	    scanf("%d", &val);
	    if(val=='0')
	    	break;
	    printf("value is = %d\n\n", val);
	    sval = (short)val;
	    lval = (long)val;
	    dval = (double)val;

	    show_short(sval);
	    show_long(lval);
	    show_double(dval);
	    }while(val>0);
	return 0;
}


void show_bytes(pointer start, int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		printf("%p\t 0x%.2x\n", start+i, start[i]);
	}
	printf("\n");
}

void show_short(short a)
{
	printf("<show_short>\n");
	show_bytes((pointer) &a, sizeof(short));
	printf("\n");
}

void show_long(long a)
{
	printf("<show_long>\n");
	show_bytes((pointer) &a, sizeof(long));
	printf("\n");
}

void show_double(double a)
{
	printf("<show_double>\n");
	show_bytes((pointer) &a, sizeof(double));
	printf("\n");
}
