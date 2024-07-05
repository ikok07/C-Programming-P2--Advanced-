//
// Created by Kaloyan Petkov on 2.07.24.
//

float arrAvg(int *arr, int size) {
    if (size == 1) return arr[0];
    float sumSoFar = arrAvg(arr + 1, size - 1) * (float)(size - 1);
    return (sumSoFar + (float)arr[0]) / (float)size;
}
