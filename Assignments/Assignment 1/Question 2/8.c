/*
Write a program to rotate the circular elements based onthe
number of shifts. If it is two shift then all the elements inthe circlewill be shifted two step forward. Write the programwithout takingany extra array.
*/

#include <stdio.h>

void rotateCircle(int matrix[4][4], int size, int shifts) {
    int layers = size / 2;
    shifts %= (4 * (size - 1));

    for (int layer = 0; layer < layers; layer++) {
        int top = layer, left = layer, bottom = size - 1 - layer, right = size - 1 - layer;

        for (int s = 0; s < shifts; s++) {
            int temp = matrix[top][left];
            for (int i = left; i < right; i++) matrix[top][i] = matrix[top][i + 1];
            for (int i = top; i < bottom; i++) matrix[i][right] = matrix[i + 1][right];
            for (int i = right; i > left; i--) matrix[bottom][i] = matrix[bottom][i - 1];
            for (int i = bottom; i > top; i--) matrix[i][left] = matrix[i - 1][left];
            matrix[top + 1][left] = temp;
        }
    }
}

void printMatrix(int matrix[4][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) printf("%2d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int matrix[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    int size = 4, shifts = 2;

    printf("Original Matrix:\n");
    printMatrix(matrix, size);

    rotateCircle(matrix, size, shifts);

    printf("\nMatrix after %d shifts:\n", shifts);
    printMatrix(matrix, size);

    return 0;
}
