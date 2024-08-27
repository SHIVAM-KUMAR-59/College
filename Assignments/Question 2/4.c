/* 
In a one dimensional array delete all even numbers present in the array.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to delete all even numbers in the array
void deleteEvenNumbers(int **arr, int *size) {
    int newSize = 0;

    // Count how many odd numbers are present
    for (int i = 0; i < *size; i++) {
        if ((*arr)[i] % 2 != 0) {
            newSize++;
        }
    }

    // Allocate new memory for the array containing only odd numbers
    int *newArr = (int *)malloc(newSize * sizeof(int));

    if (newArr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < *size; i++) {
        if ((*arr)[i] % 2 != 0) {
            newArr[j] = (*arr)[i];
            j++;
        }
    }

    free(*arr);
    *arr = newArr;
    *size = newSize;
}

int main() {
    int size = 10;
    int *a = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        *(a + i) = rand() % 100;
    }

    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(a + i));
    }

    deleteEvenNumbers(&a, &size);

    printf("\nArray after deleting even numbers: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(a + i));
    }

    free(a);

    return 0;
}
