
/*
Merge Sort is a divide-and-conquer algorithm that splits the array into smaller subarrays, sorts them, and then merges the sorted subarrays to produce a fully sorted array. It’s efficient for large datasets and has a consistent time complexity.

Best-case time complexity: O(n log(n)) when the array is already sorted.
Worst-case time complexity: O(n log(n)) when the array is sorted in reverse order.
Average-case time complexity: O(n log(n))
Space complexity: O(n)
*/

#include <stdio.h>

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;      // Size of the right subarray

    // Temporary arrays for left and right subarrays
    int leftArray[n1], rightArray[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArray[], if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArray[], if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on the array
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle point

        // Sort the first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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
    int arr[] = {12, 11, 13, 5, 6, 7};  // Array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    // Perform merge sort on the array
    merge_sort(arr, 0, n - 1);

    // Print the sorted array
    printf("Merge Sorted array: ");
    print_array(arr, n);

    return 0;
}
