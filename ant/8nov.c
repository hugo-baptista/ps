#include <stdio.h>

int main(){
	int a[10];
	int i;

	i=0;
	while (i<10){
		a[i]=i+1;
		i=i+1;
	}

	for (i=0; i<10; i=i+1){
		printf("a[%d]=%d\n", i, a[i]);
	}
}
