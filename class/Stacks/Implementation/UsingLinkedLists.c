// Implementation of stacks using linked list

#include <stdio.h>
#include <stdlib.h>

// Structure for nodes
struct node {
    int data;
    struct node *next;
};

// Structure for stacks
typedef struct {
    struct node *top;
    int count;
} stack;

// Function to initialize the stack
void init(stack *s) {
    s->top = NULL;
    s->count = 0;
}

// Function to push onto the stack
int push(stack *s, int val) {
    if (s->count == 5) {
        printf("Stack Overflow!\n");
        return 1;
    }
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    if (curr == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }
    curr->data = val;
    curr->next = s->top;
    s->top = curr;
    s->count++;
    return 0;
}

// Function to pop and return the value
int pop(stack *s, int *val) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return 1;
    }
    struct node *temp = s->top;
    *val = temp->data;
    s->top = s->top->next;
    s->count--;
    return 0;
}

// Function to pop and return a node
int popNode(stack *s, struct node **result) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return 1;
    }
    *result = s->top;
    s->top = s->top->next;
    s->count--;
    return 0;
}

int main() {
    stack a;  // Declare the stack object
    init(&a); // Initialize the stack object
    push(&a, 10); // Pushing 10 into the stack

    // Popping the value
    int val;
    if (pop(&a, &val) == 0) {
        printf("Popped Value: %d\n", val);
    }

    // Popping the node
    struct node *result;
    if (popNode(&a, &result) == 0) {
        printf("Popped Node Data: %d\n", result->data);
        // Free the popped node's memory
        free(result);
    }

    return 0;
}
