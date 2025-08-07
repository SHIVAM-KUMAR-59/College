#include<stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[10];
    printf("Enter 10 elements into the array:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:\n");
    printArray(arr, 10);

    insertionSort(arr, 10);

    printf("Sorted array in ascending order:\n");
    printArray(arr, 10);

    return 0;
}

