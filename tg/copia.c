#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>       
#include <sys/wait.h>

#define DISCO "/tmp/TG/backup"

int main(int argc, char* argv[]) {
	char pasta[64];
	int i, pid;

	for(i=1; i<21; i++) {
		pid=fork();
		if(pid==0) {
			sprintf(pasta, "%s/F%i", argv[1], i);
			execlp("cp", "cp", pasta, DISCO, NULL);
			exit(-1);
		}
	}

	for(i=0; i<20; i++) {
		int x = wait(NULL);
		if (x!=0) {
			printf("ERRO\n");
			return 1;
		}
	}
	
	return 0;
}
