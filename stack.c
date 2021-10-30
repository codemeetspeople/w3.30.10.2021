#include <stdio.h>

int main() {
    char str1[10] = "some info";
    char str2[10];

    printf("%p\n", str1);
    printf("%p\n", str2);

    scanf("%s", str2);

    printf("%s\n", str1);

    return 0;
}
