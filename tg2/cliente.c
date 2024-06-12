#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]) {
	// origem = pasta corrente (pwd)
	// destino = argv[1]

	char origem[2048],destino[2048],argumentos[4096];
	int d[2],g[2],pid;
	pipe(d);

	if(argc==2) {
		pid=fork();
		if(pid==0) {
			pipe(g);
			pid=fork();
			if(pid==0){
				dup2(g[1],1);
				close(d[0]);close(d[1]);close(g[0]);close(g[1]);
				execlp("pwd", "pwd", NULL);
				exit(-1);
			} else {
				dup2(g[0],0);dup2(d[1],1);
				close(g[0]);close(g[1]);close(d[0]);close(d[1]);
				execlp("tr", "tr", "-d", "'\n'", NULL);
				exit(-1);
			}
		} else {
			close(d[1]);
			read(d[0], origem, sizeof(origem));
			close(d[0]);
			printf("Origem: %s\n", origem);
		
			strcpy(destino, argv[1]);
			printf("Destino: %s\n", destino);
		}
	} else {
		strcpy(origem, argv[1]);
		printf("Origem: %s\n", origem);

		strcpy(destino, argv[2]);
		printf("Destino: %s\n", destino);
	}

	int f=open("fifo_bkp",O_WRONLY);
	sprintf(argumentos,"%s %s",origem,destino);
	write(f,argumentos,sizeof(argumentos));
	close(f);
	printf("Enviei: %s\n", argumentos);
	return 0;
}
