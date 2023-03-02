#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int child1 = fork();

    char inbuf[16];
    int p[2] = {0, 0};

    if (child1 < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (child1 == 0) {

        int child2 = fork();

        write(p[1], "hello!\n", 16);

        if (child2 < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (child2 == 0) {
            read(p[0], inbuf, 16);
            printf("from pipe %s\n", inbuf);
        }
        else {
        }
    }
    else {
    }

    return 0;
}
