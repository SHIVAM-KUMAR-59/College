
#include <stdio.h>
#include <pthread.h>

void *fun(void *arg){
    pthread_t t;
    int a = *((int *)arg);
    int b = a / 2;
    printf("Value in fun: %d\n", a);
    if(b > 0){
        for(int i = 0; i < b; i++){
            pthread_create(&t, NULL, fun, &b);
            pthread_join(t, NULL);
        }
        
    }
    
    return NULL;
}

int main(){

    pthread_t  t;
    int a = 8;
    pthread_create(&t, NULL, fun, &a);
    pthread_join(t, NULL);
    return 0;
}