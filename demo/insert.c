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

void insertSort(int array[], int len) {
    for ( int i = 1; i < len; i++ ) {
        int element = array[i];
        int j = i - 1;
        
        for ( ; j >= 0 && element < array[j]; j-- ) {
            array[j+1] = array[j];
        }
        array[j+1] = element;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = lenScan(in);
    int array[len];

    for ( int i = 0; i < len && (fscanf(in, "%d", &array[i])) == 1; i++ );
    fclose(in);

    insertSort(array, len);

    arrayPrint(out, array, len);
    fclose(in);

    return 0;
}
