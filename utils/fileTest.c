//
// Created by Kaloyan Petkov on 10.07.24.
//

#include <stdio.h>
#include <stdlib.h>

void createAndWriteFile(char *filename, char *str) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file for write");
        exit(1);
    }
    fprintf(fp, "%s", str);
    fclose(fp);
}

void readFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file for read");
        exit(1);
    }

    int currChar;
    while ((currChar = fgetc(fp)) != EOF) {
        printf("%c", currChar);
    }

    fclose(fp);
}

void appendToFile(char *filename, char *str) {
    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Failed to open file for append");
        exit(1);
    }

    fprintf(fp, "%s", str);
    fclose(fp);
}

void modifyLineInFile(char *filename, unsigned int targetLine, char *str) {
    FILE *fp = fopen(filename, "r");
    FILE *fpNew = fopen("../temp.txt", "w");
    if (!fp) {
        printf("Failed to open file for read");
        exit(1);
    }

    int currLine = 1;
    int currChar;
    while ((currChar = fgetc(fp)) != EOF) {
        if (currChar == '\n') currLine++;
        if (currLine == targetLine) {
            fprintf(fpNew, "\n%s\n", str);
            while (fgetc(fp) != '\n') // move the file pointer to the end of the line
                continue;
        }
        fputc(currChar, fpNew);
    }

    if (currLine != targetLine) fprintf(fpNew, "\n%s\n", str);

    fclose(fp);
    fclose(fpNew);

    if (remove(filename) != 0) {
        printf("Failed to modify file!");
        return;
    }

    rename("../temp.txt", filename);
}
