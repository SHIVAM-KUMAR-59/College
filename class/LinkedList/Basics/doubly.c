#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node *prev;
};

// Function to create the list
void create(struct node **head, int n){
    for(int i = 0; i < 10; i++){
        struct node *curr = malloc(sizeof(struct node));
        curr->data = rand()%100;
        curr->next = curr->prev = NULL;
        if(*head == NULL){
            *head = curr;
        }else{
            curr->next = *head;
            (*head)->prev = curr;
            *head = curr;
        }
    }
}

// Function to insert the node at any index
void insert(struct node **head, int index, int data){
    struct node *curr = malloc(sizeof(struct node));
    curr->data = data;
    curr->next = curr->prev = NULL;
    if(*head == NULL){ // No element is present
        *head = curr;
    }else{
        if(index == 0){ // Only 1 element is present
            curr->next = *head;
            (*head)->prev = curr;
            *head = curr;
        }else{
            struct node *temp = *head;
            int i = 0;
            while(i < index - 1 && temp->next != NULL){
                temp = temp->next;
                i++;
            }
            if(temp->next == NULL){ // Insertion at last position
                temp->next = curr;
                curr->prev = temp;
            }else{ // Insertion in the middle
                curr->next = temp->next;
                curr->prev = temp;
                temp->next->prev = curr;
                temp->next = curr;
            }
        }
    }
}

// Function to delete at any index
void delete(struct node **head, int val) {
   // If no node is present
   if (*head == NULL) {
    printf("List is empty\n");
   }else{
    struct node *temp;
    for(temp = *head; temp != NULL; temp = temp->next){
        if(temp->data == val){
            break;
        }
    }
    // If value not found
    if(temp == NULL){
        printf("Value not found in the list\n");
    }
    else if(temp == *head && temp->next == NULL){
        // If only one element is present
        *head = NULL;
        free(temp);
    }
    else if((*head)->prev == NULL){
        // If head is to be deleted
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
    }
    else if(temp->next == NULL){
        // If last element is to be deleted
        temp->prev->next = NULL;
        free(temp);
    }
    else{
        // If middle element is to be deleted
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
   }
}

// Function to search in the list
int search(struct node *head, int key) {
    struct node *temp = head;
    while(temp->next != NULL){
        if(temp->data == key){
            return 1;
    }
    }
}
// Function to display the list
void display(struct node *head){
    struct node *temp = head;
    printf("The Linked List is:\n");
    while(temp ->next != NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("Linked List Terminated\n");
}

int main(){
    struct node* head = NULL;
    struct node* prev = NULL;
    create(&head, 10);
    display(head);
    insert(&head, 0, 100);
    insert(&head, 3, 300);
    insert(&head, 10, 400);
    insert(&head, 10, 500);
    insert(&head, 10, 600);
    display(head);
    head->next = head->next->next->next;
    head->next->next->next->prev = head;
    // printf("%d\n", *head->next->next->next->next->prev);
    display(head);
    return 0;
}