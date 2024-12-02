// Reverse a Linked list recursively

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void Reverse(struct node **head) {
    // Base case: if the list is empty or only one node, return
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Recursively reverse the rest of the list
    struct node *rest = (*head)->next;
    Reverse(&rest);

    // Adjust the next pointers
    (*head)->next->next = *head;  // Make the next node point to the current head
    (*head)->next = NULL;         // Make the current head point to NULL

    // Move the head pointer to the new first node
    *head = rest;
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

int main(){
    struct node *head = NULL;
    create(&head, 5);
    display(head);
    Reverse(&head);
    display(head);
    return 0;
}