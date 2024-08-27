
// WAP to create display, create, insert and delete functions in a Single Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Function to create the linked list
void create(struct node **head){
    for(int i = 0; i < 5 ; i++){
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

// Function to insert
void insert(struct node **head, int val, int ind) {
    // Allocate memory for the new node
    struct node *curr = malloc(sizeof(struct node));
    if (curr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    curr->data = val;
    curr->next = NULL;

    // If no element is present in the list
    if (*head == NULL) {
        *head = curr;
    } else {
        // If the index is 0 
        if (ind == 0) {
            curr->next = *head;
            *head = curr;
        } else {
            struct node *temp = *head;
            int i = 0;
            while (i < ind - 1 && temp->next != NULL) {
                temp = temp->next;
                i++;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }
}

// Function to delete
void delete(struct node **head, int val) {
    if (*head == NULL) {
        printf("List is empty\n");
        exit(1);
    } else {
        struct node *temp = *head, *prev = NULL;

        // Traverse the list to find the node to delete
        for (temp = *head; temp != NULL; temp = temp->next) {
            if (temp->data == val) {
                break;
            }
            prev = temp;
        }

        // If value not found
        if (temp == NULL) {
            printf("Element not found\n");
            exit(1);
        }

        // If only one node is present
        if (temp->next == NULL && temp == *head) {
            *head = NULL;
        } else if (temp == *head) { // first node deletion
            *head = temp->next;
        } else { // Delete node from middle or end
            prev->next = temp->next;
        }

        free(temp);
    }
}



// Function to display
void display(struct node **head){
    struct node *temp = *head;
    while(temp != NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("Linked list Terminated\n");
}

int main(){
    struct node *head = NULL;
    create(&head);
    display(&head);
    insert(&head, 100, 0);
    display(&head);
    delete(&head, 100);
    display(&head);
    return 0;
}