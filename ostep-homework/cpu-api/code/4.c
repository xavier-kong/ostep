#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        char *args[2] = {"/bin/ls", NULL};
        execvp(args[0], args);
    }
    else {
    }

    return 0;
}
