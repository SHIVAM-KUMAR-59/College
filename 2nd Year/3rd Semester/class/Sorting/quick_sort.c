#include <stdio.h>
#include <stdlib.h>

// Partition function: Divides the array into two parts around a pivot
int partition(int arr[], int i, int j) {
    int l = i;                // Start pointer (left boundary)
    int u = j;                // End pointer (right boundary)
    int pivot = arr[i];       // Choose the first element as pivot

    while (l < u) {           // Loop until the two pointers meet
        // Move the left pointer while elements are less than or equal to the pivot
        while (l < j && arr[l] <= pivot) {
            l++;
        }
        // Move the right pointer while elements are greater than the pivot
        while (arr[u] > pivot) {
            u--;
        }

        // Swap elements if left pointer is still less than the right pointer
        if (l < u) {
            int temp = arr[l];
            arr[l] = arr[u];
            arr[u] = temp;
        }
    }

    // Swap the pivot with the element at the right pointer to place it in its correct position
    int temp = arr[i];
    arr[i] = arr[u];
    arr[u] = temp;

    return u; // Return the final position of the pivot
}

// Quick Sort function: Sorts the array using recursion
void quick_sort(int arr[], int l, int h) {
    if (l < h) { // Continue sorting if the sub-array has more than one element
        // Partition the array and get the pivot index
        int pivot = partition(arr, l, h);

        // Recursively sort the sub-array to the left of the pivot
        quick_sort(arr, l, pivot - 1);

        // Recursively sort the sub-array to the right of the pivot
        quick_sort(arr, pivot + 1, h);
    }
}

int main() {
    // Define an array to be sorted
    int arr[] = {1, 3, 2, 4, 6, 5, 9, 8, 21, 12};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Perform quick sort on the array
    quick_sort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0; // Return 0 to indicate successful program termination
}
