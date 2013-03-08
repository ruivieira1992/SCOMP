#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

char criaGemeos(pid_t lista[2]){

	pid_t pid, pid2;
	pid = fork();
	if(pid < 0){
		printf("ERRO\n");
		exit(-1);
	}
	
	if(pid == 0) /*---filho 1---*/
		return 'a';

	lista[0] = pid;
	pid2 = fork();
	if(pid2 < 0){
				printf("ERRO\n");
				exit(-1);
			}
	if ( pid2==0) return 'b';

			
	lista[1] = pid2;

	return 'p';
}



int main(){


	pid_t lista[2];

	char a = criaGemeos(lista);
	printf("CHAR RETORNO = %c\n", a);

	if(a == 'p') {
		int i;
		for(i=0; i<2; i++){
			printf("PID LISTA  = %d\n", lista[i]);
		}
	}
	return 0;
}




