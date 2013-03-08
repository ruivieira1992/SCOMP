#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int status;
	int aux;

	int k = 0;
	int i = 0;
	int j;

	for(i; i<6 ; i++){
		pid = fork();
		if(pid == 0){
			for(j=(i*20000); j<=(i*20000+20000); j++){
				printf("Num: %d\n",j);
			}
				exit(-1);
		}
	}

	for(i=0;i<6;i++)
		aux = wait(&status);


	printf("--- PAI ---\n");

        return 0;
}
