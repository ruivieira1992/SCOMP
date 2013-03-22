#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int dados[2];
	int status;

	if(pipe(dados) != 0){
		printf("ERRO NO PIPE!\n");
		exit(-1);
	}

	pid = fork();

	if(pid < 0){
		printf("ERRO NO FORK!\n");
		exit(-1);
	} else {
		if(pid > 0){ /*--- PAI ---*/
			close(dados[0]);
			dup2(dados[1],1);
			close(dados[1]);
	
			execlp("cat","cat", "fich.txt",NULL);
	
			wait(&status);
		} else { /*--- FILHO ---*/
			close(dados[1]);
			dup2(dados[0],0);
			close(dados[0]);

			execlp("sort", "sort",NULL);
		} 
	}

	return 0;
}
