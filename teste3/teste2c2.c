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

	sprintf(msg.origem, "%s", argv[1]);
	sprintf(msg.destino, "%s", argv[2]);

	write(f, &msg, sizeof(msg));
	printf("Enviei: origem=%s, destino=%s\n", msg.origem, msg.destino);
	close(f);

	return 0;
}
