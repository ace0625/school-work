#include <stdio.h>

int main(int argc, char *argv[])
{
	char buffer[20];
	char name[20];
	printf("name: ");
	scanf("%s",&buffer);
	strcpy(name, buffer);
	printf("%s\n", name);
	return 0;
}
