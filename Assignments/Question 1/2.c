// Write a program that will pass a two dimensional array to a function. The called function has to return middle row/s to the main function.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getMiddleRow(int rows, int cols, int array[rows][cols], int* middleRowsCount) {
    int startRow = (rows - 1) / 2;
    *middleRowsCount = (rows % 2 == 0) ? 2 : 1;

    int* middleRow = (int*)malloc(*middleRowsCount * cols * sizeof(int));
    if (!middleRow) { printf("Memory allocation failed\n"); exit(1); }

    for (int i = 0; i < *middleRowsCount * cols; i++)
        middleRow[i] = array[startRow + i / cols][i % cols];

    return middleRow;
}

int main() {
    int rows = 3, cols = 3;
    int array[rows][cols];

    // Seed for random number generation
    srand(time(0));

    // Fill the array with random numbers
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            array[i][j] = rand() % 100;  // Random number between 0 and 99

    // Display the generated array
    printf("Generated Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }

    int middleRowsCount;
    int* middleRow = getMiddleRow(rows, cols, array, &middleRowsCount);

    // Print the middle row(s)
    printf("\nMiddle row(s):\n");
    for (int i = 0; i < middleRowsCount * cols; i++) {
        printf("%d ", middleRow[i]);
        if ((i + 1) % cols == 0) printf("\n");
    }

    free(middleRow);
    return 0;
}
