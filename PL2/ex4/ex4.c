#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int status;

	pid_t pid;

	for(i=0; i<argc; i++)
	{
		pid = fork();
		if(pid < 0){
			printf("ERRO\n");
			exit(-1);
		}

		if(pid == 0){
			execlp(argv[i+1],argv[i+1],NULL);
		}
	}
	
	for(i=0; i<argc; i++)
	{
		wait(status);
	}

	return 0;
}

