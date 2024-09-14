
// Impementation of sparse matrix using Linked Lists

#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, val;
    struct node *next;
};

// Function to create a sparse matrix
void create(struct node **head) {
    *head = malloc(sizeof(struct node));
    (*head)->next = NULL;
    printf("Enter the number of rows, columns, and non-zero elements: \n");
    scanf("%d %d %d", &(*head)->row, &(*head)->col, &(*head)->val);

    struct node *ptr = *head;

    for (int i = 0; i < (*head)->val; i++) {
        struct node *curr = malloc(sizeof(struct node));
        printf("Enter the row, column of element %d and the non-zero element present at that position: \n", i + 1);
        scanf("%d %d %d", &curr->row, &curr->col, &curr->val);
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
    }
}

// Function to display the sparse matrix
void display(struct node *head) {
    struct node *ptr = head; 
    while (ptr != NULL) {
        printf("%d %d %d\n", ptr->row, ptr->col, ptr->val);
        ptr = ptr->next;
    }
}

// Function to transpose the matrix
void transpose(struct node *head) {
    struct node *temp = head->next;
    while (temp != NULL) {
        int t = temp->row;
        temp->row = temp->col;
        temp->col = t;
        temp = temp->next;
    }
    display(head);
}

// Function to join two sparse matrices
void join(struct node *h1, struct node *h2, struct node **h) {
    if (h1->row != h2->row || h1->col != h2->col) {
        printf("The two matrices are incompatible\n");
        return;
    } else {
        // Fill the header node
        *h = malloc(sizeof(struct node));
        (*h)->row = h1->row;
        (*h)->col = h1->col;
        (*h)->val = h1->val + h2->val;
        (*h)->next = NULL;
        struct node *ptr = *h;

        // Copy all the elements of the first matrix
        for (struct node *p2 = h1->next; p2 != NULL; p2 = p2->next) {
            struct node *curr = malloc(sizeof(struct node));
            *curr = *p2;
            curr->next = NULL;
            ptr->next = curr;
            ptr = curr;
        }

        // Copy all the elements of the second matrix
        for (struct node *p2 = h2->next; p2 != NULL; p2 = p2->next) {
            struct node *curr = malloc(sizeof(struct node));
            *curr = *p2;
            curr->next = NULL;
            ptr->next = curr;
            ptr = curr;
        }
    }
}

// Function to simplify the sparse matrix by combining duplicate elements
void simplify(struct node **h) {
    struct node *ptr = (*h)->next;
    while (ptr != NULL) {
        struct node *prev = ptr;
        struct node *ptr1 = ptr->next;
        while (ptr1 != NULL) {
            // If compatible then add the nodes and delete the extra node
            if (ptr->row == ptr1->row && ptr->col == ptr1->col) {
                ptr->val += ptr1->val;
                prev->next = ptr1->next;
                free(ptr1);
                (*h)->val--;
                ptr1 = prev;
            } else {
                // Else continue in the loop
                prev = ptr1;
                ptr1 = ptr1->next;
            }
        }
        ptr = ptr->next;
    }
}

// Function to multiply two sparse matrices
void multiply(struct node *h1, struct node *h2, struct node **h) {
    if (h1->col != h2->row) {
        printf("Matrix multiplication cannot be performed\n");
        exit(1);
    } else {
        // Fill the header node
        struct node *tail;
        tail = *h = malloc(sizeof(struct node));
        (*h)->next = NULL;
        (*h)->row = h1->row;
        (*h)->col = h2->col;
        (*h)->val = 0;

        // Multiply each element if compatible
        for (struct node *p1 = h1->next; p1 != NULL; p1 = p1->next) {
            for (struct node *p2 = h2->next; p2 != NULL; p2 = p2->next) {
                if (p1->col == p2->row) {
                    struct node *curr = malloc(sizeof(struct node));
                    curr->row = p1->row;
                    curr->col = p2->col;
                    curr->val = p1->val * p2->val;
                    curr->next = NULL;

                    struct node *temp = *h;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = curr;
                    (*h)->val++;
                }
            }
        }
        simplify(h); // Simplify after all elements are inserted
    }
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *result = NULL;

    printf("Create first matrix:\n");
    create(&head1);
    printf("The first sparse matrix is: \n");
    display(head1);

    printf("\nCreate second matrix:\n");
    create(&head2);
    printf("The second sparse matrix is: \n");
    display(head2);

    printf("\nTranspose of the first matrix:\n");
    transpose(head1);

    printf("\nTranspose of the second matrix:\n");
    transpose(head2);

    printf("\nJoining and Adding the two matrices:\n");
    join(head1, head2, &result);
    simplify(&result);
    display(result);

    printf("\nMultiplication of the two matrices:\n");
    multiply(head1, head2, &result);
    display(result);

    return 0;
}
