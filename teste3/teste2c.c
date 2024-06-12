#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	struct Mensagem {
		char origem[32];
		char destino[32];
	};

	struct Mensagem msg;

	int f;
     	f=open("finfa",O_WRONLY);

	strncpy(msg.origem, argv[1], sizeof(msg.origem));
	strncpy(msg.destino, argv[2], sizeof(msg.destino));

	write(f, &msg, sizeof(msg));
	printf("Enviei: origem=%s, destino=%s\n", msg.origem, msg.destino);
	close(f);

	return 0;
}
