//Implementation of stacks using queue

#define MAX 100

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int arr[MAX];
    int front, rear;
} queue;


// Global variables
queue q[2];
int ac = 0;

// Initialize queue
void init(queue *q) {
    q->front = q->rear = -1;
}

// Insert an element into the queue
int insert(queue *q, int val) {
    if (q->rear == MAX - 1) {  // Queue is full
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

// Delete an element from the queue
int delete(queue *q, int *val) {
    if (q->front == -1) {
        printf("Queue Underflow\n");
        return 1;
    }

    *val = q->arr[q->front];

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

// Push an element onto the stack
void push(int val) {
    insert(&q[ac], val);
}

// Check if the queue is empty
bool isEmpty(queue *q) {
    return q->front == -1;
}

// Pop an element from the stack
int pop(int *val) {
    if (isEmpty(&q[ac])) {
        printf("Stack Underflow\n");
        return 1;
    }
    int temp;
    while (!(isEmpty(&q[ac]))) {
        delete(&q[ac], &temp);
        if (isEmpty(&q[ac])) {
            *val = temp;
            break;
        }
        insert(&q[(ac + 1) % 2], temp);
    }
    ac = (ac + 1) % 2;
    return 0;
}



int main() {
    init(&q[0]);
    init(&q[1]);

    push(10);
    int res;
    if (pop(&res) == 0) {
        printf("Popped Value: %d\n", res);
    }

    return 0;
}
