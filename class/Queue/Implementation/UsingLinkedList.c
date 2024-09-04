#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Queue structure
typedef struct {
    struct node* front;
    struct node* rear;
} queue;

// Function to initialize the queue
void init(queue* q) {
    q->front = q->rear = NULL;
}

// Function to insert an element into the queue
int insert(queue* q, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {  // Memory allocation failed
        printf("Memory allocation failed\n");
        return 1;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {  // Queue is empty
        q->front = q->rear = newNode;
    } else {  // Normal insertion
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return 0;
}

// Function for deletion by moving the front pointer
int delete_moveFront(queue* q, int* val) {
    if (q->front == NULL) {  // Queue is empty
        printf("Queue is empty\n");
        return 1;
    }
    struct node* temp = q->front;
    *val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {  // Queue becomes empty after deletion
        q->rear = NULL;
    }

    free(temp);
    return 0;
}

// Function for deletion without moving the front pointer
int delete_notMoveFront(queue* q, int* val) {
    if (q->front == NULL) {  // Queue is empty
        printf("Queue is empty\n");
        return 1;
    }
    struct node* temp = q->front;
    *val = temp->data;

    if (q->front == q->rear) {  // Only one element in the queue
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        *val = temp->next->data;  // Update val to the data of the rear node
        free(temp->next);
        temp->next = NULL;
        q->rear = temp;
    }

    return 0;
}

int main() {
    queue q;
    init(&q);

    insert(&q, 15);
    insert(&q, 25);
    insert(&q, 35);

    int a, b;
    delete_moveFront(&q, &a);
    delete_notMoveFront(&q, &b);

    printf("Deletion by moving front: %d\n", a);
    printf("Deletion without moving front: %d\n", b);

    return 0;
}
