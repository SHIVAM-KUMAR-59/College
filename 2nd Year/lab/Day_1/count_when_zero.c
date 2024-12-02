
// Increase count if prevCount < nextCount else count -= 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    int groupStart = 0;
    int groupEnd = 0;
    int arr[] = {0, 0, 1, 1, 1, 0, 1, 1, 0, 1};
    int count = 0;
    int ones = 0;

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
            ones = 1; // Reset ones to 1
        }
        else if (arr[j] != 0)
        {
            // Increment ones if current element is 1
            ones++;
        }
        count = ones;
        if ((arr[j] != 0 && arr[j + 1] == 0) || (arr[j] != 0 && j == 9))
        {
            // Group ends
            // printf("%d ", ones); // Print the count of ones
            if (count > ones)
            {
                count = ones;
            }
            else
            {
                count = count - 1;
            }
        }
    }
    printf("The final count is: %d ", count);

    return 0;
}