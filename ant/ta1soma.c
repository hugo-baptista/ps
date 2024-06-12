#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int n, c, r = 0, d[2];
	pipe(d);

	int pid = fork();

	if(pid==0) {
		close(d[0]);
		int file = open(argv[1], O_RDONLY);
		while(n = read(file, &c, sizeof(c)) > 0) {
			write(d[1], &c, sizeof(c));
		}
		close(file);
		close(d[1]);
	} else {
		close(d[1]);
		while(n = read(d[0], &c, sizeof(c)) > 0) {
			if(c!=0) {
				r += c;
			}
		}
		close(d[0]);
		printf("O resultado final é: %d\n", r);
	}

	return 0;
}
