//
// Created by Kaloyan Petkov on 3.07.24.
//

void swapArr(int **arr1, int **arr2) {
    int *temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}
