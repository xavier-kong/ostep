#include <stdio.h>
#include <stdlib.h>

void readFile(char *filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("wcat: cannot open file\n");
		exit(1);
	}

	char buff[100];
	int lineNum = 100;

	while (1) {
		if (fgets(buff, lineNum, fp) == NULL) {
			break;
		}

		printf("%s", buff);
	}

	fclose(fp);
}

int main(int argc, char **argv) {
	if (argc == 1) {
		exit(0);
	}

	for (int i = 1; i < argc; i++) {
		readFile(argv[i]);
	}

	return 0;
}
