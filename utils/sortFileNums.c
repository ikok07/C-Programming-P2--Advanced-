//
// Created by Kaloyan Petkov on 10.07.24.
//

#include <stdio.h>

void sortFileInts(char *filename) {
    FILE *fp = fopen(filename, "r");
    FILE *fpEven = fopen("../even.txt", "w");
    FILE *fpOdd = fopen("../odd.txt", "w");

    int num;
    while ((fscanf(fp, "%d", &num)) != EOF){
        if (num % 2 == 0) fprintf(fpEven, "%d ", num);
        else fprintf(fpOdd, "%d ", num);
    }

    fclose(fp);
    fclose(fpEven);
    fclose(fpOdd);
}
