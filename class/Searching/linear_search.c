// Linear Searching is traversing through the array sequentially until
// the element is found. If the element is not found in the array then 
// the function returns -1.

#include<stdio.h>

int linear_search(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int index = linear_search(arr, n, x);
    if(index == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index %d", index);
    }
    return 0;
}