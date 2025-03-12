// WAP that creates 2 threads which take 2 integer and an operator from parent process and perform the operation and return the result to the parent process.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct data{
    int a, b;
    char op;
};

void *fun(void *arg){
    struct data *d = (struct data *)arg;
    int a = d->a;
    int b = d->b;
    char op = d->op;
    int res;
    switch(op){
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
    }
    printf("Result is: %d\n", res);
    return NULL;
}

int main(){
    struct data d1 = {1, 5, '+'};

    pthread_t t1, t2;
    pthread_create(&t1, NULL, fun, &d1);
    pthread_join(t1, NULL);
    return 0;
}