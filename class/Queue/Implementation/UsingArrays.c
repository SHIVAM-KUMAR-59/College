// Implementation of Queue using array

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100];
    int front;
    int rear;
} queue;

// Function to initialize
void init(queue *q) {
    q->front = q->rear = -1;
}

// Function to insert
int insert(queue *q, int val) {
    if (q->rear == 99) {  // Queue is full
        printf("Queue is full\n");
        return 1;
    } else if (q->rear == -1) {  // Queue is empty
        q->front = q->rear = 0;
    } else {  // Normal insertion
        q->rear++;
    }
    q->arr[q->rear] = val;
    return 0;
}

// Function for deletion by moving the front pointer
int delete_moveFront(queue *q, int *val) {
    if (q->front == -1) {  // Queue is empty
        printf("Queue is empty\n");
        return 1;
    }
    *val = q->arr[q->front];  // Get the front element
    if (q->front == q->rear) {  // Queue becomes empty after deletion
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return 0;
}

// Function for deletion without moving the front pointer
int delete_notMoveFront(queue *q, int *val) {
    if (q->front == -1) {  // Queue is empty
        printf("Queue is empty\n");
        return 1;
    }
    *val = q->arr[q->front];  // Get the front element
    if (q->front == q->rear) {  // Queue becomes empty after deletion
        q->front = q->rear = -1;
    } else {
        for (int i = q->front + 1; i <= q->rear; i++) {
            q->arr[i - 1] = q->arr[i];  // Shift elements to the left
        }
        q->rear--;  // Decrement rear after shifting
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
