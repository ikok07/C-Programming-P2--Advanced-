#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapInts(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapIntsNoThird1(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapIntsNoThird2(int *a, int *b) {
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

void genericSwap(void *a, void *b, unsigned int size) {
    int *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int swapFuncs() {
    int a = 10;
    int b = 20;


    swapInts(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    swapIntsNoThird1(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    swapIntsNoThird2(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    genericSwap(&a, &b, sizeof(int));
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}
