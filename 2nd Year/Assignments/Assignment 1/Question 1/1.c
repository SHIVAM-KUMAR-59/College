// 1. Write a program to divide a one dimensional array(having 40 elements) to 5 two dimensional array of 2X4 each. Pass the 2nd and 4th two dimensional array to a function which will swap these two 2-D array in original one dimensional array.

#include <stdio.h>
#include <stdlib.h>

// Function to divide the array
void divideArray(int arr[], int arr1[][2][4], int totalElements) {
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                arr1[i][j][k] = arr[index++];
            }
        }
    }
}

// Function to swap two two-dimensional arrays
void swapArrays(int arr1[][2][4], int arrIndex1, int arrIndex2) {
    int temp;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 4; k++) {
            temp = arr1[arrIndex1][j][k];
            arr1[arrIndex1][j][k] = arr1[arrIndex2][j][k];
            arr1[arrIndex2][j][k] = temp;
        }
    }
}

// Function to print a one-dimensional array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % (2 * 4) == 0) {
            printf("\n");
        }
    }
}


int main() {
    int arr[40];
    int arr1[5][2][4];

    for (int i = 0; i < 40; i++) {
        arr[i] = rand()%100;
    }
    printf("Original array:\n");
    printArray(arr, 40);

    // Divide the one-dimensional array into two-dimensional arrays
    divideArray(arr, arr1, 40);

    // Swap the 2nd and 4th two-dimensional arrays
    swapArrays(arr1, 2, 4);

    // Combine back into the one-dimensional array
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                arr[index++] = arr1[i][j][k];
            }
        }
    }

    // Print the modified one-dimensional array
    printf("Modified One-Dimensional Array:\n");
    printArray(arr, 40);

    return 0;
}

