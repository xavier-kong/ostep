#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("need arg");
        return 1;
    }

    if (argc > 2) {
        printf("too many arg lol");
        return 1;
    }

    int val = atoi(argv[1]);

    if (val == 0) {
        printf("invalid integer %s", argv[1]);
        return 1;
    }

    struct timeval startTime, endTime;
    gettimeofday(&startTime, NULL);

    for (int i = 0; i < val; i++) {
        read(0, NULL, 0);
    }

    gettimeofday(&endTime, NULL);

    long long startUSecs = startTime.tv_sec * 1000000 + startTime.tv_usec;
    long long endUSecs = endTime.tv_sec * 1000000 + endTime.tv_usec;

    printf("time used: %lld", endUSecs - startUSecs);
}

