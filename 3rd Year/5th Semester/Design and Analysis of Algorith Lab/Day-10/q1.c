#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 
    
    for(int j = low; j < high; j++) {
    
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int randomPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = randomPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));
    
    int n;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Entered array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    randomizedQuickSort(arr, 0, n - 1);
    
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}