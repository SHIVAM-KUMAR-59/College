/*
Write a program to remove repeated elements in a given array.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to remove duplicates from the array
void removeDuplicates(int *arr, int *n) {
    int i, j, k;
    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n; j++) {
            if (arr[i] == arr[j]) {
                // Shift elements to the left to remove duplicate
                for (k = j; k < *n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*n)--;  // Reduce array size
                arr = realloc(arr, *n * sizeof(int));  // Reallocate memory
                j--;  // Adjust index after removal
            }
        }
    }
}

// Function to display the array
void displayArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // User input for size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // User input for elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    displayArray(arr, n);

    removeDuplicates(arr, &n);

    printf("Array after removing duplicates:\n");
    displayArray(arr, n);

    // Free allocated memory
    free(arr);

    return 0;
}
