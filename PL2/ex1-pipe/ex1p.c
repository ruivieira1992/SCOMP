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
	FILE *executa;

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

		executa = popen("cat < fich.txt","r");
		while(d=fread(buffer,sizeof(char),80,executa)){
			buffer[d]="\0";

		}
		pclose(executa);

		write(dados[1],buffer, sizeof(buffer));
		close(dados[1]);

		wait(&status);
	} else {
		close(dados[1]);
		read(dados[0],aux,sizeof(aux));
		printf("%s\n",aux);
		close(dados[0]);
	}

	return 0;
}