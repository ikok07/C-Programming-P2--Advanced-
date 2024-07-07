//
// Created by Kaloyan Petkov on 7.07.24.
//

#include <stdlib.h>

int* *lowerTriangularMatrix(unsigned int maxW, int **colsArr) {
    int* *arr = malloc(maxW * sizeof(int*));
    *colsArr = malloc(sizeof(int) * maxW);
    for (int i = 0; i < maxW; i++) {
        arr[i] = calloc(i + 1, sizeof(int));
        (*colsArr)[i] = i + 1;
    }
    return arr;
}

int* *upperTriangularMatrix(unsigned int maxW, int **colsArr) {
    int* *arr = malloc(maxW * sizeof(int*));
    *colsArr = malloc(sizeof(int) * maxW);
    for (int i = 0; i < maxW; i++) {
        arr[i] = calloc(maxW - i, sizeof(int));
        (*colsArr)[i] = maxW - i;
    }
    return arr;
}
