#include <stdio.h>
#include <stdlib.h>

int intScan(FILE *in) {
    int x;
    
    fscanf(in, "%d", &x);
    return x;
}

void merge(int array[], int lo, int mid, int hi) {
    int sizeTemp = hi - lo;
    int tempArray[sizeTemp];
    int index1 = lo;
    int index2 = mid;
    int indexTemp = 0;
    
    for ( ; index1 < mid && index2 < hi; indexTemp++ ) {
        if ( array[index2] < array[index1] ) {
            tempArray[indexTemp] = array[index2];
            index2 += 1;
        } else {
            tempArray[indexTemp] = array[index1];
            index1 += 1;
        }
    }
    for ( ; index1 < mid; indexTemp++, index1++ ) {
        tempArray[indexTemp] = array[index1];
    }
    
    for ( ; index2 < hi; indexTemp++, index2++ ) {
        tempArray[indexTemp] = array[index2];
    }
    
    for ( int i = lo, j = 0; i < hi; i++, j++ ) {
        array[i] = tempArray[j];
    }
}

int iterationQuantity(int n) {
    int res = 0;
    
    for ( int i = 1; i < n; i *= 2 ) {
        res += 1;
    }
    return res;
}

void mergeSort(int array[], int len) {
    int quantity = iterationQuantity(len);
    int step = 1;
    
    for ( int i = 0; i < quantity; i++ ) {
        int lo = 0;
        int mid = lo + step;
        int hi = mid + step;
        int limit = len + step;
        
        for ( ; hi < limit; ) {
            int currentHi;
            
            currentHi = hi;
            if ( currentHi > len ) {
                currentHi = len;
            }
            merge(array, lo, mid, currentHi);
            lo = hi;
            mid = lo + step;
            hi = mid + step;
        }
        step *= 2;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = intScan(in);
    int *array = malloc(len*sizeof(int));
    
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
    fclose(in);
    
    mergeSort(array, len);
    
    len -= 1;
    for ( int i = 0; i < len; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[len]);
    fclose(out);
    free(array);
    
    return 0;
}
