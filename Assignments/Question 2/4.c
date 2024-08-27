/* 
In a one dimensional array delete all even numbers present in the array.
*/

#include <stdio.h>
#include <stdlib.h>

void deleteEvenNumbers(int **arr, int *size) {
    int j = 0;
    for (int i = 0; i < *size; i++) 
        if ((*arr)[i] % 2 != 0) 
            (*arr)[j++] = (*arr)[i];

    *arr = realloc(*arr, j * sizeof(int));
    *size = j;
}

int main() {
    int size = 10;
    int *a = malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++) 
        a[i] = rand() % 100;

    printf("Original array: \n");
    for (int i = 0; i < size; i++) 
        printf("%d ", a[i]);

    deleteEvenNumbers(&a, &size);

    printf("\nArray after deleting even numbers: \n");
    for (int i = 0; i < size; i++) 
        printf("%d ", a[i]);

    free(a);
    return 0;
}
