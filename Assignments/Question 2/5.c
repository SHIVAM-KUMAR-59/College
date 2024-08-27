
/*
In a one dimensional array find out all the elements and their
position, which is the summation of its immediate previous
contiguous elements. Ex: Given array: 2,9,6,3,9,8,17,3,6,4,13,5
Output: output is 9, which is a summation of it’s previous
elements 3 and 6
output is 13, which is a summation of it’s previous elements4,6and 3
*/

#include <stdio.h>
#include <stdlib.h>

void findSummationElements(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = i - 1; j >= 0; j--) {
            sum += arr[j];
            if (sum == arr[i]) {
                printf("Output is %d, which is a summation of its previous elements", arr[i]);
                printf(" at position %d.\n", i);
                break;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);  // Corrected scanf to correctly take the pointer
    }

    findSummationElements(a, n);

    free(a); // Free the allocated memory after use

    return 0;
}
