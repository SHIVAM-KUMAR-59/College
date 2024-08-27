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

#define N 3  // Number of rows
#define M 4  // Number of columns

// Function to rearrange the array
void rearrange(int arr[N][M], int n) {
    int totalElements = N * M;
    int flatArray[totalElements];
    int freq[totalElements];
    
    // Initialize frequency array
    for (int i = 0; i < totalElements; i++) {
        freq[i] = 0;
    }
    
    // Flatten the 2D array into a 1D array
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            flatArray[k++] = arr[i][j];
        }
    }
    
    // Calculate frequency of each element
    for (int i = 0; i < totalElements; i++) {
        freq[flatArray[i]]++;
    }
    
    // Sort the flattened array using simple selection sort
    for (int i = 0; i < totalElements - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < totalElements; j++) {
            if (flatArray[j] < flatArray[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = flatArray[minIndex];
        flatArray[minIndex] = flatArray[i];
        flatArray[i] = temp;
    }
    
    // Group the elements based on frequency
    int newArr[N][M];
    int index = 0;
    for (int i = 0; i < totalElements; ) {
        int value = flatArray[i];
        for (int j = 0; j < freq[value]; j++) {
            newArr[index / M][index % M] = value;
            index++;
        }
        i += freq[value]; // Skip over all occurrences of this value
    }
    
    // Display the rearranged array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", newArr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[N][M] = {
        {2, 3, 1, 4},
        {3, 1, 2, 2},
        {1, 3, 4, 4}
    };

    int n = 3;  // Number of repetitions in the original array

    printf("Original Array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nRearranged Array:\n");
    rearrange(arr, n);

    return 0;
}
