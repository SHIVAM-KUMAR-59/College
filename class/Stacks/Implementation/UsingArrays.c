
// Implementation of stack using Arrays
#include <stdio.h>
#include <stdlib.h>

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

int main() {
    stack a;
    init(&a);
    push(&a, 10);

    int b;
    if (pop(&a, &b) == 0) {
        printf("Popped value: %d\n", b);
    }
    return 0;
}
