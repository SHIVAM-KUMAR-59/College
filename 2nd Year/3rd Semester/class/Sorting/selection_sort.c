
/*
Selection Sort divides the array into a sorted and unsorted region. It repeatedly finds the minimum element from the unsorted region and moves it to the end of the sorted region.

Best-case time complexity: O(n^2) when the array is already sorted.
Worst-case time complexity: O(n^2) when the array is sorted in reverse order.
Average-case time complexity: O(n^2) when the array is randomly ordered.
Space complexity: O(1) as it only uses a constant amount of space.
*/

#include <stdio.h>

// Function to perform selection sort on the array
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;  // Assume the minimum is at the current position
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;  // Update min_index if a smaller element is found
            }
        }
        // Swap the found minimum element with the first unsorted element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
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

    // Perform selection sort on the array
    selection_sort(arr, n);

    // Print the sorted array
    printf("Selection Sorted array: ");
    print_array(arr, n);

    return 0;
}
