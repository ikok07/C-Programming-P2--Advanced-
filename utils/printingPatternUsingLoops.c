//
// Created by Kok_PC on 14.7.2024 г..
//

#include <stdio.h>

int getColumns(int n) {
    int count = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        count++;
    }
    return count;
}

void printPattern() {
    const int n = 5;
    const int colsCount = getColumns(n);
    const int betweenLinesCount = colsCount / 2 - 1;
    int currLine = 0;

    // First line
    for (int i = 0; i < colsCount; i++) {
        printf("%d ", n);
    }
    printf("\n");
    currLine++;

    // Between Lines #1
    for (int i = 0; i < betweenLinesCount; i++) {
        int minValForLine = n - currLine;
        int unavailableColsCount = 3;
        printf("%d ", n);
        for (int j = n - 1; j > minValForLine; j--) {
            printf("%d ", j);
            unavailableColsCount += 2;
        }

        int leftCols = colsCount - unavailableColsCount;
        for (int k = 0; k < leftCols; k++) {
            printf("%d ", minValForLine);
        }

        for (int j = minValForLine; j < n; j++) {
            printf("%d ", j);
        }
        printf("%d ", n);
        printf("\n");
        currLine++;
    }

    // Middle line
    int j = 0, k = 0;
    while (k < colsCount) {
        if (k < colsCount / 2) {
            printf("%d ", n - j);
            j++;
        }

        if (k >= colsCount / 2) {
            printf("%d ", n - j);
            j--;
        }

        k++;
    }
    printf("\n");
    currLine++;

    // Between Lines #2
    for (int i = 0; i < betweenLinesCount; i++) {
        int minValForLine = 2 + i;
        int unavailableColsCount = 3;
        printf("%d ", n);
        for (int j = n - 1; j > minValForLine; j--) {
            printf("%d ", j);
            unavailableColsCount += 2;
        }

        int leftCols = colsCount - unavailableColsCount;
        for (int k = 0; k < leftCols; k++) {
            printf("%d ", minValForLine);
        }

        for (int j = minValForLine; j < n; j++) {
            printf("%d ", j);
        }
        printf("%d ", n);
        printf("\n");
        currLine++;
    }

    // Last Line
    for (int i = 0; i < colsCount; i++) {
        printf("%d ", n);
    }
}