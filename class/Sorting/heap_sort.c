#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int i, int n) {
    int left_child = (2 * i) + 1;  // Left child index
    int right_child = (2 * i) + 2; // Right child index
    int max = i;                   // Initialize the largest element as root

    // Check if left child is larger than root
    if (left_child < n && arr[left_child] > arr[max]) {
        max = left_child;
    }

    // Check if right child is larger than the current largest
    if (right_child < n && arr[right_child] > arr[max]) {
        max = right_child;
    }

    // If the largest is not root, swap and recursively heapify
    if (max != i) {
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr, max, n); // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Sort
void heap_sort(int arr[], int n) {
    // Build a max heap
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (maximum element) to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Reduce the size of the heap and heapify the root again
        heapify(arr, 0, i);
    }
}

int main() {
    int arr[] = {1, 3, 2, 4, 6, 5, 9, 8, 21, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform heap sort
    heap_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
