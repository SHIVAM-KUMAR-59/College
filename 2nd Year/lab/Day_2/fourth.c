// create 3-D array 3x2x4 dynamically
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // Initializing the array
    int ***arr = (int ***)malloc(3 * sizeof(int **));
    for (int i = 0; i < 3; i++)
    {
        arr[i] = (int **)malloc(2 * sizeof(int *));
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = (int *)malloc(4 * sizeof(int));
        }
    }

    // Entering the values in the array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                arr[i][j][k] = rand() % 100;
            }
        }
    }

    // Printing the array
    printf("The array is: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Storing the arr[1] in another 1-D array
    int *temp = (int *)malloc(8 * sizeof(int));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp[i * 4 + j] = arr[1][i][j];
        }
    }

    // Printing the array
    printf("The elements are: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", temp[i]);
    }
    return 0;
}