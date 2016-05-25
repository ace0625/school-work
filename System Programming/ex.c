/*
 ============================================================================
 Name        : ex.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
int  main()
{
	if(fork() ==0)
	{
		if(fork() ==0)
		{
			printf("3");
		}
		else
		{
			pid_t pid; int status;
			if((pid = wait(&status)) > 0)
			{
				printf("4");
			}
		}
	}
	else
	{
		if(fork() ==0)
		{
			printf("1");
			exit(0);
		}
		printf("2");
	}
	printf("0");

	return 0;
}
