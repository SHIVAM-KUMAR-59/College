#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    int groupStart = 0;
    int groupEnd = 0;
    int arr[] = {0,0,1,2,3,0,4,5,0,6,7,0};
    int min = 0;
 
    // // Generate a random array
    // for (int i = 0; i < 10; i++)
    // {
    //     arr[i] = rand() % 100;
    // }

    printf("Random array is: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int j = 0; j < 10; j++)
    {
        if ((j == 0 && arr[j] != 0) || (arr[j] != 0 && arr[j - 1] == 0))
        {
            // Group starts
            groupStart = j;
            min = arr[j];
        }
        if (arr[j] != 0 && (arr[j] < min))
        {
            min = arr[j];
        }
        if ((arr[j] != 0 && arr[j + 1] == 0) || (arr[j] != 0 && j == 9))
        {
            // Group ends
            groupEnd = j;
            printf("Group from index %d to %d, Minimum value: %d\n", groupStart, groupEnd, min);
        }
    }

    return 0;
}