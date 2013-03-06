#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	pid_t pid;
	int status;
	int aux;

	int k = 0;
	int i = 0;
	
	for(i; i<6 ; i++){
	pid = fork();
	if(pid > 0){
		do{
			aux = waitpid(pid, &status, WNOHANG);
		}while(aux == 0);
		printf("--------------PAI------------------\n");
	} else {
			int j;
			for(j=0; j<20000; j++){
				printf("Num: %d\n",k);
				k++;
			}
			exit(-1);
	}
		k = k+20000;
	}

	return 0;
}