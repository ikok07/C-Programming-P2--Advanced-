//
// Created by Kaloyan Petkov on 12.07.24.
//

int rotateRightShift(int value) {
    int mask = 1;
    int rightMostDigit = value & mask;
    value = value >> 1;
    if (rightMostDigit == 0) return value; // if machine fills empty bits with 0s
    mask = mask << 7;
    value = value | mask;
    return value;
}

int rotateLeftShift(int value) {
    int mask = 1 << 7;
    int leftMostDigit = value & mask;
    value = (value << 1) & 0xFF;
    if (leftMostDigit == 0) return value;
    mask = 1;
    value = value | mask;
    return value;
}

void swapBitwise_p1(int *a, int *b) {
    int temp = *a;
    // change value of b into a
    int maskA = 1;
    for (int i = 0; i < 8; i++) {
        int maskB = 1 << i;
        int currBitA = (*a & maskA) == 0 ? 0 : 1;
        int currBitB = (*b & maskB) == 0 ? 0 : 1;
        if (currBitA == currBitB) {
            maskA = maskA << 1;
            continue;
        }
        if (currBitB == 0) *a = *a ^ maskA;
        else *a = *a | maskA;
        maskA = maskA << 1;
    }

    // change value of temp(a) into b
    int maskC = 1;
    for (int i = 0; i < 8; i++) {
        int maskD = 1 << i;
        int currBitTemp = (temp & maskC) == 0 ? 0 : 1;
        int currBitB = (*b & maskD) == 0 ? 0 : 1;
        if (currBitTemp == currBitB) {
            maskC = maskC << 1;
            continue;
        }
        if (currBitTemp == 0) *b = *b ^ maskC;
        else *b = *b | maskC;
        maskC = maskC << 1;
    }
}

void swapBitwise_p2(int *a, int *b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *b ^ *a;
}
