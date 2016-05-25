/*
 ============================================================================
 Name        : show-bytes.c
 Problem#2.55	
 Description : This code shows byte representation of data in pointer and hexadecimal
 ============================================================================
 */

#include <stdio.h>

typedef unsigned char *pointer;

void show_bytes(pointer start, int len);

//int main(int argc, char *argv[])
int main()
{
    int val = 15213;
    printf("value is = %d\n", val);
    show_bytes((pointer)&val, sizeof(int));


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

