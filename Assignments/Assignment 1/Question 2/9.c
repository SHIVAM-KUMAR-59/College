
/*
Write a program to find the square matrix subset of an original twodimensional matrix whose summation, i.e. the summationof all theelements of square matrix subset, is equal to the required number.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Function to calculate the sum of all elements in a matrix
int sumMatrix(int **matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            sum += matrix[i][j];
    return sum;
}

// Function to find and print square submatrices with the required sum
void findSquareSubset(int **matrix, int rows, int cols, int required_sum) {
    int found = 0;
    for (int i = 0; i <= rows - 1; i++) {
        for (int j = 0; j <= cols - 1; j++) {
            for (int size = 1; size <= rows - i && size <= cols - j; size++) {
                int **subset = (int **)malloc(size * sizeof(int *));
                for (int k = 0; k < size; k++) subset[k] = (int *)malloc(size * sizeof(int));
                for (int k = 0; k < size; k++)
                    for (int l = 0; l < size; l++)
                        subset[k][l] = matrix[i + k][j + l];
                
                if (sumMatrix(subset, size) == required_sum) {
                    printf("Found a square subset of size %d:\n", size);
                    printMatrix(subset, size);
                    printf("\n");
                    found = 1;
                }
                for (int k = 0; k < size; k++) free(subset[k]);
                free(subset);
            }
        }
    }
    if (!found) printf("The subset matrix with the required sum does not exist\n");
}

int main() {
    int rows, cols, required_sum;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) scanf("%d", &matrix[i][j]);

    printf("Enter required sum: ");
    scanf("%d", &required_sum);

    findSquareSubset(matrix, rows, cols, required_sum);

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);

    return 0;
}
