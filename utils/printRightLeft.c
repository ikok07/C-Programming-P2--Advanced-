//
// Created by Kaloyan Petkov on 2.07.24.
//

#include <stdio.h>

void printLtoR(int *arr, int size) {
    if (size == 1) {
        printf("%d", arr[0]);
        return;
    }
    printf("%d\n", arr[0]);
    printLtoR(arr + 1, size - 1);
}

void printRtoL(int *arr, int size) {
    if (size > 0) {
        printRtoL(arr + 1, size - 1);
        printf("%d", arr[0]);
    }
}
