#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 12-integer array dynamically
    int *a = malloc(sizeof(int));

    // Initializing the array 
    for (int i = 0; i < 12; i++)
    {
        *(a + i) = rand() % 100;
    }

    // Printing the array with values
    printf("Array is: \n");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", *(a + i));
    }

    printf("\n");

    // Pointer to an array
    int(*b)[4];
    b = (int(*)[4])a;

    // Print the array as a 3x4 matrix
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}