/*
Write a program to find whether an array is subset of another array
*/

#include <stdio.h>
#include <stdlib.h>

// Function to check if `b` is a subset of `a`
int isSubset(int *a, int n, int *b, int m) {
    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (b[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;

    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed for the first array.\n");
        exit(1);
    }

    printf("Enter elements of the first array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &m);
    int *b = (int *)malloc(m * sizeof(int));
    if (b == NULL) {
        printf("Memory allocation failed for the second array.\n");
        free(a);
        exit(1);
    }

    printf("Enter elements of the second array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    printf("\nFirst array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nSecond array: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", b[i]);
    }

    if (isSubset(a, n, b, m)) {
        printf("\nThe second array is a subset of the first array.\n");
    } else {
        printf("\nThe second array is NOT a subset of the first array.\n");
    }

    free(a);
    free(b);

    return 0;
}
