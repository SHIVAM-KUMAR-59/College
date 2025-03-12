#include <stdio.h>
#include <pthread.h>

#define N 8
int arr[N] = {38, 27, 43, 3, 9, 82, 10, 1};

void merge(int low, int mid, int high) {
    int temp[N];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];

    for (i = low; i <= high; i++) arr[i] = temp[i];
}

void* mergeSort(void* arg) {
    int *range = (int*)arg;
    int low = range[0];
    int high = range[1];

    if (low < high) {
        int mid = (low + high) / 2;

        pthread_t leftThread, rightThread;
        int leftParams[2] = {low, mid};
        int rightParams[2] = {mid + 1, high};

        pthread_create(&leftThread, NULL, mergeSort, leftParams);
        pthread_create(&rightThread, NULL, mergeSort, rightParams);

        pthread_join(leftThread, NULL);
        pthread_join(rightThread, NULL);

        merge(low, mid, high);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    int params[2] = {0, N - 1};

    pthread_create(&thread, NULL, mergeSort, params);
    pthread_join(thread, NULL);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
