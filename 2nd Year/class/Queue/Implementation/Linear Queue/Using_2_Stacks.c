// Implement queue using two stacks

#include<stdio.h>
#include<stdbool.h>

// Basic stack structure
typedef struct {
    int arr[100];
    int top;
} stack;

// Function to initialize the stack
void init(stack *a) {
    a->top = -1;
}

// Function to push into a stack
int push(stack *a, int val) {
    if (a->top == 99) {
        printf("Stack Overflow!\n");
        return 1;
    }
    a->arr[++a->top] = val;
    return 0;
}

// Function to pop from a stack
int pop(stack *a, int *v) {
    if (a->top == -1) {
        printf("Stack Underflow!\n");
        return 1;
    }
    *v = a->arr[a->top--];
    return 0;
}

// Function to check whether stack is empty
bool isEmpty(stack *s) {
    return s->top == -1;
}

// Function to perform insert operation in queue (enqueue)
void insert(int val, stack *s1) {
    push(s1, val);
}

// Function to perform delete operation in queue (dequeue)
int delete(int *val, stack *s1, stack *s2) {
    // If both stacks are empty, queue is empty
    if (isEmpty(s1) && isEmpty(s2)) {
        printf("Queue is empty\n");
        return 1;
    }
    
    // If s2 is empty, transfer elements from s1 to s2
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            int temp;
            pop(s1, &temp);
            push(s2, temp);
        }
    }

    // Pop from s2 to get the front of the queue
    pop(s2, val);
    return 0;
}

// Global stacks for queue implementation
stack s1, s2;

int main() {
    // Initialize the stacks
    init(&s1);
    init(&s2);

    // Insert (enqueue) elements
    insert(10, &s1);
    insert(20, &s1);
    insert(30, &s1);
    
    // Delete (dequeue) elements and print the values
    int val;
    if (delete(&val, &s1, &s2) == 0) {
        printf("Deleted: %d\n", val);
    }
    
    if (delete(&val, &s1, &s2) == 0) {
        printf("Deleted: %d\n", val);
    }

    if (delete(&val, &s1, &s2) == 0) {
        printf("Deleted: %d\n", val);
    }


    return 0;
}
