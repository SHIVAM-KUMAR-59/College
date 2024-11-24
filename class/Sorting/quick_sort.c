#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int i, int j){
    int l = i, u = j, pivot = arr[i];
    while(l < u){
        while(l < j && arr[i] <= pivot){
            l++;
        }
        while(arr[u] > pivot){
            u--;
        }

        if(l < u){
            int temp = arr[l];
            arr[l] = arr[u];
            arr[u] = temp;
        }
    }
    int temp = arr[i];
    arr[i] = arr[u];
    arr[u] = temp;
    return u;
}

void quick_sort(int arr[], int l, int h){
    if(l < h){
        int pivot = partition(arr, l, h);
        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, h);
    }
}


int main(){
    int arr[] = {1,3,2,4,6,5,9,8,21,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}