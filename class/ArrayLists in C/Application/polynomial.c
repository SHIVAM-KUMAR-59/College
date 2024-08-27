#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, exp;
};

// Function to create a polynomial
void create(struct node **a, int *n) {
    printf("Enter the number of terms: ");
    scanf("%d", n);
    *a = (struct node*)malloc(*n * sizeof(struct node));
    if (*a == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for(int i = 0; i < *n; i++) {
        (*a + i)->coeff = rand() % 10 + 1;  // Avoiding zero coefficients
        (*a + i)->exp = rand() % 5;
    }
}

// Function to display the polynomial
void display(struct node *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("%dx^%d", (a + i)->coeff, (a + i)->exp);
        if (i < n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to join two polynomials
void join(struct node **a, struct node *b, int n, int m) {
    *a = realloc(*a, (n + m) * sizeof(struct node));
    if (*a == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    // Copying elements from b into a
    for(int i = 0; i < m; i++) {
        (*a + n + i)->coeff = (b + i)->coeff;
        (*a + n + i)->exp = (b + i)->exp;
    }
}

void add(struct node *a,struct node **c, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if((a + i)->exp == (a + j)->exp){
                (a + i)->coeff += (a + j)->coeff;
            }
        }
    }
}

int main() {
    struct node *a;
    int n;
    struct node *b;
    int m;
    struct node *c;

    create(&a, &n);
    create(&b, &m);
    printf("The first polynomial:\n");
    display(a, n);
    printf("The second polynomial:\n");
    display(b, m);

    printf("After joining the two polynomials:\n");
    join(&a, b, n, m);
    display(a, n + m);

    add(a, &c, n + m);
    display(a, n+m);

    free(a);
    free(b);

    return 0;
}
