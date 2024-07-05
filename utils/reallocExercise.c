//
// Created by Kaloyan Petkov on 3.07.24.
//

#include <stdlib.h>
#include <stdio.h>

void reallocExercise() {
    int totalGrades;
    int *grades;
    printf("Enter total grades: ");
    scanf("%d", &totalGrades);

    grades = (int*)malloc(sizeof(int) * totalGrades);
    if (grades == NULL) {
        printf("Could not allocate memory!");
        exit(1);
    }

    for (int i = 0; i < totalGrades; i++) {
        printf("Enter grade: ");
        scanf("%d", &grades[i]);
    }

//    displayArray(grades, totalGrades);
    totalGrades++;

    int *temp = (int*)realloc(grades, totalGrades);
    if (temp == NULL) {
        printf("Could not reallocate memory!");
        exit(1);
    }
    grades = temp;

    printf("Enter grade: ");
    scanf("%d", &grades[totalGrades - 1]);

//    displayArray(grades, totalGrades);

    totalGrades--;
    temp = (int*) realloc(grades, totalGrades - 1);
    if (temp == NULL) {
        printf("Could not reallocate memory!");
        exit(1);
    }
    grades = temp;

//    displayArray(grades, totalGrades);

    free(grades);
}
