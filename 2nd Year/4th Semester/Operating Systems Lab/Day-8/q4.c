// WAP that creates 2 threads which increment a global variable by 1. Print the final value of the global variable. Verify race condition

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int a  = 0;

void *fun(void *arg){
    for(int i = 0; i < 1000000; i++){
        a++;
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of a: %d\n", a);
    return 0;
}