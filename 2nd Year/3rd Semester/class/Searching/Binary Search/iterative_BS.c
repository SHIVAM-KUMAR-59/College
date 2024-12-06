/*
Binary search is a fast algorithm to find an element in a sorted array. It repeatedly divides the search interval in half, checking the middle element, achieving O(log n) complexity.
*/

#include<stdio.h>

// Function to perform iterative binary search on a sorted array
int binarySearch(int arr[], int lower_index, int upper_index, int key) {

    // Loop until the search interval is valid
    while (lower_index <= upper_index) {
        // Calculate the middle index
        int mid = (lower_index + upper_index) / 2;

        // Check if the middle element is the key we're looking for
        if (arr[mid] == key) {
            return mid; // Return the index if key is found
        }
        // If the middle element is greater than the key, search in the left half
        else if (arr[mid] > key) {
            upper_index = mid - 1;
        }
        // If the middle element is less than the key, search in the right half
        else {
            lower_index = mid + 1;
        }
    }
    // Return -1 if the key is not found
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sorted array to search in
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int key = 5; // Element to search for

    // Call binary search and store result
    int result = binarySearch(arr, 0, n - 1, key);

    // Check if the element was found and print the result
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index %d", result);
    }
    return 0;
}
