#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Value #%d: %d\n", i + 1, arr[i]);
    }
    printf("\n");
}

int *generateArray(int size) {
    int *arr = (int *) malloc(sizeof(int) * size);
    if (!arr) {
        printf("Could not allocate memory!");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        printf("Enter array value: ");
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {


    return 0;
}
