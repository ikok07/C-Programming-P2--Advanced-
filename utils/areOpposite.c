//
// Created by Kaloyan Petkov on 2.07.24.
//

int areOpposite(int *arr, int size) {
    if (size == 2) return (arr[0] > 0 && arr[1] < 0) || (arr[0] < 0 && arr[1] > 0);
    if (!areOpposite(arr + 1, size - 1)) return 0;
    return (arr[0] > 0 && arr[1] < 0) || (arr[0] < 0 && arr[1] > 0);
}
