#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int p;

	printf("pai= %d\n", getpid());
	p=fork ();

	if (p==0) {
	printf("sou o filho\n");
	}
	printf("pid= %d\n", p);

}
