#include <stdio.h>
#include <pthread.h>

void *fun(void *arg) {
    int a = *((int *)arg);

    for (int i = 0; i < 8 / a; i++) {
        printf("%d\n", a);
    }

    if (a > 1) {
        pthread_t t;
        int b = a / 2;
        pthread_create(&t, NULL, fun, &b);
        pthread_join(t, NULL); 
    }

    return NULL;
}

int main() {
    pthread_t t;
    int a = 8;

    pthread_create(&t, NULL, fun, &a);
    pthread_join(t, NULL);

    return 0;
}
