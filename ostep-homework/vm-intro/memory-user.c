#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {

    printf("PID: %d", getpid());

    if (argc != 3) {
        fprintf(stderr, "./a.out [size] [duration]");
        return 1;
    }

    int size = atoi(argv[1]);
    int duration = atoi(argv[2]);

    if (size == 0 || duration == 0) {
        fprintf(stderr, "size and duration cannot be 0");
        return 1;
    }

    int n = size / sizeof(int);

    int *arr = calloc(n, sizeof(int));

    time_t startTime;
    time(&startTime);

    printf("started at %ld \n", startTime);

    while (difftime(time(NULL), startTime) < duration) {
        for (int i = 0; i < n; i++) {
            int temp = arr[i];
        }
    }

    printf("finished at %ld \n", time(NULL));

    free(arr);

    return 0;
}
