#include <stdlib.h>
#include <string.h>

int freqAsValue(int *arr, unsigned int size, int k) {
    int flag = 1;
    int *countArr = calloc(k + 1, sizeof(int));


    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }

    for (int i = 0; i < k; i++) {
        if (countArr[i] != i) flag = 0;
    }
    free(countArr);
    return flag;
}

int findDominantValue_p1(int *arr, unsigned int size) {
    int *countArr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }

    int dominantValAppearances = countArr[0];
    int dominantVal = 0;
    for (int i = 0; i < size; i++) {
        int currValAppearances = countArr[i];
        for (int j = i + 1; j < size; j++) {
            if (currValAppearances > 0 && currValAppearances == countArr[j]) {
                free(countArr);
                return -1;
            }
        }

        if (dominantValAppearances < currValAppearances) {
            dominantValAppearances = currValAppearances;
            dominantVal = i;
        }
    }

    free(countArr);
    return dominantVal;
}

int findDominantValue_p2(int *arr, unsigned int size) {
    int *countArr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }

    for (int i = 0; i < size; i++) {
        if (countArr[i] > size / 2) {
            free(countArr);
            return i;
        }
    }

    free(countArr);
    return -1;
}

int findSpecificValueMaxSum(int *arr, unsigned size) {
    int *countArr = calloc(size + 1, sizeof(int));
    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }

    int maxSum = countArr[1];
    for (int i = 2; i <= size; i++) {
        int currSum = i * countArr[i];
        if (currSum > maxSum) maxSum = currSum;
    }
    free(countArr);
    return maxSum;
}

int findLargestMissingValue(int *arr, unsigned int n) {
    int *countArr = calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        countArr[arr[i]]++;
    }

    for (int i = n; i >= 0; i--) {
        if (countArr[i] == 0) {
            free(countArr);
            return i;
        }
    }

    free(countArr);
    return -1;
}

// Not using counting array here
int areAllLettersIncluded(char *str1, char *str2) {
    for (int i = 0; i < strlen(str1); i++) {
        int flag = 0;
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return flag;
    }
    return 1;
}