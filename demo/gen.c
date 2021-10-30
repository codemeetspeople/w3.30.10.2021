#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *out = fopen("task.in", "w");
    int len, min, max, first;
    int last;

    srand (time(NULL));

    printf("Lenght:\n");
    scanf("%d", &len);

    last = len - 1;

    printf("Range (min/max):\n");
    scanf("%d %d", &min, &max);

    printf("Type a lenght as a first string of the file? (1/0):\n");
    scanf("%d", &first);

    if ( first ) {
        fprintf(out, "%d\n", len);
    }

    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", rand() % (min + max));
    }
    fprintf(out, "%d\n", rand() % (min + max));

    return 0;
}
