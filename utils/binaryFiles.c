//
// Created by Kaloyan Petkov on 11.07.24.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct point1 {
    int x;
    int y;
} Point1;

void mulPointBy3(char *filename, unsigned int index) {
    FILE *fp = fopen(filename, "rb+");
    Point1 p;
    fseek(fp, sizeof(Point1) * index, SEEK_SET);
    fread(&p, sizeof(Point1), 1, fp);
    p.x *= 2;
    p.y *= 2;
    fseek(fp, -1 * (int)sizeof(Point1), SEEK_CUR);
    fwrite(&p, sizeof(Point1), 1, fp);
    fclose(fp);
}

void reversePoints(char *filename, unsigned int size) {
    FILE *fp = fopen(filename, "rb+");
    if (!fp) {
        printf("Failed to open file!");
        return;
    }
    for (int i = 0; i < size / 2; i++) {
        fseek(fp, sizeof(Point1) * i, SEEK_SET); // set the pointer to the start of the iterated point
        Point1 temp;
        fread(&temp, sizeof(Point1), 1, fp); // read the iterated point
        Point1 oppositePoint;
        fseek(fp, -1 * ((int)sizeof(Point1) * (i + 1)), SEEK_END); // set the pointer to the start of the opposite point
        fread(&oppositePoint, sizeof(Point1), 1, fp); // read the opposite pointer
        fseek(fp, -1 * ((int)sizeof(Point1) * (i + 1)), SEEK_END); // set the pointer to the start of the opposite point
        fwrite(&temp, sizeof(Point1), 1, fp); // write the temp point on the place of opposite point
        fseek(fp, sizeof(Point1) * i, SEEK_SET); // set the pointer to the start of the iterated point
        fwrite(&oppositePoint, sizeof(Point1), 1, fp); // write the opposite point to the iterated point
    }
}

void addPoint(char *filename, Point1 point) {
    FILE *fp = fopen(filename, "rb+");
    if (!fp) {
        printf("Failed to open file!");
        return;
    }
    fseek(fp, 0, SEEK_END);
    fwrite(&point, sizeof(Point1), 1, fp);
    fclose(fp);
}

void deletePoint(char *filename, unsigned int pointIndex, unsigned int totalPoints) {
    FILE *fp = fopen(filename, "rb+");
    Point1 *pointsArr = malloc(sizeof(Point1) * (totalPoints - 1));
    for (int i = 0, j = -1; i < totalPoints; i++) {
        if (i == pointIndex) {
            fseek(fp, sizeof(Point1), SEEK_CUR);
            continue;
        }
        j++;
        fread(&pointsArr[j], sizeof(Point1), 1, fp);
    }
    fclose(fp);
    fp = fopen(filename, "wb");
    fwrite(pointsArr, sizeof(Point1), totalPoints - 1, fp);
    fclose(fp);
}