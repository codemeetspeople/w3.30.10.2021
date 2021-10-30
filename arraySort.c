#include <stdio.h>

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

int partition(int array[], int start, int end) {
    int avg = (start + end) / 2;
    int pivot = array[avg];
    int tail = start;

    array[avg] = array[end];
    array[end] = pivot;

    for ( ; array[tail] < array[end]; tail++);
    for ( int i = tail + 1; i < end; i++ ) {
        if ( array[i] < array[end] ) {
            pivot = array[i];
            array[i] = array[tail];
            array[tail] = pivot;
            tail += 1;
        }
    }
    pivot = array[end];
    array[end] = array[tail];
    array[tail] = pivot;

    return tail;
}

void quickSort(int array[], int start, int end) {
    if ( start >= end ) {
        return;
    }
    int index = partition(array, start, end);

    quickSort(array, start, index-1);
    quickSort(array, index+1, end);
}

int main() {
    int array[10] = {5,9,7,3,6,1,4,8,2,10};

    quickSort(array, 0, 9);
    arrayPrint(array, 10);

    return 0;
}
