
// WAP to find out intersection, union and substraction of sets

#include <stdio.h>
#include <stdlib.h>

// Function to display an array
void display(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to find union of two sets
void Union(int *a, int n, int *b, int m) {
    int *c = (int *)malloc((n + m) * sizeof(int));
    int k = 0;

    // Copy all elements of set A to C
    for (int i = 0; i < n; i++) {
        c[k++] = a[i];
    }

    // Copy elements of set B to C, if not already present
    for (int i = 0; i < m; i++) {
        int present = 0;
        for (int j = 0; j < n; j++) {
            if (b[i] == a[j]) {
                present = 1;
                break;
            }
        }
        if (!present) {
            c[k++] = b[i];
        }
    }

    printf("Union: ");
    display(c, k);
    free(c);
}

// Function to find intersection of two sets
void intersection(int *a, int n, int *b, int m) {
    int *c = (int *)malloc((n < m ? n : m) * sizeof(int));
    int k = 0;

    // Find common elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                c[k++] = a[i];
                break;
            }
        }
    }

    printf("Intersection: ");
    if(k == 0){
        printf("Null\n");
    }else{
    display(c, k);
    }
    free(c);
}

// Function to find the difference of two sets (A - B)
void difference(int *a, int n, int *b, int m) {
    int *c = (int *)malloc(n * sizeof(int));
    int k = 0;

    // Add elements of A that are not in B
    for (int i = 0; i < n; i++) {
        int present = 0;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                present = 1;
                break;
            }
        }
        if (!present) {
            c[k++] = a[i];
        }
    }

    if (k == 0) {
        printf("Difference (A - B): No elements\n");
    } else {
        printf("Difference (A - B): ");
        display(c, k);
    }

    free(c);
}


int main() {
    int n, m;

    printf("Enter size of first set: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter elements of first set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second set: ");
    scanf("%d", &m);
    int *b = (int *)malloc(m * sizeof(int));
    printf("Enter elements of second set: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    Union(a, n, b, m);
    intersection(a, n, b, m);
    difference(a, n, b, m);

    free(a);
    free(b);
    return 0;
}
