#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
	int f, i;
	char line[6];
	f=open("/ps/teste3/ex",O_RDONLY);
	printf("A iniciar leitura...\n");
	i=0;
	while(read(f, &line, sizeof(line))>0) {
		line[5]=0;
		i++;
		printf("Linha %d: %s\n", i, line);
		memset(line,0,sizeof(line));
	}
	printf("Concluído\n");
	return 0;
}
