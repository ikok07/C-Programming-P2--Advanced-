#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter value #%d\n", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Value #%d: %d\n", i + 1, arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE] = {9,2,4,5,3};
    printRtoL(arr, SIZE);
    return 0;
}
