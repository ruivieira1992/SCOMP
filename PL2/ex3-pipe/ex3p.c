#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int dados[2];
	char buffer[81], aux[81];
	int status, d;

	if(pipe(dados) != 0)
	{
		perror("Erro ao criar o pipe\n");
		exit(-1);
	}

	pid = fork();
	if(pid < 0)
	{
		printf("ERRO!\n");
		exit(-1);
	}
	if(pid > 0)
	{
		close(dados[0]);
		dup2(dados[1],1);
		close(dados[1]);

		execlp("cat","cat","fich.txt",NULL);

		wait(&status);
	} else {
		close(dados[1]);
		dup2(dados[0],0);
		close(dados[0]);

		execlp("od","od",NULL);
	}

	return 0;
}
