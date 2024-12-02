#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to insert
void insert(struct node **head, int val, int ind){
    struct node *curr = malloc(sizeof(struct node));
    curr->data = val;
    curr->next = NULL;
    // If no element is present
    if(*head == NULL){
        curr = *head;
    }else{
        // If the index is 0
        if(ind == 0){
            curr->next = *head;
            *head = curr;
        }else{
            struct node *temp = *head;
            int i = 0;
            while(i < ind - 1 && temp->next != NULL){
                temp = temp->next;
            }
            // If the temp is at the last position
            if(temp->next == NULL){
                temp->next = curr;
            }else{
                curr->next = temp->next;
                temp->next = curr;
            }
        }
    }
}

// Function to delete
void delete(struct node **head, int val) {
    // If the list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        exit(1);
    } else {
        struct node *temp = *head;
        struct node *prev = NULL;

        // If the head node itself holds the value to be deleted
        if (temp != NULL && temp->data == val) {
            // If there's only one node in the list
            if (temp->next == NULL) {
                *head = NULL;
            } else {
                *head = temp->next; 
            }
            free(temp); 
        } else {
            // Traverse the list to find the node to delete
            while (temp != NULL && temp->data != val) {
                prev = temp;
                temp = temp->next;
            }

            // If the element was not found
            if (temp == NULL) {
                printf("Element not found\n");
                exit(1);
            } else {
                // If the element is in the middle or end of the list
                if (temp->next != NULL) {
                    prev->next = temp->next;  // Unlink the node from the list
                } else {
                    prev->next = NULL;  // Unlink the last node
                }
                free(temp); 
            }
        }
    }
}

// Function to create
void create(struct node **head, int n){
    for(int i = 0; i < n ; i++){
        struct node *curr = malloc(sizeof(struct node));
        curr->data = rand() % 100;
        curr->next = NULL;
        if(*head == NULL){
            *head = curr;
        }else{
            struct node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
    }
}


// Function to display
void display(struct node *head) {
    struct node *temp = head;
    printf("\nThe Linked List is:\n");
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("Linked List Terminated\n"); // Indicates the end of the linked list
}

int main() {
    struct node* head = NULL;
    create(&head, 10);
    display(head);
    insert(&head, 10, 10);
    display(head);
  
 

    return 0;
}
