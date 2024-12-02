// Create 2 D array and sort in a way that the odd numbers appear before the even numbers

#include <stdio.h>
#include<stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the 2D array
void sortArray(int arr[4][3], int row, int col) {
    int i, j, k;
    int n = row * col;

    int flatArr[n];
    int index = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            flatArr[index++] = arr[i][j];
        }
    }

    // Sort the 1D array
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (flatArr[i] % 2 == 0 && flatArr[j] % 2 != 0) {
                swap(&flatArr[i], &flatArr[j]);
            }
        }
    }

    // Convert the 1D array back to a 2D array
    index = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            arr[i][j] = flatArr[index++];
        }
    }
}

// Function to print the 2D array
void printArray(int arr[4][3], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row = 4;
    int col = 3;
    int arr[4][3];
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 3; j++){
            arr[i][j] = rand()%100;
    }
    }
    printf("\nOriginal array:\n");
    printArray(arr, row, col);

    sortArray(arr, row, col);

    printf("\nSorted array:\n");
    printArray(arr, row, col);

    return 0;
}