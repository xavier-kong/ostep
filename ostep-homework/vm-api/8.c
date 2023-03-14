#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity; // how many elements it could potentially hold
    int length; // how many elements it is currently holding (conveniently also
                // the next available index)
    int arr[];    // the actual array
} Array;

// ok maybe not

void append(Array *array, int item) { int length = 0; }

int main() {
    int size = 25;
    int *arr = (int *)malloc(size * sizeof(int));

    int idx = 0;

    while (size < 100) {
        if (idx == size - 1) {
            size *= 2;
            arr = realloc(arr, (size * sizeof(int)));
        }

        arr[idx] = 1;
        idx++;
    }

    return 0;
}
