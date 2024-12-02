/*
N1 --> N2 -- > N3 --
                   |
                   |
                   -----> N7 --> N8 --> N9
                   |
                   |
N4 --> N5 --> N6 --
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create the linked list
void create(struct node **head, int n) {
    for (int i = 0; i < n; i++) {
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

// Function to get the length of the linked list
int getLength(struct node *head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the first intersection point 
void findIntersection(struct node *h1, struct node *h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    struct node *ptr1 = h1;
    struct node *ptr2 = h2;
    
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            ptr1 = ptr1->next;
        }
    } else if (len2 > len1) {
        for (int i = 0; i < len2 - len1; i++) {
            ptr2 = ptr2->next;
        }
    }

    // Traverse both lists together to find the intersection
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {  // Intersection found
            printf("The intersection is at node with data: %d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No intersection found.\n");
}

// Function to display the linked list
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("Linked list terminated\n");
}

int main() {
    struct node *h1 = NULL;
    struct node *h2 = NULL;

 
    create(&h1, 6);
    display(h1);

    create(&h2, 2);
    display(h2);

    struct node *temp1 = h1;
    for (int i = 0; i < 3; i++) {
        temp1 = temp1->next;
    }
    struct node *temp2 = h2;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp1;  

    printf("Lists after joining:\n");
    display(h1);
    display(h2);

    findIntersection(h1, h2);

    return 0;
}
