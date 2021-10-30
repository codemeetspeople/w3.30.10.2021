#include <stdio.h>

int partition(int array[], int start, int end) {
    int average = (start + end) / 2;
    int marker;
    int buffer = array[average];
    
    array[average] = array[end];
    array[end] = buffer;
    
    for ( marker = start; array[marker] < array[end]; marker++ );
    for ( int i = marker + 1; i < end; i++ ) {
        if ( array[i] <= array[end] ) {
            buffer = array[i];
            array[i] = array[marker];
            array[marker] = buffer;
            marker += 1;
        }
    }
    
    buffer = array[marker];
    array[marker] = array[end];
    array[end] = buffer;
    
    return marker;
}

void quickSort(int array[], int lo, int hi) {
    int pivot;
    
    if ( hi - lo < 1 ) {
        return;
    }
    
    pivot = partition(array, lo, hi);
    
    quickSort(array, lo, pivot-1);
    quickSort(array, pivot+1, hi);
}

int lenScan(FILE *in) {
    int length;
    
    fscanf(in, "%d", &length);
    
    return length;
}

void arrayPrint(FILE *out, int array[], int size) {
    int i = 0;
    
    for ( int last = size - 1; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[i]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = lenScan(in);
    int array[len];
    
    for ( int i = 0; i < len && (fscanf(in, "%d", &array[i])) == 1; i++ );
    fclose(in);
    
    quickSort(array, 0, len-1);
    
    arrayPrint(out, array, len);
    fclose(out);
    
    return 0;
}
