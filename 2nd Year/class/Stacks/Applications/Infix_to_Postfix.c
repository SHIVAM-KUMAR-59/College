// Conversion from infix to postfix

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char arr[100];
    int top;
}stack;

void init(stack *a){
    a->top = -1;
}

// Function to push
void push(stack *s1, char a){
    if(s1->top == 99){
        printf("Stack Overflow!\n");
        return;
    }
    s1->arr[++s1->top] = a;
}

// Function to pop
int pop(stack *s1, char *val){
    if(s1->top == -1){
        printf("Stack Underflow!\n");
        return 1;
    }
    else{
        *val = s1->arr[s1->top--];
        return 0;
    }
}

// is_operand Function
int is_operand(char a){
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
        return 1;
    } else{
        return 0;
    }
}

// Function to check if stack is empty
int isEmpty(stack s1){
    return s1.top == -1;
}

// val Function
int val(char c){
    int p;
    switch(c){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    }
}

// l_to_h Function
int l_to_h(char a, char b){
    if(val(a) < val(b)){
        return 1;
    }else{
        return 0;
    }
}



void infix_to_postfix(char *in, char *out){
    stack s;
    init(&s);
    int i = 0, k = 0;
    char temp;
    while(in[i] != '\0'){
        if(is_operand(in[i])){
            out[k++] = in[i];
        }else if(in[i] == '('){
            push(&s, in[i]);
        }else if(in[i] == ')'){
            while(1){
                pop(&s, &temp);
                if(temp == '('){
                    break;
                }else{
                    out[k++] = temp;
                }
            }
        }else{
            if(isEmpty(s)){
                push(&s, in[i]);
            }else{
                pop(&s, &temp);
                if(temp == '('){
                    push(&s, '(');
                    push(&s, in[i]);
                }else if(l_to_h(temp, in[i])){
                    push(&s, temp);
                    push(&s, in[i]);
                }else{
                    out[k++] = temp;
                    i--;
                }
            }
        }
        i++;
    }

    // Popping the remaining elements
    while(!isEmpty(s)){
        pop(&s, &temp);
        out[k++] = temp;
    }
}

int main(){
    char infix[100], postfix[100] = {0};
    printf("Enter the infix expression: ");
    gets(infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix: ");
    printf("%s", postfix);
    return 0;
}