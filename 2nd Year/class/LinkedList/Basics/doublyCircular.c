#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

// Function to create
void create(struct node **head, int n){
    for(int i = 0; i < n; i++){
        struct node *curr = malloc(sizeof(struct node));
        curr->data = rand() % 100;
        curr->next = curr->prev = NULL;
        if(*head == NULL){
            *head = curr->next = curr->prev = curr;
        }else{
            curr->next = *head;
            curr->prev = (*head)->prev;
            (*head)->prev->next = curr;
            (*head)->prev = curr;
        }
    }
}

// Function to insert
void insert(struct node **head, int val, int ind){
    struct node *curr = malloc(sizeof(struct node));
    curr->data = val;
    curr->next = curr->prev = NULL;
    // If no element present
    if(*head == NULL){
        *head = curr->next = curr->prev = curr;
    }else{
        // If inserting at the beginning
        if(ind == 0){
            curr->next = *head;
            curr->prev = (*head)->prev;
            (*head)->prev->next = curr;
            (*head)->prev = curr;
            *head = curr;
        }
        // Inserting at middle and end
        else{
            struct node *temp = *head;
            int i = 0;
            while(i < ind - 1 && temp->next != *head){
                temp = temp->next;
                i++;
            }
            curr->next = temp->next;
            curr->prev = temp;
            temp->next->prev = curr;
            temp->next  = curr;
        }
    }
}

// Function to delete
void delete(struct node **head, int val){
    struct node *ptr;
    if(*head == NULL){
        printf("Empty list\n");
        exit(1);
    }else{
        // Check if the node is present
        for(ptr = *head; ptr->next != *head; ptr = ptr->next){
            if(ptr->data == val){
                break;
            }
        }
        if(ptr->data != val){
            printf("Element not found\n");
            exit(1);
        }
        else{
            // If only one node present
            if(ptr->next == ptr){
                *head = NULL;
            }
            // Delete first node
            else if(ptr == *head){
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                *head = ptr->next;
            }else{
                // Delete middle and end node
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            free(ptr);
        }
    }
}
// Function to display
void display(struct node **head){
    if(*head == NULL){
        printf("The list is empty\n");
        return;
    }else{
    struct node *temp = *head;
    do{
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }while(temp != *head);
    printf("head\n");
    }
}


int main(){
    struct node *head = NULL;
    create(&head, 10);
    display(&head);
    insert(&head, 20, 0);
    display(&head);
    delete(&head, 64);
    display(&head);
    return 0;
}