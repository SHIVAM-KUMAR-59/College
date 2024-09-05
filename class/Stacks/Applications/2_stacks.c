#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top[2];  // top[0] for Stack 0, top[1] for Stack 1
} stack;

// Function to initialize
void init(stack *s) {
    s->top[0] = -1;       // Stack 0 starts from the left
    s->top[1] = MAX;      // Stack 1 starts from the right
}

// Function to push
int push(stack *s, int val, int a) {
    if (s->top[0] + 1 == s->top[1]) {
        printf("Stack Overflow\n");
        return 1;
    }
    s->arr[(a == 0) ? ++s->top[0] : --s->top[1]] = val;
    return 0;
}

// Function to pop
int pop(stack *s, int *val, int a) {
    if ((a == 0 && s->top[0] == -1) || (a == 1 && s->top[1] == MAX)) {
        printf("Stack Underflow\n");
        return 1;
    }
    *val = s->arr[(a == 0) ? s->top[0]-- : s->top[1]++];
    return 0;
}

// Test the 2-stack implementation
int main() {
    stack s;
    int val;

    init(&s);

    // Push into Stack 0
    push(&s, 10, 0);
    push(&s, 20, 0);

    // Push into Stack 1
    push(&s, 100, 1);
    push(&s, 200, 1);

    // Pop from Stack 0
    pop(&s, &val, 0);
    printf("Popped from Stack 0: %d\n", val);

    // Pop from Stack 1
    pop(&s, &val, 1);
    printf("Popped from Stack 1: %d\n", val);

    return 0;
}
