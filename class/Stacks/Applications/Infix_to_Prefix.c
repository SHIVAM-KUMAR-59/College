// Convert infix to prefix stacks

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Stack Structure
typedef struct{
    char arr[100];
    int top;
}stack;

// Function to initialize
void init(stack *s){
    s->top = -1;
}

// Function to push an element onto the stack
void push(stack *s1, char a) {
    if (s1->top == 99) {
        printf("Stack Overflow!\n");
        return;
    }
    s1->arr[++s1->top] = a;
}

// Function to pop an element from the stack
int pop(stack *s1, char *val) {
    if (s1->top == -1) {
        printf("Stack Underflow!\n");
        return 1;
    }
    *val = s1->arr[s1->top--];
    return 0;
}

// Function to check if a character is an operand
int is_operand(char a) {
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

// Function to check if the stack is empty
int isEmpty(stack s1) {
    return s1.top == -1;
}

// Function to get the precedence of an operator
int val(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to reverse a string
void reverse(char *c) {
    int i, j;
    int len = strlen(c);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = c[i];
        c[i] = c[j];
        c[j] = temp;
    }
    c[len] = '\0'; // Ensure the string is null-terminated
}

// Function to compare precedence
int l_to_h(char a, char b) {
    return val(a) < val(b);
}

void infix_to_prefix(char *in, char *out){
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
    out[k] = '\0';
}

int main(){
    char infix[100], prefix[100];
    printf("Enter infix expression: ");
    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    infix[strcspn(infix, "\n")] = '\0';

    reverse(infix);
    infix_to_prefix(infix, prefix);
    reverse(prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
