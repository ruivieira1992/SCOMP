#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	pid_t pid;
	int dados[100000];
	int resultado[100000];	
	int x=0, status, aux;
	int cont = 0;

	for(x;x<100000;x++)
	{
		dados[x] = cont;
		cont++;
	}
	int i =0;
	pid = fork();
	if(pid<0)
	{
		printf("Erro!\n");
	}else{
		if(pid > 0)
		{
			
			do{
				aux = waitpid(pid, &status, WNOHANG);
				
			}while(aux == 0);
				i=50000;
				for(i;i<100000;i++)
				{
					resultado[i] = dados[i]*4 + 20;
					printf("Resultado %d = %d\n",i, resultado[i]);
				}
		} else {
			for(i;i<50000;i++)
			{
				resultado[i] = dados[i]*4 + 20;
				printf("Resultado %d = %d\n",i, resultado[i]);
			}
			exit(0);

		}
	}	

	return 0;
}

