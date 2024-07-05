//
// Created by Kaloyan Petkov on 5.07.24.
//

#include <stdlib.h>
#include <string.h>

void *myRealloc(void *addr, unsigned int oldSize, unsigned int newSize) {
    void *newAddr = malloc(newSize);
    if (!newAddr) return NULL;
    unsigned int smallSize = oldSize < newSize ? oldSize : newSize;
    memcpy(newAddr, addr, smallSize);
    free(addr);
    return newAddr;
}
