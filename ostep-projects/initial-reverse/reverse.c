#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkIfSameFile(char *file1, char *file2) {
    // if / in file name, split and take only last portion
    // if / not in file name, it is the file name
    // strcmp files
    return 0;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "no arguments passed\n");
        exit(1);
    }

    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    int isSameFile = checkIfSameFile(argv[1], argv[2]);

    if (isSameFile) {
        fprintf(stderr, "reverse: input and output file must differ\n");
        exit(1);
    }

    FILE *output = fopen(argv[2], "w");

    if (output == NULL) {
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
        exit(1);
    }

    char *lines[sizeof(size_t)];
    char line[sizeof(size_t)];
    int i = 0;

    while (fgets(line, sizeof(line), fp)) {
        lines[i] = malloc(strlen(line) + 1);
        strcpy(lines[i], line);
        i++;
    }

    for (int j = i; j > -1; j--) {
        fprintf(output, "%s\n", lines[j]);
    }

    return 0;
}
