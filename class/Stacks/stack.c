#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int arr[100];
    int top;
}STACK;

// Function to initialize
void init(STACK *a){
    a->top = -1;
}

// Function to push into a stack
int push(STACK *a, int val){
    if(a->top == 100){
        printf("Stack Overflow!\n");
        return 1;
        exit(1);
    }
    a->arr[++a->top] = val;
    return 0;
}

int main(){
    STACK a;
    init(&a);
    push(&a, 10);
}
