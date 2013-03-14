#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int aux, *escolha;
	int quantia = 25;
	do{

		do{
			printf("Escolha um numero: \n");
			scanf("%d",&escolha);
		}while((int) escolha < 1 || (int) escolha > 5);

		pid = fork();
	
		if(pid == 0){
			aux = execlp("./batota","batota",NULL);
			
		}
		
		wait(&aux);
	
		printf("AUX = %d\n",WEXITSTATUS(aux));
	
		if((int) WEXITSTATUS(aux) == (int) escolha){
			printf("ACERTOU!!!!\n");
			quantia = quantia + ((int) escolha * 2);
		}
		else {
			printf("FALHOU!!!!\n");
			quantia = quantia - ((int) escolha * 2);
		}
		printf("Quantia = %d\n",quantia);
	}while(quantia>0);

	printf("PERDEU TUDO!\n");

	return 0;
}

