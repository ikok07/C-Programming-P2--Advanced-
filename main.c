#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Value #%d: %d\n", i + 1, arr[i]);
    }
    printf("\n");
}

int *generateArray(int size) {
    int *arr = (int *) malloc(sizeof(int) * size);
    if (!arr) {
        printf("Could not allocate memory!");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        printf("Enter array value: ");
        scanf("%d", &arr[i]);
    }
    return arr;
}

int **generate2DArray() {
    int rowsCount;
    int columnsCount;
    int* *arr;
    printf("Enter number of rows: ");
    scanf("%d", &rowsCount);

    arr = (int**)malloc(sizeof(int*) * rowsCount);
    for (int i = 0; i < rowsCount; i++) {
        printf("Enter number of columns for row #%d: ", i + 1);
        scanf("%d", &columnsCount);
        arr[i] = (int*)calloc(columnsCount, sizeof(int));
    }
    return arr;
}

void display2DArray(int* *arr, unsigned int rowsCount, int *columnCounts) {
    for (int i = 0; i < rowsCount; i++) {
        printf("Row #%d:\n", i + 1);
        displayArray(arr[i], columnCounts[i]);
    }
}

void free2DArray(int* *arr, unsigned int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {

    int* *arr = generate2DArray();
    int cols[3] = {1, 2, 3};
    display2DArray(arr, 3, cols);
    free2DArray(arr, 3);
    return 0;
}
