/*
Write a program to remove repeated elements in a given array.
*/

#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(int *arr, int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < *n - 1; k++) arr[k] = arr[k + 1];
                (*n)--;
            } else {
                j++;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) return 1;

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    removeDuplicates(arr, &n);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    free(arr);
    return 0;
}
