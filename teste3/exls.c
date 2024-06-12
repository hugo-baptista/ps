#include <stddef.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char l[32];
	strcpy(l,"ls");
	execlp(l,l,NULL);
	return 1;
}
