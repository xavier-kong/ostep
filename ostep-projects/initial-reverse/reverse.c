#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "no arguments passed\n");
        exit(1);
    }

    if (argc == 2 || argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    if (argv[1] == argv[2]) {
        fprintf(stderr, "Input and output file must differ\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "error: cannot open file %s", argv[1]);
        exit(1);
    }

    // count number of lines
    // malloc array and add string to array
    // read lines backwards and write to new file

    return 0;
}
