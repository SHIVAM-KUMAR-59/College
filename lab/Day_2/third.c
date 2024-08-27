
// Create a 2-D array using pointer to an array
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of arrays: ");
    scanf("%d", &n);

    // Create an array to store the lengths of each array
    int *lengths = malloc(n * sizeof(int));

    // Create an array of pointers to integers
    int **arr = malloc(n * sizeof(int *));

    // Initialize each array and store its length
    for (int i = 0; i < n; i++) {
        lengths[i] = i + 1;
        arr[i] = malloc(lengths[i] * sizeof(int));

        // Initialize the values in each array
        for (int j = 0; j <= i; j++) {
            arr[i][j] = (i * (i + 1)) / 2 + j + 1;
        }
    }

    // Print the 2D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lengths[i]; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // free the memory
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(lengths);

    return 0;
}


// #include<stdio.h>
// #include<stdlib.h>
// int main(){
//     int n = rand() % 10;

//     int *a = malloc(n * sizeof(int));
//     a[0] = 1;
//     int *b = malloc(n * sizeof(int));
//     b[0] = 2;
//     b[1] = 3;
//     int *c = malloc(n * sizeof(int));
//     c[0] = 4;
//     c[1] = 5;
//     c[2] = 6;
//     int *d = malloc(n * sizeof(int));
//     d[0] = 7;
//     d[1] = 8;
//     d[2] = 9;
//     d[3] = 10;

//     int **arr = malloc(4 * sizeof(int *));
//     arr[0] = a;
//     arr[1] = b;
//     arr[2] = c;
//     arr[3] = d;

//     // Print the array
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < i + 1; j++) {
//             printf("%d ", *(arr[i] + j));
//         }
//         printf("\n");
//     }
//     return 0;
// }

