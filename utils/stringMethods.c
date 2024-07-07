//
// Created by Kaloyan Petkov on 7.07.24.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strLength(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *strConcat(char *destString, char *sourceString) {
    int destSize = strLength(destString);
    int sourceSize = strLength(sourceString);
    char *newStr = (char*)malloc(destSize + sourceSize);
    if (!newStr) {
        printf("Could not allocate memory!");
        exit(1);
    }

    memcpy(newStr, destString, destSize);
    memcpy(newStr + destSize, sourceString, sourceSize + 1);
    return newStr;
}

void strCopy(char **destStr, char *srcString) {
    int srcLength = strLength(srcString);
    *destStr = malloc(srcLength);
    for (int i = 0; i < srcLength; i++) {
        (*destStr)[i] = srcString[i];
    }
}

int strCompare(char *str1, char *str2) {
    int flag = 0;
    int str1Length = strLength(str1);
    int str2Length = strLength(str2);
    if (str1Length > str2Length) flag = -1;
    else if (str2Length > str1Length) flag = 1;

    if (flag == 0) {
        for (int i = 0; i < str1Length; i++) {
            if (str1[i] != str2[i]) {
                flag = str1[i] > str2[i] ? -1 : 1;
                break;
            }
        }
    }

    return flag;
}
