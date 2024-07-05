//
// Created by Kaloyan Petkov on 5.07.24.
//

#include <stdlib.h>

void create1DByRef(int **arr, unsigned int size) {
    // 1.
    //    int *newArr = (int*)calloc(size, sizeof(int));
    //    memcpy(arr, newArr, size * sizeof(int));
    // 2.
    *arr = (int*)calloc(size, sizeof(int));
}
