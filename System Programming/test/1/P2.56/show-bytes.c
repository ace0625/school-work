/*
 ============================================================================
 Name        : show-bytes.c
 Problem#2.56	
 Description : Running the code for show-bytes for different sample values.
 ============================================================================
 */

#include <stdio.h>

typedef unsigned char *pointer;

void show_bytes(pointer start, int len);

int main()
{
    int val = 0;
    do{
    printf("Enter a integer value(type 0 to exit): ");
    scanf("%d", &val);
    if(val=='0')
 	return 0;
    printf("value is = %d\n", val);
    show_bytes((pointer)&val, sizeof(int));
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

