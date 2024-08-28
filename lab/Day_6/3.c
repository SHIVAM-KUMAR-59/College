// WAP to find out intersection, union and substraction of Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
    int data;
    struct node *next;
};

// Function to create the linked list
void create(struct node **head) {
    for (int i = 0; i < 5; i++) {
        struct node *curr = malloc(sizeof(struct node));
        curr->data = rand() % 100;
        curr->next = NULL;
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

// Function to display the linked list
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to check if a value exists in the linked list
int exists(struct node *head, int value) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to find the union of two linked lists
void Union(struct node *h1, struct node *h2) {
    struct node *h3 = NULL;
    struct node *temp = h1;

    // Add all elements of the first list to h3
    while (temp != NULL) {
        struct node *curr = malloc(sizeof(struct node));
        curr->data = temp->data;
        curr->next = NULL;
        if (h3 == NULL) {
            h3 = curr;
        } else {
            struct node *t = h3;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = curr;
        }
        temp = temp->next;
    }

    // Add only those elements of the second list to h3 that are not already present
    temp = h2;
    while (temp != NULL) {
        if (!exists(h3, temp->data)) {
            struct node *curr = malloc(sizeof(struct node));
            curr->data = temp->data;
            curr->next = NULL;
            struct node *t = h3;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = curr;
        }
        temp = temp->next;
    }

    printf("Union of the lists:\n");
    display(h3);
}

// Function to find the intersection of two linked lists
void Intersection(struct node *h1, struct node *h2) {
    struct node *h3 = NULL;
    struct node *temp = h1;

    while (temp != NULL) {
        if (exists(h2, temp->data)) {
            struct node *curr = malloc(sizeof(struct node));
            curr->data = temp->data;
            curr->next = NULL;
            if (h3 == NULL) {
                h3 = curr;
            } else {
                struct node *t = h3;
                while (t->next != NULL) {
                    t = t->next;
                }
                t->next = curr;
            }
        }
        temp = temp->next;
    }

    printf("Intersection of the lists:\n");
    display(h3);
}

// Function to find the subtraction of list h2 from list h1 (h1 - h2)
void Subtraction(struct node *h1, struct node *h2) {
    struct node *h3 = NULL;
    struct node *temp = h1;

    while (temp != NULL) {
        if (!exists(h2, temp->data)) {
            struct node *curr = malloc(sizeof(struct node));
            curr->data = temp->data;
            curr->next = NULL;
            if (h3 == NULL) {
                h3 = curr;
            } else {
                struct node *t = h3;
                while (t->next != NULL) {
                    t = t->next;
                }
                t->next = curr;
            }
        }
        temp = temp->next;
    }

    printf("Subtraction (h1 - h2) of the lists:\n");
    display(h3);
}

int main() {
    struct node *h1 = NULL;
    struct node *h2 = NULL;

    create(&h1);
    create(&h2);

    printf("First Linked List:\n");
    display(h1);
    printf("Second Linked List:\n");
    display(h2);


    Union(h1, h2);
    Intersection(h1, h2);
    Subtraction(h1, h2);

    return 0;
}
