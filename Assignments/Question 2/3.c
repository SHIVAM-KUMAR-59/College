/*
In a one dimensional array insert one or more element at a
particular position of an array. Ex: Given array: 1,2,3,4,5,6,7,8,9
insert 15,17,19 at the 5
th position of the given array. Output: 1,2,3,4,15,17,18,5,6,7,8,9
You can apply the realloc to increase the size of the array if necessary.
*/

#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int pos, int *new_elements, int num) {
    // Adjust the size of the array
    *arr = (int*)realloc(*arr, (*size + num) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    
    // Shift the elements to the right to make space for the new elements
    for (int i = *size - 1; i >= pos; i--) {
        (*arr)[i + num] = (*arr)[i];
    }
    
    // Insert the new elements
    for (int i = 0; i < num; i++) {
        (*arr)[pos + i] = new_elements[i];
    }
    
    // Update the size of the array
    *size += num;
}

int main() {
    int n, pos, num;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position where you want to insert new elements: ");
    scanf("%d", &pos);

    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &num);

    int *new_elements = (int *)malloc(num * sizeof(int));

    printf("Enter the new elements:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &new_elements[i]);
    }

    insert(&arr, &n, pos, new_elements, num);

    printf("Modified array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    free(new_elements);

    return 0;
}
