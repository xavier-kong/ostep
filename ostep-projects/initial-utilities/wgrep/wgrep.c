#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace_char(char* str, char find, char replace){
	char *current_pos = strchr(str,find);
	while (current_pos) {
		*current_pos = replace;
		current_pos = strchr(current_pos,find);
	}
	return str;
}

void checkFile(char *filename, char *searchTerm) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("wgrep: cannot open file\n");
		exit(1);
	}

	char line[512];

	while (fgets(line, sizeof(line), fp)) {
		if (strstr(line, searchTerm)) {
			printf("%s", line);
		}
	}

	fclose(fp);

	return;
}

void checkInput(char *searchTerm) {
	char line[512];

	while (fgets(line, sizeof(line), stdin)) {
		if (strstr(line, searchTerm)) {
			printf("%s", line);
		}
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}

	if (argc == 2) {
		if (argv[1][0] == '\0') { // if search term is an empty string
			return 0;
		}

		checkInput(argv[1]);
		return 0;
	}

	for (int i = 2; i < argc; i++) {
		checkFile(argv[i], argv[1]);
	}

	return 0;
}
