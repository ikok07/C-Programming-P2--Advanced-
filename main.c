#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *generateArray(unsigned int n) {
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter #%d array value: ", i);
        scanf("%d", &arr[i]);
    }
    return arr;
}

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Value #%d: %d\n", i + 1, arr[i]);
    }
    printf("\n");
}



int main() {

    return 0;
}

//while ((currLineLength = getline(&line, &lineCap, fp)) != EOF) {
//currLine++;
//if (currLine != lineNumber) {
//
//}
//
//}