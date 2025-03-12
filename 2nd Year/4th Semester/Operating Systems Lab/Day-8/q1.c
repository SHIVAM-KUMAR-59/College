// Create a thread which prints your name

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int c = 0;

void *f1(void *arg){
    
    printf("Name is: %s\n", (char *)arg);

    return NULL;
}


int main(){
    pthread_t t1;
    char name[] = "Ganesh";
    pthread_create(&t1, NULL, f1, name);
    pthread_join(t1, NULL);
    return 0;
}