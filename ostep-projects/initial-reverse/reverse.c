#include <libgen.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char *get_filename_ext(const char *filename) {
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return "";
    return dot + 1;
}

char *getFileName(char *path) {
    char *bname;
    char *ext;
    char *path2 = strdup(path);
    bname = basename(path2);
    ext = get_filename_ext(path);
    char *fullName = concat(bname, ext);
    return fullName;
}

int checkIfSameFile(char *file1, char *file2) {
    // if / in file name, split and take only last portion
    // if / not in file name, it is the file name
    // strcmp files
    // https://linux.die.net/man/3/basename
    // https://stackoverflow.com/questions/5901624/how-to-extract-a-file-name-from-a-full-path
    char *file1Name = getFileName(file1);
    char *file2Name = getFileName(file2);

    if (strcmp(file1Name, file2Name) == 0) { // strings are equal
        return 1;
    }
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

    for (int j = i - 1; j > -1; j--) {
        fprintf(output, "%s", lines[j]);
    }

    return 0;
}
