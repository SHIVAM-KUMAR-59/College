// Avoid race condition using peterson's 2 person lock

#include<stdio.h>
#include<pthread.h>

int i = 0;
int flag[2] = {0, 0};
int turn;

void lock(){
    flag[0] = 1;
    
}

void *fun(void * arg){
    for(int j = 0; j < 1000; j++){
        i++;
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Value of i: %d", i);
    return 0;
}
