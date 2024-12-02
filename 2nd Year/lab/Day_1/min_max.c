
// Calculate the minimum and maximum in an array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 10;
    }
    printf("Random array: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
        printf("Maximum: %d\n", max);
        printf("Minimum: %d\n", min);
        return 0;
    }
}