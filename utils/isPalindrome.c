//
// Created by Kaloyan Petkov on 2.07.24.
//

int isPalindrome(int *arr, int size, int i) {
    if (i >= size / 2 - 1) return arr[i] == arr[i + 1];
    if (!isPalindrome(arr, size, i + 1)) return 0;
    return arr[i] == arr[size - 1 - i];
}
