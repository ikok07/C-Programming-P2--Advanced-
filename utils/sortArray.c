//
// Created by Kaloyan Petkov on 9.07.24.
//

#include <stdbool.h>

bool isAscending(int num1, int num2) {
    return num1 < num2;
}

bool isDescending(int num1, int num2) {
    return num1 > num2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, unsigned int n, bool (*compFunc)(int,int)) {
    for (int i = 0; i < n; i++) {
        int replaceIntIndex = i;
        int replaceInt = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (!compFunc(replaceInt, arr[j])) {
                replaceInt = arr[j];
                replaceIntIndex = j;
            }
        }
        swap(&arr[i], &arr[replaceIntIndex]);
    }
}
