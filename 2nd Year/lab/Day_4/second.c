#include <stdio.h>
#include <stdlib.h>

// Function to insert an element into the array at a given index
void insert(int *arr, int *size, int num, int index) {
    if (*size >= 5) {
        printf("Array is full\n");
        return;
    }
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = num;
    (*size)++;
}

// Function to delete an element from the array at a given index
void delete(int *arr, int *size, int index) {
    if (*size <= 0) {
        printf("Array is empty\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Function to rotate the array segment
void rotate(int *arr, int startingIndex, int endingIndex, int times) {
    int n = endingIndex - startingIndex + 1;
    if (n <= 0) {
        return;
    }
    
    times = times % n;
    if (times < 0) {
        times += n;
    }

    if (times == 0) {
        return;
    }

    int tempArr[n];
    int tempSize = 0;

    for (int i = startingIndex; i <= endingIndex; i++) {
        tempArr[tempSize++] = arr[i];
    }

    // Delete the segment from the original position
    for (int i = startingIndex; i <= endingIndex; i++) {
        delete(arr, &tempSize, startingIndex);
    }

    // Insert the rotated segment
    for (int i = 0; i < n; i++) {
        insert(arr, &tempSize, tempArr[(i + times) % n], startingIndex + i);
    }
}

int main() {
    int arr[5];
    int size = 5;
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("\nOriginal array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rotate(arr, 1, 4, 2);

    printf("\nRotated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
