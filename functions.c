#include <stdio.h>

typedef int (*function_type)(int, int);

typedef struct {
    function_type sum;
    function_type diff;
    function_type mult;
} Math;

int sum(int x, int y) {
    return x + y;
}

int diff(int x, int y) {
    return x - y;
}

int mult(int x, int y) {
    return x * y;
}

int array_handler(function_type f, int array[], int size) {
    int result = array[0];

    for ( int i = 1; i < size; i++ ) {
        result = f(result, array[i]);
    }
    return result;
}

function_type calculate(int condition) {
    switch ( condition ) {
        case 1:
            return sum;
        case 2:
            return diff;
        default:
            return mult;
    }
}

int main() {
    // int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // function_type farray[3] = {sum, diff, mult};
    // Math math = {sum, diff, mult};

    // printf("%d\n", array_handler(sum, array, 10));
    // printf("%d\n", array_handler(mult, array, 10));

    // printf("%d\n", farray[0](5, 10));
    // printf("%d\n", farray[1](5, 10));
    // printf("%d\n", farray[2](5, 10));

    // printf("%d\n", math.sum(5, 10));
    // printf("%d\n", math.diff(5, 10));
    // printf("%d\n", math.mult(5, 10));

    int action;
    int x, y;
    function_type operation;

    for ( ; ; ) {
        printf("type operation to perform: 1-sum, 2-diff, else-mult, -1-exit:\n");
        scanf("%d", &action);
        if ( action == -1 ) {
            printf("Bye-bye1\n");
            break;
        }
        printf("type two values:\n");
        scanf("%d %d", &x, &y);
        printf("result: %d\n\n", calculate(action)(x, y));
    }

    return 0;
}
