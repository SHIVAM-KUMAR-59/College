
// Implement Double Ended Queue (DEQ) using a Linear queue
#define MAX 100 // Define the maximum size of the deque
#include<stdio.h>
#include<stdlib.h>

// Define the structure for the Double Ended Queue (DEQ)
typedef struct {
    int arr[MAX]; // Array to store elements
    int front, rear; // Indices for front and rear of the deque
} DQ;

// Function to initialize the deque by setting front and rear to -1
void init(DQ *q){
    q->front = q->rear = -1;
}

// Function to insert an element into the deque
// Takes the deque pointer, value to insert, and side ('F' for front, 'R' for rear)
int enqueue(DQ *q, int val, char side){
    // If the deque is full, return an error
    if(q->front == 0 && q->rear == MAX - 1){
        printf("Queue is full\n");
        return 1;
    }

    // If the deque is empty, initialize front and rear to 0
    if(q->front == -1){
        q->front = q->rear = 0;
    }

    // Insertion at the rear
    if(side == 'R'){
        // If there's space at the rear, move rear forward
        if(q->rear != MAX - 1){
            q->rear++;
        } else { 
            // If rear is at MAX, shift elements left and adjust front
            for(int i = q->front ; i <= q->rear ; i++){
                q->arr[i - 1] = q->arr[i];
            }
            q->front--; // Decrement front
        }
        q->arr[q->rear] = val; // Insert value at rear
    }

    // Insertion at the front
    if(side == 'F'){
        // If there's space at the front, move front backward
        if(q->front != 0){
            q->front--;
        } else { 
            // If front is at 0, shift elements right and adjust rear
            for(int i = q->rear ; i >= q->front ; i--){
                q->arr[i + 1] = q->arr[i];
            }
            q->rear++; // Increment rear
        }
        q->arr[q->front] = val; // Insert value at front
    }
    return 0;
}

// Function to delete an element from the deque
// Takes the deque pointer, pointer to store the deleted value, and side ('F' for front, 'R' for rear)
int dequeue(DQ *q, int *val, char side){
    // If the deque is empty, return an error
    if(q->front == -1){
        printf("Queue is Empty\n");
        return 1;
    }

    // Store the value to be deleted
    *val = q->arr[(side == 'F') ? q->front : q->rear];

    // If there's only one element, reset the deque
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }

    // Dequeue from the front
    if(side == 'F'){
        q->front++; // Move front forward
    } else { 
        // Dequeue from the rear
        q->rear--; // Move rear backward
    }
    return 0;
}

int main(){
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
    if(val1){
        printf("Deleted value from the front: %d \n", val1);
    }

    if(val2){
        printf("Deleted value from the rear: %d ", val2);
    }
    
    return 0;
}
