#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fp = fopen("2.txt", "w");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char str[] = "from child";
        fwrite(str, 1, sizeof(str), fp);
    } else {
        char str[] = "from parent";
        fwrite(str, 1, sizeof(str), fp);
    }

    fclose(fp);

    return 0;
}
