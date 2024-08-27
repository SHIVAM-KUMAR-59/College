
/*
In a one dimensional array, user gives a certain range of indexwithshifting value. You need to right shift and rotate those range of
values based on the given shifting value. Do the same for left shift.
*/

#include <stdio.h>
#include <stdlib.h>

void rotate(int arr[], int left, int right, int shift, int direction) {
    int rangeSize = right - left + 1;
    shift %= rangeSize;
    if (shift == 0) return;

    int *temp = (int *)malloc(shift * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Store the elements to be shifted
    for (int i = 0; i < shift; i++) {
        temp[i] = arr[(direction == 1) ? right - i : left + i];
    }

    // Shift elements in the array
    if (direction == 1) {  // Right rotation
        for (int i = right; i > left; i--) {
            arr[i] = arr[i - shift];
        }
        for (int i = 0; i < shift; i++) {
            arr[left + i] = temp[i];
        }
    } else {  // Left rotation
        for (int i = left; i < right; i++) {
            arr[i] = arr[i + shift];
        }
        for (int i = 0; i < shift; i++) {
            arr[right - shift + 1 + i] = temp[i];
        }
    }

    free(temp);
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, left, right, shift;
    
    // User input for size of the array
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 100;

    printf("Original array:\n");
    displayArray(arr, n);

    // User input for the range and shift value
    printf("Enter left and right indices: ");
    scanf("%d %d", &left, &right);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Left shift and rotate
    printf("Array after left shift and rotate:\n");
    rotate(arr, left, right, shift, 0);
    displayArray(arr, n);

    // Right shift and rotate
    printf("Array after right shift and rotate:\n");
    rotate(arr, left, right, shift, 1);
    displayArray(arr, n);

    return 0;
}
