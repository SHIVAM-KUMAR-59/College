#include<stdio.h>
#include<stdlib.h>

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

// Function to insert at bottom
void insert_Bottom(stack *s, int val) {
    if (s->top == -1) {
        push(s, val);  // Base case: push when the stack is empty
        return;
    }

    int temp;
    pop(s, &temp);        // Pop the top element
    insert_Bottom(s, val); // Recursive call to insert at the bottom
    push(s, temp);        // Push the previously popped element back
}

void display(stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    stack a;
    init(&a);

    // Push some elements
    push(&a, 20);
    push(&a, 30);
    push(&a, 40);

    printf("Stack before insertion at bottom: ");
    display(&a);

    // Insert 10 at the bottom of the stack
    insert_Bottom(&a, 10);

    printf("Stack after insertion at bottom: ");
    display(&a);

    return 0;
}
