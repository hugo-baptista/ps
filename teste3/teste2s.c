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

	int f=open("finfa",O_RDONLY);
	while(read(f, &msg, sizeof(msg))>0) {
		printf("Recebi: origem=%s, destino=%s\n", msg.origem, msg.destino);
	}
	close(f);
	return 0;
}
