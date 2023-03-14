#include <stdio.h>

int main() {
    int num = 1;
    int *p = &num;

    p = NULL;

    printf("%d", *p);
}
