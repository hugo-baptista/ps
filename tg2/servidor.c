#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int f,d[2],pid;
	char origem[2048],destino[2048],argumentos[4096],ficheiro[2048];

	f=open("fifo_bkp",O_RDONLY);
	
	while(true) {
		while(read(f,argumentos,sizeof(argumentos))>0) {
			printf("Recebi: %s\n", argumentos);

			strcpy(origem, strtok(argumentos, " "));
			printf("Origem: %s\n", origem);

			strcpy(destino, strtok(NULL, " "));
			printf("Destino: %s\n", destino);

			pipe(d);
			pid=fork();
			if(pid==0) {
				close(d[0]);
				for(int i=1; i<21; i++) {
					sprintf(ficheiro,"%s/F%i",origem,i);
					write(d[1],ficheiro,sizeof(ficheiro));
				}
				close(d[1]);
				exit(0);
			}

			close(d[1]);
			while(read(d[0],ficheiro,sizeof(ficheiro))>0) {
				pid=fork();
				if(pid==0) {
					close(d[0]);
					execlp("cp","cp",ficheiro,destino,NULL);
					exit(-1);
				}
			}

			memset(origem,0,sizeof(origem));
			memset(destino,0,sizeof(destino));
			memset(argumentos,0,sizeof(argumentos));
		}
	}

	close(f);
	return 0;
}
