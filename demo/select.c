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

void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int min = array[i];
        int minIndex = i;
        
        for ( int j = i; j < size; j++ ) {
            if ( array[j] < min ) {
                min = array[j];
                minIndex = j;
            }
        }
        
        array[minIndex] = array[i];
        array[i] = min;
    }
}


int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = lenScan(in);
    int array[len];

    for ( int i = 0; i < len && (fscanf(in, "%d", &array[i])) == 1; i++ );
    fclose(in);

    selectSort(array, len);
    
    arrayPrint(out, array, len);
    fclose(in);

    return 0;
}
