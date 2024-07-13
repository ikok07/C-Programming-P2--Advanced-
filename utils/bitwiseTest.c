//
// Created by Kaloyan Petkov on 13.07.24.
//

int setBit(int value, int bitPos) {
    int mask = 1;
    for (int i = 0; i < 8; i++) {
        if (i == bitPos) {
            return value | mask;
        }
        mask = mask << 1;
    }
    return -1;
}

int clearBit(int value, int bitPos) {
    int mask = 1;
    for (int i = 0; i < 8; i++) {
        if (i == bitPos) {
            int currBit = (value & mask) == 0 ? 0 : 1;
            if (currBit == 0) return value;
            return value ^ mask;
        }
        mask = mask << 1;
    }
    return -1;
}

int toggleBit(int value, int bitPos) {
    int mask = 1;
    for (int i = 0; i < 8; i++) {
        if (i == bitPos) {
            return value ^ mask;
        }
        mask = mask << 1;
    }
    return -1;
}

int checkBit(unsigned int value, int bitPos) {
    int mask = 1;
    for (int i = 0; i < 8; i++) {
        if (i == bitPos) {
            return (value & mask) == 0 ? 0 : 1;
        }
        mask = mask << 1;
    }

    return -1;
}

int countSetBits(unsigned int value) {
    int mask = 1;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if ((value & mask) != 0) count++;
        mask = mask << 1;
    }
    return count;
}