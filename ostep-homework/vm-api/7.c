#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(100);
    int test = 5;
    int *p = &test;

    arr[12] = p;

    return 0;
}
