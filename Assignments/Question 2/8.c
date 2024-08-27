/*
Write a program to rotate the circular elements based onthe
number of shifts. If it is two shift then all the elements inthe circlewill be shifted two step forward. Write the programwithout takingany extra array.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to rotate the circular elements in a matrix
void rotateCircle(int matrix[4][4], int size, int shifts) {
    int layers = size / 2; // Number of layers (circles)
    shifts = shifts % (4 * (size - 1)); // Reduce shifts to within the layer's element count

    for (int layer = 0; layer < layers; layer++) {
        int top = layer, left = layer;
        int bottom = size - 1 - layer, right = size - 1 - layer;

        // Perform the rotation `shifts` times
        for (int s = 0; s < shifts; s++) {
            int temp = matrix[top][left]; // Store the top-left element

            // Move left column up
            for (int i = left; i < right; i++) {
                matrix[top][i] = matrix[top][i + 1];
            }
            // Move bottom row left
            for (int i = top; i < bottom; i++) {
                matrix[i][right] = matrix[i + 1][right];
            }
            // Move right column down
            for (int i = right; i > left; i--) {
                matrix[bottom][i] = matrix[bottom][i - 1];
            }
            // Move top row right
            for (int i = bottom; i > top; i--) {
                matrix[i][left] = matrix[i - 1][left];
            }

            matrix[top + 1][left] = temp; // Place the stored element in its new position
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[4][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define a 4x4 matrix
    int matrix[4][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    int size = 4;
    int shifts = 2; // Number of shifts to rotate

    printf("Original Matrix:\n");
    printMatrix(matrix, size);

    // Rotate the matrix elements circularly
    rotateCircle(matrix, size, shifts);

    printf("\nMatrix after %d shifts:\n", shifts);
    printMatrix(matrix, size);

    return 0;
}
