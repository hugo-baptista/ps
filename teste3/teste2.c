#include <string.h>
#include <stdio.h>
#include <unistd.h>

struct Mensagem {
	char origem[32];
	char destino[32];
} msg;

int main(int argc, char* argv[]) {
	int d[2], pid;

	pipe(d);
	pid=fork();
	if(pid==0) {
		close(d[0]);

		strncpy(msg.origem, argv[1], 32);
		strncpy(msg.destino, argv[2], 32);

		write(d[1], &msg, 64);
		printf("Enviei: origem=%s, destino=%s\n", msg.origem, msg.destino);
		close(d[1]);
	} else {
		close(d[1]);
		while(read(d[0], &msg, 64)>0) {
			printf("Recebi: origem=%s, destino=%s\n", msg.origem, msg.destino);
		}
		close(d[0]);
	}
	return 0;
}
