//
// Created by Kaloyan Petkov on 5.07.24.
//

#include <stdio.h>
#include <stdlib.h>

void displayArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Value #%d: %d\n", i + 1, arr[i]);
    }
    printf("\n");
}

int *createArray(unsigned int size) {
    return malloc(sizeof(int) * size);
}

void initArray(int **arr, unsigned int size) {
    int *newArr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        newArr[i] = i;
    }
    *arr = newArr;
}

unsigned int doubleArrSize(int **arr, unsigned int size) {
    int *newArr = realloc(*arr, sizeof(int) * size * 2);
    if (!newArr) {
        printf("Could not allocate memory!");
        return -1;
    }
    for (int i = 0; i < size; i++) {
        newArr[size + i] = 0;
    }
    *arr = newArr;
    return size * 2;
}

void freeMemory(void *ptr) {
    free(ptr);
}

int test() {
    int *arr1 = createArray(5);
    displayArr(arr1, 5);

    int *arr2;
    initArray(&arr2, 3);
    displayArr(arr2, 3);

    unsigned int newSize = doubleArrSize(&arr2, 3);
    displayArr(arr2, newSize);

    freeMemory(arr1);
    return 0;
}
