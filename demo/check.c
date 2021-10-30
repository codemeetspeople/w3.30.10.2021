#include <stdio.h>

int lenScan(FILE *in) {
    int length;
    
    fscanf(in, "%d", &length);
    
    return length;
}

int main() {
    FILE *in = fopen("task.out", "r");
    int check;
    int flag = 0;
    int tmp;

    fscanf(in, "%d", &check);

    for ( ; fscanf(in, "%d", &tmp) == 1; ) {         
        if ( check > tmp ) {
            flag = 1;
        }
        check = tmp;
    }

    if ( flag ) {
        printf("NOT SORTED\n");
    } else {
        printf("SORTED\n");
    }
    
    return 0;
}
