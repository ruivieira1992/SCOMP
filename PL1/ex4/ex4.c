#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	pid_t pid;
	int aux;
	int f;
	int status;
	for(f=0;f<3;f++)
	{
		pid = fork();
		if(pid < 0){
			printf("Processo mal criado");
			exit(-1);
		} else {
			if(pid > 0)
			{
				printf("Pai:Eu sou o PAI %d\n", getpid());
				do{
					aux = waitpid(pid, &status, WNOHANG);
					
				}while(aux==0);
				if(WIFEXITED(status)){
					printf("O meu filho é %d\n", WEXITSTATUS(status));
				}
			}else{
				printf("O meu pai é %d\n", getppid());
				sleep(4);
				exit(getpid());
			}
		}
	}

	return 0;
}