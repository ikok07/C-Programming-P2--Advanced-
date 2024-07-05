//
// Created by Kaloyan Petkov on 5.07.24.
//

#include <stdlib.h>

void separateArrays(int *sourceArr, int **evenArr, int **oddArr, unsigned int size) {
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (sourceArr[i] % 2 == 0) evenCount++;
        else oddCount++;
    }

    *evenArr = malloc(sizeof(int) * evenCount);
    *oddArr = malloc(sizeof(int) * oddCount);

    int evenIndex = 0;
    int oddIndex = 0;

    for (int i = 0; i < size; i++) {
        if (sourceArr[i] % 2 == 0) {
            (*evenArr)[evenIndex] = sourceArr[i];
            evenIndex++;
        } else {
            (*oddArr)[oddIndex] = sourceArr[i];
            oddIndex++;
        }
    }
}
