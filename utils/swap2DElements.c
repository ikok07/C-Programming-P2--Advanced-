//
// Created by Kaloyan Petkov on 7.07.24.
//

void swapRows(void* *arr1, int row1, int row2) {
    void* temp = arr1[row1];
    arr1[row1] = arr1[row2];
    arr1[row2] = temp;
}

void swapColumns(int* *arr1, int rowsCount, int col1, int col2) {
    for (int i = 0; i < rowsCount; i++) {
        int temp = arr1[i][col1];
        arr1[i][col1] = arr1[i][col2];
        arr1[i][col2] = temp;
    }
}
