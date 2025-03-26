// Avoid race condition using semaphore

/**
 * sem_init(&st, 0, 1)
 * 1 --> binary semaphore / counting semaphore
 * 0 --> All the thread belong to same process can only use the semaphore, if more than 0 then other process's threads can access the semaphore
 */
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int i = 0;

sem_t st;

void *fun(void *arg){
    int j;
    for(j = 0; j < 100000; j++){
        // Lock
        sem_wait(&st);
        i++;
        // Unlock
        sem_post(&st);
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;
    sem_init(&st, 0, 1);
    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Value of i: %d\n", i);
    return 0;
}