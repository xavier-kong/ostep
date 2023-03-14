#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(100);

    free(arr);

    printf("%d", arr[0]);

    return 0;
}
