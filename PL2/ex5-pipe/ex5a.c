#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	int d;
	char aux[80];
	FILE *executa;

	executa = popen("ps -ax","r");
	while((d = fread(aux, sizeof(char),80, executa))){
		printf("%s",aux);
		aux[d]='\0';
	}
	pclose(executa);

	return 0;
}

