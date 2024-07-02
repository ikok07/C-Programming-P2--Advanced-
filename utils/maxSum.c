//
// Created by Kaloyan Petkov on 2.07.24.
//

int maxSum(int *arr, int size) {
    if (size == 2) return arr[0] + arr[1];
    int maxSumVal = maxSum(arr + 1, size - 1);
    if (maxSumVal > arr[0] + arr[1]) return maxSumVal;
    else return arr[0] + arr[1];
}
