#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	int d;
	char aux[101];
	FILE *executa;

	executa = popen("sort fich.txt","r");
	while((d = fread(aux, sizeof(char),100, executa))){
		printf("%s",aux);
	}
	pclose(executa);

	

	return 0;
}

