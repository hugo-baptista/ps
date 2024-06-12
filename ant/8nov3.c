#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        char a[1024];
        int n;
	int p[2];	// descritores de pipeline

	pipe (p);	// habemus pipe

	int f = fork();	// cria o filho
	if (f==0) {	// instruções para o filho
		while ( (n = read(p[0], a, 1024)) > 0) {	// lê do pipeline
			write(1, a, n);
        	}
		exit(0);
	}

	while ( (n = read(0, a, 1024)) > 0) {
        	write(p[1], a, n);	// o pai escreve no pipeline
        }
}
