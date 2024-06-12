#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	char jun[4096], a1[2048], a2[2048], res1[2048], res2[2048];
	
	sprintf(a1, "chupapi");
	sprintf(a2, "muñaño");
	printf("a1=%s, a2=%s\n", a1, a2);

	sprintf(jun, "%s-%s", a1, a2);
	printf("juntos=%s\n",jun);

	strcpy(res1, strtok(jun,"-"));
	strcpy(res2, strtok(NULL," "));
	printf("strcpy: res1=%s, res2=%s\n", res1, res2);

	memset(res1, 0, sizeof(res1));
	memset(res2, 0, sizeof(res2));
	printf("limpos: res1=%s, res2=%s\n", res1, res2);

	sprintf(jun, "%s-%s", a1, a2);
        printf("juntos=%s\n",jun);

	sprintf(res1, "%s", strtok(jun,"-"));
	sprintf(res2, "%s", strtok(NULL," "));
	printf("sprintf: res1=%s, res2=%s\n", res1, res2);
}
