#include <stdio.h>
#include <pthread.h>

int i = 0;
int flag[2] = {0, 0};  
int turn = 0;          


void lock(int process_id) {
    int other = 1 - process_id;  
    flag[process_id] = 1;        
    turn = other;                
    while (flag[other] && turn == other);
}


void unlock(int process_id) {
    flag[process_id] = 0; 
}


void *fun(void *arg) {
    int process_id = *(int *)arg;
    
    for (int j = 0; j < 100000; j++) {
        lock(process_id);  
        i++;               
        unlock(process_id); 
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 0, id2 = 1; 

    pthread_create(&t1, NULL, fun, &id1);
    pthread_create(&t2, NULL, fun, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Value of i: %d\n", i);  
    return 0;
}
