
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
        for (int sum = 0, j = i - 1; j >= 0; j--) {
            if ((sum += arr[j]) == arr[i]) {
                printf("Output is %d, a summation of previous elements at position %d.\n", arr[i], i);
                break;
            }
        }
    }
}

int main() {
    int n, *a;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    a = malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    findSummationElements(a, n);

    free(a);
    return 0;
}
