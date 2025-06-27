#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid= fork();
	
	if(pid == 0) 
	{
		printf("1st Child PID = %d\n",getpid());
		printf("Array = %s\n", argv[1]);
		printf("Size of Array = %ld\n\n", strlen(argv[1]));
		char *args[] = {"./q3b", argv[1], NULL};
		execv("./q3b", args);
	}
	else if(pid>0)
	{ 
		wait(NULL);
		pid = fork();
		
		if(pid == 0)
		{
			printf("2nd Child PID: %d\n", getpid());
		}
		else if (pid>0)
		{ 
			wait(NULL);
			printf("Parent PID: %d\n", getppid());
		}
	}
	return 0;
}


















#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	
	int counter = 0;
	printf("PID of 2nd exec = %d\n ",getpid());
	for(int i = 0; argv[1][i] != '\0'; ++i)
	{
		counter++;
	}
	printf("Total elements = %d\n", counter);
	int size=counter*sizeof(char);
	printf("Size in Bytes = %d\n\n", size);
	return 0;
}















