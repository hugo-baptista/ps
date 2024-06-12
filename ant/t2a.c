#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	int d[2][2];
	pipe(d[0]);
	pipe(d[1]);

	int n, c, l = 0;

	int pid=fork();

	if(pid==0) {
		close(d[0][1]);
		close(d[1][0]);

		while(n = read(d[0][0], &c, 1) > 0) {
			printf("Recebido: char=%c, int=%d\n",c,c);
			if(c=='\n') {
				l++;
			}
		}

		write(d[1][1], &l, sizeof(int));

		close(d[1][1]);
                close(d[0][0]);
	} else {
		close(d[1][1]);
                close(d[0][0]);

		while(n = read(0, &c, 1) > 0) {
                	write(d[0][1], &c, 1);
                }

		close(d[0][1]);
		wait(NULL);

		read(d[1][0], &l, sizeof(int));
		printf("Número de linhas=%d\n", l);

                close(d[1][0]);
	}

	return 0;
}

