#include <stdio.h>
#include <stdlib.h>  
#include <pthread.h>

void *fun(void *arg) {
    int *data = malloc(sizeof(int));

    *data = 12;
    return data;
}

int main() {
    pthread_t t;
    int a = 8;
    int *m;

    pthread_create(&t, NULL, fun, &a);
    pthread_join(t, (void **)&m);

    printf("Value of m: %d\n", *m);

    return 0;
}
