#define MAX 100 // Define the maximum size of the deque
#include<stdio.h>
#include<stdlib.h>

// Define the structure for the Circular Double Ended Queue (DEQ)
typedef struct {
    int arr[MAX]; // Array to store elements
    int front, rear; // Indices for front and rear of the deque
} DQ;

// Function to initialize the deque by setting front and rear to -1
void init(DQ *q) {
    q->front = q->rear = -1;
}

// Function to check if the deque is full
int isFull(DQ *q) {
    return ((q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1 + MAX) % MAX));
}

// Function to check if the deque is empty
int isEmpty(DQ *q) {
    return (q->front == -1);
}

// Function to insert an element into the deque
// Takes the deque pointer, value to insert, and side ('F' for front, 'R' for rear)
int enqueue(DQ *q, int val, char side) {
    // If the deque is full, return an error
    if (isFull(q)) {
        printf("Queue is full\n");
        return 1;
    }

    // If the deque is empty, initialize front and rear to 0
    if (q->front == -1) {
        q->front = q->rear = 0;
    }
    // Insertion at the rear
    else if (side == 'R') {
        // Circular increment of rear
        q->rear = (q->rear + 1) % MAX;
    }
    // Insertion at the front
    else if (side == 'F') {
        // Circular decrement of front
        q->front = (q->front - 1 + MAX) % MAX;
    }

    // Insert the value at the appropriate position
    q->arr[(side == 'R') ? q->rear : q->front] = val;

    return 0;
}

// Function to delete an element from the deque
// Takes the deque pointer, pointer to store the deleted value, and side ('F' for front, 'R' for rear)
int dequeue(DQ *q, int *val, char side) {
    // If the deque is empty, return an error
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return 1;
    }

    // Store the value to be deleted
    *val = q->arr[(side == 'F') ? q->front : q->rear];

    // If there's only one element, reset the deque
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    // Dequeue from the front
    else if (side == 'F') {
        // Circular increment of front
        q->front = (q->front + 1) % MAX;
    }
    // Dequeue from the rear
    else {
        // Circular decrement of rear
        q->rear = (q->rear - 1 + MAX) % MAX;
    }

    return 0;
}

int main() {
    DQ q; // Declare a deque object
    init(&q); // Initialize the deque

    // Insert elements into the deque from both front and rear
    enqueue(&q, 10, 'F');
    enqueue(&q, 100, 'R');
    enqueue(&q, 30, 'F');
    enqueue(&q, 300, 'R');
    enqueue(&q, 20, 'F');
    enqueue(&q, 200, 'R');
    enqueue(&q, 400, 'R');

    int val1, val2; // Variables to hold deleted values

    // Delete elements from both front and rear
    dequeue(&q, &val1, 'F');
    dequeue(&q, &val2, 'R');

    // Print the values deleted from front and rear
    if(val1) {
        printf("Deleted value from the front: %d \n", val1);
    }

    if(val2) {
        printf("Deleted value from the rear: %d ", val2);
    }

    return 0;
}
