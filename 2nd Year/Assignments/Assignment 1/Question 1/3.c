/*
Let us assume a two dimensional array consists of different numbers and each number
is repeated equal number of times in this array. You need to write a function whichwill
rearrange the array where each number will contiguously present in that array. Youhave to create a pointer which will pointing to a row having n number of elements, where n is the number of times each number gets repeated in the original array. Using this pointer, you need to display the modified array. Original array
2,3,1,4,
3,1,2,2,
1,3,4,4
New array
1,1,1,2
,2,2,3,3
,3,4,4,4
For this example, you have to create a pointer which will point to 3 element row. Usingthis pointer, you have to display this new array.
*/

#include <stdio.h>
#include <stdlib.h>

void rearrange(int **arr, int n, int m) {
    int totalElements = n * m;
    int *flatArray = (int *)malloc(totalElements * sizeof(int));
    int *freq = (int *)calloc(101, sizeof(int)); // Assuming max value <= 100
    int k = 0;

    // Flatten the array and compute frequencies
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            flatArray[k] = arr[i][j];
            freq[arr[i][j]]++;
            k++;
        }

    // Sort the flattened array
    for (int i = 0; i < totalElements - 1; i++)
        for (int j = i + 1; j < totalElements; j++)
            if (flatArray[j] < flatArray[i]) {
                int temp = flatArray[i];
                flatArray[i] = flatArray[j];
                flatArray[j] = temp;
            }

    // Rearrange the 2D array
    int index = 0;
    for (int i = 0; i < totalElements; i += freq[flatArray[i]]) {
        int value = flatArray[i];
        for (int j = 0; j < freq[value]; j++)
            arr[index / m][index++ % m] = value;
    }

    free(flatArray);
    free(freq);

    // Print the rearranged array
    printf("Rearranged Array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int main() {
    int n = 3, m = 4;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(m * sizeof(int));

    int values[3][4] = {{2, 3, 1, 4}, {3, 1, 2, 2}, {1, 3, 4, 4}};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = values[i][j];

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    rearrange(arr, n, m);

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
