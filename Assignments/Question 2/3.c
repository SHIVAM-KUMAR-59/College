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
    *arr = realloc(*arr, (*size += num) * sizeof(int));
    for (int i = *size - 1; i >= pos + num; i--) (*arr)[i] = (*arr)[i - num];
    for (int i = 0; i < num; i++) (*arr)[pos + i] = new_elements[i];
}

int main() {
    int n, pos, num;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter position and number of elements to insert: ");
    scanf("%d %d", &pos, &num);

    int *new_elements = malloc(num * sizeof(int));
    printf("Enter the new elements:\n");
    for (int i = 0; i < num; i++) scanf("%d", &new_elements[i]);

    insert(&arr, &n, pos, new_elements, num);

    printf("Modified array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    free(arr);
    free(new_elements);
    return 0;
}
