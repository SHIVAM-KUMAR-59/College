#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, exp;
    struct node *next;
};

// Function to create a polynomial
void create(struct node **head) {
    for (int i = 0; i < 5; i++) {
        struct node *curr = malloc(sizeof(struct node));
        if (curr == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        curr->next = NULL;
        curr->coeff = rand() % 10 + 1; // Avoid zero coefficients
        curr->exp = rand() % 5;

        if (*head == NULL) {
            *head = curr;
        } else {
            struct node *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
    }
}

// Function to display the polynomial
void display(struct node *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to join two polynomials
void join(struct node **h1, struct node *h2) {
    if (*h1 == NULL) {
        *h1 = h2;
    } else {
        struct node *temp = *h1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = h2;
    }
    printf("The joined polynomial is:\n");
    display(*h1);
}

// Function to add two polynomials
void addition(struct node *h1) {
    struct node *ptr1 = h1, *ptr2, *prev;
    while (ptr1 != NULL) {
        prev = ptr1;
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr2->exp == ptr1->exp) {
                ptr1->coeff += ptr2->coeff;
                prev->next = ptr2->next;
                free(ptr2);
                ptr2 = prev->next;
            } else {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    printf("The sum of the two polynomials is:\n");
    display(h1);
}

// Function to subtract two polynomials
void substraction(struct node *h1) {
    struct node *ptr1 = h1, *ptr2, *prev;
    while (ptr1 != NULL) {
        prev = ptr1;
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr2->exp == ptr1->exp) {
                ptr1->coeff -= ptr2->coeff;
                prev->next = ptr2->next;
                free(ptr2);
                ptr2 = prev->next;
            } else {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    printf("The subtraction of the two polynomials is:\n");
    display(h1);
}

// Function to multiply two polynomials
void multiplication(struct node *h1, struct node *h2, struct node **h) {
    struct node *ptr1 = h1, *ptr2, *ptr;

    for (ptr1 = h1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = h2; ptr2 != NULL; ptr2 = ptr2->next) {
            struct node *curr = malloc(sizeof(struct node));
            if (curr == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
            curr->next = NULL;
            curr->coeff = ptr1->coeff * ptr2->coeff;
            curr->exp = ptr1->exp + ptr2->exp;
            if (*h == NULL) {
                *h = curr;
            } else {
                struct node *temp = *h;
                struct node *prev = NULL;

                // Insert the current term in the correct place based on exponent
                while (temp != NULL && temp->exp > curr->exp) {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp != NULL && temp->exp == curr->exp) {
                    // Combine like terms by adding coefficients
                    temp->coeff += curr->coeff;
                    free(curr);
                } else {
                    // Insert the new term into the list
                    if (prev == NULL) {
                        curr->next = *h;
                        *h = curr;
                    } else {
                        curr->next = temp;
                        prev->next = curr;
                    }
                }
            }
        }
    }
    printf("The product of the two polynomials is:\n");
    display(*h);
}


int main() {
    struct node *h1 = NULL;
    struct node *h2 = NULL;
    struct node *h = NULL;
    create(&h1);
    create(&h2);
    printf("Polynomial 1: ");
    display(h1);
    printf("Polynomial 2: ");
    display(h2);

    join(&h1, h2);
    addition(h1);
    // substraction(h1);
    // multiplication(h1, h2, &h);

    return 0;
}
