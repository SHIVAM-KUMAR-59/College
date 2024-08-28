#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int arr[100];
    int top;
}stack;

// Function to initialize
void init(stack *a){
    a->top = -1;
}

// Function to push into a stack
int push(stack *a, int val){
    if(a->top == 100){
        printf("Stack Overflow!\n");
        return 1;
        exit(1);
    }
    a->arr[++a->top] = val;
    return 0;
}

int main(){
    stack a;
    init(&a);
    push(&a, 10);
}
