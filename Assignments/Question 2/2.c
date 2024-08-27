
/*
Write a program to reverse the even index position and oddindexposition for even element array and odd element array.
*/
#include <stdio.h>
#include <stdlib.h>

// Function to reverse elements at even indices for even-sized arrays
void reverseEvenIndices(int* arr, int size) {
    int start = 0;
    int end = (size % 2 == 0) ? size - 2 : size - 1;
    
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move indices
        start += 2;
        end -= 2;
    }
}

// Function to reverse elements at odd indices for odd-sized arrays
void reverseOddIndices(int* arr, int size) {
    int start = 1;
    int end = (size % 2 == 1) ? size - 2 : size - 1;

    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move indices
        start += 2;
        end -= 2;
    }
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse elements based on array size
    if (size % 2 == 0) {
        reverseEvenIndices(arr, size);
    } else {
        reverseOddIndices(arr, size);
    }

    // Print the modified array
    printf("Modified array:\n");
    printArray(arr, size);

    // Free allocated memory
    free(arr);

    return 0;
}
