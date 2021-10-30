#include <stdio.h>

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

void bubbleSort(int array[], int size) {
    for ( ; size > 1; ) {
        int last = 1;
        
        for ( int i = 1, j = 0; i < size; i++, j++ ) {
            int lo = array[j];
            int hi = array[i];
            
            if ( hi < lo ) {
                array[i] = lo;
                array[j] = hi;
                last = i;
            }
        }
        size = last;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = lenScan(in);
    int array[len];

    for ( int i = 0; i < len && (fscanf(in, "%d", &array[i])) == 1; i++ );
    fclose(in);

    bubbleSort(array, len);

    arrayPrint(out, array, len);
    fclose(in);

    return 0;
}
