#include <stdio.h>

void merge(int array[], int lo, int mid, int hi) {
    int i = lo;
    int j = mid;
    int k = 0;
    int tmp[hi-lo];

    for ( ; i < mid && j < hi; k++ ) {
        if ( array[i] <= array[j] ) {
            tmp[k] = array[i];
            i += 1;
        } else {
            tmp[k] = array[j];
            j += 1;
        }
    }
    for ( ; i < mid; i++, k++ ) {
        tmp[k] = array[i];
    }
    for ( ; j < hi; j++, k++ ) {
        tmp[k] = array[j];
    }

    for ( int i = lo, j = 0; i < hi; i++, j++ ) {
        array[i] = tmp[j];
    }
}

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

void mergeSort(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;

    if ( mid == lo ) {
        return;
    }

    mergeSort(array, lo, mid);
    mergeSort(array, mid, hi);

    merge(array, lo, mid, hi);
}


int main() {
    int array[10] = {5,9,7,3,6,1,7,8,5,10};

    mergeSort(array, 0, 10);

    arrayPrint(array, 10);

    return 0;
}
