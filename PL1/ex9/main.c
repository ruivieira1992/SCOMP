#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	int status, aux;
	int vec[100000];

	int f;
	for(f=0; f<100000; f++){
		vec[f] = f;
	}
	int num = 30012;
	int i,p;
	int flag =0;
	for(i=0; i<5 ; i++){
		pid = fork();
		if(pid<0){
			printf("ERRO!\n");
			exit(-1);
		} else {
			if(pid==0) { /* --- FILHO --- */
				if(flag == 0) {
					for(p = (i*20000); p<(i*20000+20000); p++){
						if(vec[p] == num){
							printf("Foi encontrado o numero %d na posicao %d do vector.\n", num, p);
							flag = 1;
							exit(i+1);
						}
					}
					if(flag == 0)
						exit(0);
				} else {
					exit(0);
				}
			} else if(pid>0){ /* --- PAI --- */
				aux = wait(&status);
				if(WIFEXITED(status)){
					if(WEXITSTATUS(status)>0){
						printf("O filho que encontrou o numero foi o filho cujo processo é o numero %d\n", WEXITSTATUS(status));
					}
				}
			}



		}







	}






return 0;
}
