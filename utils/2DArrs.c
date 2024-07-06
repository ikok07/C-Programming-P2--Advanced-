//
// Created by Kaloyan Petkov on 6.07.24.
//

#include <stdio.h>
#include <stdlib.h>

int **generate2DArr() {
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

void display2DArr(int* *arr, unsigned int rowsCount, int *columnCounts) {
    for (int i = 0; i < rowsCount; i++) {
        printf("Row #%d:\n", i + 1);
//        displayArray(arr[i], columnCounts[i]); // NOT IN THIS FILE
    }
}

void free2DArr(int* *arr, unsigned int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}
