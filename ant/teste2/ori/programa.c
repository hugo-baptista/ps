#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int t, pid, d[2];
	t=atoi(argv[1])*60;
	char name[2], line[4096];
	while(true) {
		pipe(d);
		pid=fork();
		if(pid==0) {
			close(d[0]);
			dup2(d[1],1);
			close(d[1]);
			execlp("script","script",NULL);
			exit(-1);
		} else {
			close(d[1]);
			while(read(d[0], &name, sizeof(name))>0) {
				pid=fork();
				if(pid==0) {
					name[2]=0;
					execlp("cp","cp",name,argv[2],NULL);
				}
			}
			close(d[0]);
		}
		sleep(t);
	}
	return(-1);
}
