// WAP that creates 2 threads which display 1 to certain number based on the number that you have passed as an argument to that thread

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun1(void * arg){
    int start = 1;
    int end = *((int *)arg);
    for(int i = start; i <= end; i++){
        printf("%d\n", i);
    }
    return NULL;
}

int main(){

    int end = 10;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, fun1, &end);
    pthread_create(&t2, NULL, fun1, &end);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}