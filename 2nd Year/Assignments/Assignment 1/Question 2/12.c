
/*
. Write a program that will create an ascending element array fromthe given unsorted array by fulfilling the following criteria. The values present in the resultant array may be different fromthe original array but the digits present in the each element of theoriginal array must be present in the same position of the
resultant array. Your target should be to minimize the maximumvalue present inthe resultant array. Ex: Original array: 2,9,6,3,9,8,17,3,4,6,13,5
Resultant array: 2, 9, 16, 23, 29, 38, 71, 73, 74, 76, 103, 105
*/

#include <stdio.h>
#include <stdlib.h>

int contain(int num1, int num2) {
    int arr1[10] = {0}; // Changed to 10 as digits are 0-9
    int arr2[10] = {0};
    
    // Count digits in num1
    while (num1 > 0) {
        arr1[num1 % 10]++;
        num1 /= 10;
    }
    
    // Count digits in num2
    while (num2 > 0) {
        arr2[num2 % 10]++;
        num2 /= 10;
    }
    
    // Check if num2 is contained within num1
    for (int i = 0; i < 10; i++) {
        if (arr1[i] < arr2[i]) {
            return 1;  // Return 1 if num1 does not contain all digits of num2
        }
    }
    
    return 0;  // Return 0 if num1 contains all digits of num2
}

void create(int *arr, int size) {
    for (int i = 1; i < size; i++) {  // Start from 1 to avoid out-of-bounds error
        if (arr[i] < arr[i - 1]) {
            for (int j = arr[i - 1] + 1;; j++) {
                if (contain(j, arr[i]) == 0) {  // Corrected the condition
                    arr[i] = j;
                    break;
                }
            }
        }
    }
}

int main() {
    int size = 12;
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    create(arr, size);

    printf("\n\nModified array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // Freeing the allocated memory
    return 0;
}
