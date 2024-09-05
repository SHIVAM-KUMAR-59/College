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
        push(s, val);  // If the stack is empty, push the element to the bottom
        return;
    }
    
    int temp;
    pop(s, &temp);     // Pop the top element
    insert_Bottom(s, val); // Recursively insert the element at the bottom
    push(s, temp);     // Push the popped element back on top
}

// Recursive function to reverse the stack
void reverseStack(stack *s) {
    if (s->top == -1) {
        return;  // Base case: if the stack is empty, return
    }

    int temp;
    pop(s, &temp);         // Pop the top element
    reverseStack(s);       // Recursively reverse the remaining stack
    insert_Bottom(s, temp); // Insert the popped element at the bottom
}

// Function to display the stack
void display(stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    stack a;
    init(&a);

    // Push some elements into the stack
    push(&a, 10);
    push(&a, 50);
    push(&a, 40);
    push(&a, 30);
    push(&a, 20);

    // Display original stack
    printf("Original Stack: ");
    display(&a);

    // Reversing the stack
    reverseStack(&a);

    // Display reversed stack
    printf("Reversed Stack: ");
    display(&a);

    return 0;
}
