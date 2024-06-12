#include <stdio.h>
#include <unistd.h>

int main() {
        char a[1024];
	int n;

        while ((n = read(0, a, 1024)) > 0) {
		write(1, a, n);
        }
}
