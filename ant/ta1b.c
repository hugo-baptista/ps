#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int np=atoi(argv[1]), max=atoi(argv[2]), j, i, n, banda, limi, lims, d[np][2], pid[np];
	for(i=0; i<np; i++) {
		pipe(d[i]);
	}

	int list[100000] = {};
	for(i=0; i<100000; i++)
		list[i]=0;
	list[500]=1;
	list[0]=1;
	list[50001]=1;
	list[99999]=1;

	banda = max / np;
	for(j=1; j<np+1; j++) {
		pid[j-1]=fork();
		if(pid[j-1]==0) {
			close(d[j-1][0]);
			limi=(j-1)*banda+1;
			lims=j*banda+1;
			for(i=limi; i<lims; i++) {
				if(list[i-1]==1) {
//					printf("(filho %d) valor(%d)->%d\n", j, i, list[i-1]);
					write(d[j-1][1],&i,sizeof(int));
				}
			}
			close(d[j-1][1]);
			exit(0);
		}
	}

	for(j=1; j<np+1; j++) {
		close(d[j-1][1]);
		i=0;
		while(n = read(d[j-1][0], &i, sizeof(int)) > 0) {
			printf("Filho %d encontrou na posição %d\n", j, i);
		}
		if(i==0) {
		printf("Filho %d não encontrou\n", j);
		}
		close(d[j-1][0]);
	}
	return(0);
}
