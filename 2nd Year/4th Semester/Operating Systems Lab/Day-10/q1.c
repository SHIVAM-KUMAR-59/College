// Avoid race condition using mutex

/**
 * sem_init(&st, 0, 1)
 * 1 --> binary semaphore / counting semaphore
 * 0 --> All the thread belong to same process can only use the semaphore, if more than 0 then other process's threads can access the semaphore
 */
#include<stdio.h>
#include<pthread.h>

int i = 0;

pthread_mutex_t pt; // Declaring a lock variable or sem_t st;

void *fun(void *arg){
    int j;
    for(j = 0; j < 100000; j++){
        // Lock
        pthread_mutex_lock(&pt); // sem_wait(&st)
        i++;
        // Unlock
        pthread_mutex_unlock(&pt); // sem_post(&pt)
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;
    pthread_mutex_init(&pt, NULL); // Initialize a lock or sem_init(&st, 0, 1)
    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Value of i: %d\n", i);
    return 0;
}