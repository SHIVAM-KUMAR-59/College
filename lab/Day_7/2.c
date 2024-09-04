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


int main() {
    stack a;  
    init(&a); 
    push(&a, 10);
    push(&a, 20);
    push(&a, 30);
    push(&a, 40);
    // Popping the value
    int val;
    if (pop(&a, &val) == 0) {
        printf("Popped Value: %d\n", val);
    }
    return 0;
}
