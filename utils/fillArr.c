//
// Created by Kaloyan Petkov on 5.07.24.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *fillArr() {
    int *arr = malloc(sizeof(int));
    int value = 0;
    int arrSize = 0;
    while (value >= 0) {
        printf("Enter array value: ");
        scanf("%d", &value);
        if (value == -1) break;
        arrSize++;
        int *newArr = realloc(arr, arrSize * sizeof(int));
        if (!newArr) {
            printf("Failed to allocate memory!");
            return NULL;
        }
        newArr[arrSize - 1] = value;
        memcpy(arr, newArr, sizeof(int) * arrSize);
    }
    return arr;
}
