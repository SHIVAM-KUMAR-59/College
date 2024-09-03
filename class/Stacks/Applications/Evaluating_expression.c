
/*
Infix to Postfix

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char arr[100];
    int *top;
}stack;

void init(stack *a){
    a->top = 0;
}

int main(){
    stack a;
    init(&a);
    return 0;
}