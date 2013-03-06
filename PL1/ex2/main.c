#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main (void){
	int pid, pid2,status, status2, aux2, aux;
	pid=fork();
	if(pid<0)
		printf("ERRO!\n");
	else{
		if (pid==0){
			printf("FILHO1!\n");
			sleep(5);
			exit(1);
		}
		else {
			printf("PAI!%d\n", getpid());
			pid2=fork();
			if(pid2<0)
				printf("ERRO!\n");
	else{
		if (pid2==0){
			printf("FILHO2!\n");
			exit(2);
		}
	}	
			do {
				aux = waitpid(pid, &status, WNOHANG);
			} while (aux == 0);
			do{
				aux2 = waitpid(pid2,&status2, WNOHANG);
			}while (aux2 == 0); 
			if(WIFEXITED(status)) {
				printf("PAI: vai-te embora, pois retornou -> %d\n\n", WEXITSTATUS(status));
			}
			if(WIFEXITED(status2)) {
				printf("PAI: vai-te embora, pois retornou -> %d\n\n", WEXITSTATUS(status2));
			}
		}
	}	
	return 0;
}
