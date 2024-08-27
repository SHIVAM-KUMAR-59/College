#include <stdio.h>
#include<stdlib.h>

// Function to right shift and rotate a subarray
void rightShiftRotate(int arr[], int left, int right, int shift) {
    int rangeSize = right - left + 1;
    shift %= rangeSize; // Handle cases where shift >= rangeSize

    for (int i = 0; i < shift; i++) {
        // Store the last element of the range
        int last = arr[right];

        // Shift elements to the right by 1
        for (int j = right; j > left; j--) {
            arr[j] = arr[j - 1];
        }

        // Place the last element at the beginning of the range
        arr[left] = last;
    }
}

// Function to left shift and rotate a subarray
void leftShiftRotate(int arr[], int left, int right, int shift) {
    int rangeSize = right - left + 1;
    shift %= rangeSize; // Handle cases where shift >= rangeSize

    for (int i = 0; i < shift; i++) {
        // Store the first element of the range
        int first = arr[left];

        // Shift elements to the left by 1
        for (int j = left; j < right; j++) {
            arr[j] = arr[j + 1];
        }

        // Place the first element at the end of the range
        arr[right] = first;
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, left, right, shift, choice;

    // User input for size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];


    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printf("Original array:\n");
    displayArray(arr, n);


    // User input for the range and shift value
    printf("Enter the left and right indices (0-based) for the range: ");
    scanf("%d %d", &left, &right);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // User choice for rotation direction
    printf("Choose rotation direction:\n1. Right\n2. Left\n");
    scanf("%d", &choice);

    if (choice == 1) {
        // Right shift and rotate
        printf("Array after right shift and rotate:\n");
        rightShiftRotate(arr, left, right, shift);
    } else if (choice == 2) {
        // Left shift and rotate
        printf("Array after left shift and rotate:\n");
        leftShiftRotate(arr, left, right, shift);
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    // Display the resulting array
    displayArray(arr, n);

    return 0;
}
