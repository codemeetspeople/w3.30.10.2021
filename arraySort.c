#include <stdio.h>

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

int partition(int array[], int array_clean[], int start, int end) {
    int average = (start + end) / 2;
    int elem = array[average];

    // TODO
    // 1. Записать в массив array_clean значения меньшие чем elem
    // 2. Записать в массив array_clean elem и запомнить его индекс
    // 3. Записать в массив array_clean все значения большие чем elem


    return 0;
}

int main() {
    int array[10] = {5,9,7,3,6,1,4,8,2,10};
    int array_clean[10];

    int value = partition(array, array_clean, 0, 9);

    printf("%d\n", value);
    arrayPrint(array_clean, 10);

    // 5
    // 5 3 1 4 2 6 9 7 8 10


    return 0;
}
