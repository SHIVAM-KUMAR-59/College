#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

struct Number{
    int a;
    int b;
    char operation;
};

int main(){
    struct Number n;
    int a[2];
    pipe(a);
    n.a = 5;
    n.b = 7;
    n.operation = '+';

    int t = fork();
    if(t > 0){
        write(a[1], &n, sizeof(struct Number));
    }else{
        struct Number p;
        read(a[0], &p, sizeof(struct Number));
        printf("%d\n", p.a);
        printf("%d\n", p.b);
        printf("%c\n", p.operation);
        printf("%d\n", p.a + p.b);
    }

    return 0;
}