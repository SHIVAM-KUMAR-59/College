
/*
Write a program to reverse the even index position and oddindexposition for even element array and odd element array.
*/
#include <stdio.h>
#include <stdlib.h>

// Function to reverse elements at given indices
void reverseIndices(int* arr, int size, int start) {
    int end = (size % 2 == (start % 2)) ? size - 2 : size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start += 2;
        end -= 2;
    }
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) { printf("Memory allocation failed\n"); return 1; }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    reverseIndices(arr, size, size % 2);  // 0 for even, 1 for odd

    printf("Modified array:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}
