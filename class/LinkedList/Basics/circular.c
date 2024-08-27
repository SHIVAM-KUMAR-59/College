#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create Circular Linked List
void create(struct node **head, int n) {
    struct node *ptr = NULL;
    struct node *temp = NULL;

    for (int i = 0; i < n; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = rand() % 100;
        temp->next = NULL;

        if (*head == NULL) {
            *head = temp;
            temp->next = *head; 
            ptr = temp;
        } else {
            temp->next = *head;  // New node points to head
            ptr->next = temp;   // Previous node points to new node
            ptr = temp;
        }
    }
}

// Function to insert
void insert(struct node **head, int val, int ind){
    struct node *curr = malloc(sizeof(struct node));
    curr->data = val;
    curr->next = NULL;
    struct node *ptr = *head;
    // If the list is empty
    if(*head == NULL){
        *head = curr;
        curr->next = *head;
    }
    else if(ind == 0){
        for(ptr = *head; ptr->next != *head; ptr = ptr->next);
        curr->next = *head;
        *head = curr;
        ptr->next = curr;
    }else{
        int i = 0;
        ptr = *head;
        while(i < ind - 1 && ptr->next != *head){
            ptr = ptr->next;
            i++;
        }
        curr->next = ptr->next;
        ptr->next = curr;
    }
}

// Function to delete
void delete(struct node **head, int val) {
    struct node *ptr, *prev, *ptr2;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        prev = NULL;
        for (ptr = *head;ptr->next != *head ; ptr = ptr->next) {
            if (ptr->data == val) {
                break;
            }
            prev = ptr;
        }

        if (ptr->data != val) {
            printf("Element not found\n");
            return;
        } else {
            // Condition for only one element present
            if (ptr->next == ptr) {
                *head = NULL;
            } else if (ptr == *head) {
                for (ptr2 = *head; ptr2->next != *head; ptr2 = ptr2->next);
                *head = ptr->next;
                ptr2->next = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
        }
    }
}

// Function to display Circular Linked List
void display(struct node *head) {
    if (head == NULL) return;
    struct node *ptr = head;
    do {
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // Continue until we loop back to the head
    printf("head\n");  
}

int main() {
    struct node* head = NULL;
    create(&head, 10);
    display(head);
    insert(&head, 199, 0);
    display(head);
    delete(&head, 199);
    display(head);
    return 0;
}
