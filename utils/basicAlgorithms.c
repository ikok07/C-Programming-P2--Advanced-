//
// Created by Kaloyan Petkov on 13.07.24.
//

#include <stdlib.h>
#include <string.h>

int *mergeArrs(int *arr1, size_t arr1Size, int *arr2, size_t arr2Size) {
    int *newArr = malloc(sizeof(int) * (arr1Size + arr2Size));
    int i = 0, j = 0, k = 0;
    while (i < arr1Size) {
        if (arr1[i] < arr2[j] || j == arr2Size) newArr[k++] = arr1[i++];
        else newArr[k++] = arr2[j++];
    }
    while (j < arr2Size) newArr[k++] = arr2[j++];
    return newArr;
}

void mergeArrInPlace(int *arr, size_t arrSize) {
    int *newArr = malloc(sizeof(int) * arrSize);
    int separatorIndex = -1;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > arr[i + 1]) {
            separatorIndex = i + 1;
            break;
        }
    }

    int j = 0, k = separatorIndex, m = 0;
    while (j < separatorIndex) {
        if (arr[j] < arr[k] || k == arrSize) newArr[m++] = arr[j++];
        else newArr[m++] = arr[k++];
    }

    while (k < arrSize) newArr[m++] = arr[k++];
    memcpy(arr, newArr, sizeof(int) * arrSize);
    free(newArr);
}
