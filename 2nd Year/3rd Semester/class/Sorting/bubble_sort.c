
/*
Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until no swaps are needed, which means the list is sorted.

Best-case time complexity: O(n) when the array is already sorted.
Worst-case time complexity: O(n^2) when the array is sorted in reverse order.
Average-case time complexity: O(n^2) when the array is randomly ordered.
Space complexity: O(1) as it only uses a constant amount of space.
*/

#include <stdio.h>

// Function to perform bubble sort on the array
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;  // Flag to track if any swaps occur in a pass
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // Set flag to indicate a swap occurred
            }
        }
        // If no swaps occurred, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the elements of an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  // Array to be sorted
    int n = 10;  // Size of the array

    // Perform bubble sort on the array
    bubble_sort(arr, n);

    // Print the sorted array
    printf("Bubble Sorted array: ");
    print_array(arr, n);

    return 0;
}
