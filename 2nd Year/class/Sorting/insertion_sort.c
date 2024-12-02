/*
Insertion sort is a simple sorting algorithm that builds the sorted array one element at a time by repeatedly inserting the next element into the sorted portion of the array.

Best-case time complexity: O(n) when the array is already sorted.
Worst-case time complexity: O(n^2) when the array is sorted in reverse order.
Average-case time complexity: O(n^2)
Space complexity: O(1) (in-place sorting).
*/

#include <stdio.h>

// Function to perform insertion sort on a subset of the array
void insertion_sort(int arr[], int lower_index, int upper_index) {
    // Traverse the array starting from the second element
    for (int i = lower_index + 1; i <= upper_index; i++) {
        int temp = arr[i];  // Store the current element to be inserted
        int j = i - 1;  // Initialize `j` to point to the last element of the sorted portion

        // Shift elements of sorted portion of array to make space for `temp`
        for (; j >= lower_index; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];  // Shift element to the right
            } else {
                break;  // Exit the loop if `temp` is greater or equal
            }
        }
        arr[j + 1] = temp;  // Insert `temp` in its correct sorted position
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

    // Perform insertion sort on the entire array
    insertion_sort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
