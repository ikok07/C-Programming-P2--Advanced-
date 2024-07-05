//
// Created by Kaloyan Petkov on 2.07.24.
//

#include <stdio.h>


int getBinary(int n) {
    if (n >= 2) {
        getBinary(n / 2);
        printf("%d", n % 2);
    } else printf("%d", n % 2);
}