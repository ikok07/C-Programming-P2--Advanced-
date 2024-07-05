#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5

int *generateArr(int size) {
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        printf("Enter value #%d\n", i + 1);
        scanf("%d", &arr[i]);
    }
    return arr;
}

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Value #%d: %d\n", i + 1, arr[i]);
    }
    printf("\n");
}

int *generateArray(int size) {
    int *arr = (int*)malloc(sizeof(int) * size);
    if (!arr) {
        printf("Could not allocate memory!");
        exit(1);
    }
    return arr;
}



int main() {
    int *ptr;
    int size = 3;

    create1DByRef(&ptr, size);
    displayArray(ptr, size);
    return 0;
}
