
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid, pid2;


	int i;
	for(i=0; i<2; i++){
		pid = fork();
		if(pid<0){
			printf("ERRO!\n");
			exit(-1);
		} else {
			
			if(pid > 0){
				printf("A\n");
			} else if (pid == 0) {
				printf("B\n");
				pid2 = fork();
				if(pid2 > 0){
					printf("A\n");
				} else {
					exit(0);
					//printf("B\n");
				}
					
			}
		}	
	}

return 0;
}
