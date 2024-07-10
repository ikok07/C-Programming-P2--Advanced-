//
// Created by Kaloyan Petkov on 10.07.24.
//

#include <stdio.h>

int filecomp(char *fn1, char *fn2) {
    FILE *fp1 = fopen(fn1, "r");
    FILE *fp2 = fopen(fn2, "r");

    int flag = 1;
    int currChar;
    while ((currChar = fgetc(fp1)) != EOF) {
        int currChar2;
        if ((currChar2 = fgetc(fp2)) == EOF) {
            flag = 0;
            break;
        }
        if (currChar != currChar2) {
            flag = 0;
            break;
        }
    }
    if (fgetc(fp2) != EOF) flag = 0;
    fclose(fp1);
    fclose(fp2);

    return flag;
}
