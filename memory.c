#include <stdio.h>
#include <stdlib.h>

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

int main() {
    int* array;

    array = (int*)malloc(SIZE*sizeof(int));

    for ( int i = 0; i < SIZE; i++ ) {
        array[i] = i + 1;
    }
    arrayPrint(array, SIZE);

    array = (int*)realloc(array, (SIZE+SIZE) * sizeof(int));
    arrayPrint(array, SIZE+SIZE);

    free(array);

    return 0;
}
