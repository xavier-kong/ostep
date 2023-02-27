#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handleLine(char line[512]) {
    int len = strlen(line);

    if (len == 0) {
        return;
    }

    char *currChar = &line[0];
    int currCount = 0;

    for (int i = 0; i < len; i++) {
        if (*currChar == line[i]) {
            currCount++;
        } else {
            fwrite(currChar, strlen(currChar), 1, stdout);
            // stdout
            // change char and count
        }
    }
}

void compressFile(char *filename) {
    // open file
    // for each line in file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("wzip: cannot open file\n");
        exit(1);
    }

    char line[512];

    while (fgets(line, sizeof(line), fp)) {
        handleLine(line);
    }

    fclose(fp);

    return;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("wzip: file1 [file2 ...]");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        compressFile(argv[i]);
    }
}
