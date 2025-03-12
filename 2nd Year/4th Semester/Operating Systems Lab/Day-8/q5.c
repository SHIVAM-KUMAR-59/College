// WAP that creates 4 threads. The parent divides an integer array into 4 parts and share lower and upper index and the threads will calculate the sum of all elements of the respective subarray, finally the parent process will add their value

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int sum = 0;

void *fun(void *arg){
    int *range = ((int *)arg);
    printf("Start %d, End %d\n", range[0], range[1]);
    // int sum = 0;
    for(int i = range[0]; i <= range[1]; i++){
        sum += arr[i];
        // printf("%d\n", sum);
    }
    return NULL;
}

int main(){
    int first_partition[] = {0, 3};
    int second_partition[] = {4, 7};
    int third_partition[] = {8, 11};
    int fourth_partition[] = {12, 15};

    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, NULL, fun, first_partition);
    pthread_create(&t2, NULL, fun, second_partition);
    pthread_create(&t3, NULL, fun, third_partition);
    pthread_create(&t4, NULL, fun, fourth_partition);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("%d\n", sum);

    return 0;

}