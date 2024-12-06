#include<stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) { // Check if the search interval is valid
        int mid = l + (r - l) / 2; // Calculate the middle index

        // If element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, search in the left half
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // If element is larger than mid, search in the right half
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40}; // Example sorted array
    int x = 10; // Element to search for
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the array size

    // Call binary search and store result
    int result = binarySearch(arr, 0, n - 1, x);

    // Print the result
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}
