#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	char *cmd;
	int status, flag = 0;
	pid_t pid;

	do{
		pid = fork();
	
		if(pid == 0){ /*--- FILHO ---*/
			printf("cmd > ");
			scanf("%s",&cmd);
			if(strcmp(&cmd,"sair") == 0){
				exit(2);
			}

			execlp(&cmd,&cmd,NULL);
		}
		/*--- PAI ---*/
		wait(&status);
	}while(WEXITSTATUS(status) == 0);



	return 0;
}
