//
// Created by Kaloyan Petkov on 6.07.24.
//

#include <stdlib.h>
#include <string.h>

void arrInsert(int **sourceArr, int *value, unsigned int index, int sourceCount, int typeSize) {
    int sourceSize = typeSize * sourceCount;
    int valueSize = typeSize;
    int indexSize = index * typeSize;
    void *newArr = malloc(sourceSize + valueSize);
    if (!newArr) return;
    memcpy(newArr, *sourceArr, indexSize);
    memcpy((char *)newArr + indexSize, value, valueSize);
    memcpy((char *)newArr + indexSize + valueSize, (char *)*sourceArr + indexSize, sourceSize - indexSize);
    *sourceArr = newArr;
}

void arrRemoveAt(int **sourceArr, unsigned int index, int sourceCount, int typeSize) {
    int sourceSize = sourceCount * typeSize;
    int valueSize = typeSize;
    int indexSize = index * typeSize;
    void *newArr = malloc(sourceSize - valueSize);
    if (!newArr) return;
    memcpy(newArr, *sourceArr, indexSize);
    memcpy((char *)newArr + indexSize, (char *)*sourceArr + indexSize + valueSize, sourceSize - indexSize - valueSize);
    *sourceArr = newArr;
}