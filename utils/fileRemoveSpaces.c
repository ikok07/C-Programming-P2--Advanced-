//
// Created by Kaloyan Petkov on 10.07.24.
//

#include <stdio.h>

void removeSpaceChars(char *filename, char *outputFilename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file for reading!");
        return;
    }
    FILE *fpOut = fopen(outputFilename, "w");
    if (!fpOut) {
        printf("Failed to open output file for writing!");
        return;
    }

    int currChar;

    while ((currChar = fgetc(fp)) != EOF) {
        if (currChar != ' ') fputc(currChar, fpOut);
    }

    fclose(fp);
    fclose(fpOut);
}