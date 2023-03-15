#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int runInteractive() {
    char buff[99999];

    while (1) {
        printf("wish> ");

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            return 0;
        }

        buff[strlen(buff) - 1] = '\0';

        if (strcmp(buff, "exit") == 0) {
            return 0;
        }

    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc == 1) { // interactive mode
        int status = runInteractive();
        exit(status);
    } else if (argc == 2) { // batch mode
    }
}

