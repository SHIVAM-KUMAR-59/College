// Implementing Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct node {
    int data;
    struct node *next;
};

// Queue Structure
typedef struct {
    struct node *rear;
} queue;

// Function to initialize
void init(queue *q) {
    q->rear = NULL;
}

// Function to push (enqueue)
int push(queue *q, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(!temp) {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    
    temp->data = data;
    
    if (q->rear == NULL) {
        // When queue is empty, new node points to itself
        temp->next = temp;
        q->rear = temp;
    } else {
        // Insert new node between rear and front
        temp->next = q->rear->next;
        q->rear->next = temp;
        q->rear = temp;  // Update rear pointer to the new node
    }
    
    return 0;
}

// Function to pop (dequeue)
int pop(queue *q, int *val) {
    if (q->rear == NULL) {
        printf("Queue is Empty\n");
        return 1;
    }

    struct node *temp = q->rear->next;  // The front node to be removed
    *val = temp->data;

    if (q->rear == temp) {
        // Only one element in the queue
        q->rear = NULL;
    } else {
        // Remove the front node
        q->rear->next = temp->next;
    }
    
    free(temp);
    return 0;
}

int main() {
    queue q;
    init(&q);
    
    push(&q, 10);
    push(&q, 30);
    push(&q, 20);
    push(&q, 90);

    for (int i = 0; i < 4; i++) {
        int temp;
        if (pop(&q, &temp) == 0) {
            printf("Popped Value: %d\n", temp);
        } else {
            printf("Unsuccessful\n");
        }
    }

    return 0;
}
