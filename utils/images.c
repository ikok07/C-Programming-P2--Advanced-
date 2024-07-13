//
// Created by Kaloyan Petkov on 13.07.24.
//

#include <stdio.h>

typedef struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGBPixel;

int testImages() {

    RGBPixel image[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            image[i][j].red = (unsigned char)((255.0 / 10.0) * j);
            image[i][j].green = 128;
            image[i][j].blue = (unsigned char)((255.0 / 10.0) * j);
        }
    }

    FILE *fp = fopen("../image-rgb.bin", "wb");
    fwrite(image, sizeof(RGBPixel), 100, fp);
    fclose(fp);
    return 0;
}