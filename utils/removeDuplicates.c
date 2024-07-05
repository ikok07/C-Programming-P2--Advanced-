//
// Created by Kaloyan Petkov on 5.07.24.
//

#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int **arr, unsigned int size) {
    int *newArr = malloc(sizeof(int));
    if (!newArr) {
        printf("Could not allocate memory!\n");
        return -1;
    }
    int arrSize = 1;
    newArr[0] = *arr[0];
    for (int i = 1; i < size; i++) {
        if ((*arr)[i] == (*arr)[i - 1]) continue;
        arrSize++;
        newArr = realloc(newArr, arrSize);
        newArr[arrSize - 1] = (*arr)[i];
    }

    *arr = newArr;
    return arrSize;
}