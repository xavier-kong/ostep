#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 100;
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 50;
        printf("Child value of x: %d\n", x);
    } else {
        printf("Parent value of x: %d\n", x);
    }

    return 0;
}
