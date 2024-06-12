#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int file=open("ta_txt", O_WRONLY | O_CREAT | O_TRUNC);
	for(int i=0; i<100000; i++) {
		int x = 0, y = 1;
		if (i==50001 || i==99999) {
			write(file, &y, sizeof(int));
		} else {
			write(file, &x, sizeof(int));
		}
	}
	close(file);
	return 0;
}
