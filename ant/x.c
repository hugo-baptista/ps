#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 4096

int main(int argc, char* argv[]) {
	char buf [MAX];
	int n=1;
	int d,d1;

//	if (argc ... não dá jeito) {perror, return}

	for (int i=0; i<=2; i++) {
		printf("argv[%d]-%s\n", i, argv[i]);
	}

	d = open (argv[1], O_RDONLY);
	if (d == -1) {
		perror ("Erro na abertura do ficheiro de leitura");
		return (-1);
	}

	d1 = open (argv[2], O_WRONLY|O_CREAT|O_TRUNC);
        if (d1 == -1) {
                perror ("Erro na abertura do ficheiro de escrita");
                return (-1);
        }

	while (n > 0) {
		n = read (d, buf, MAX);
		write (d1, buf, n);
	}

	return(0);
}
