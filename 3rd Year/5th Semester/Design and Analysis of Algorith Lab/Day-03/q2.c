#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	int leftArray[n1], rightArray[n2];
	for(int i = 0; i < n1; i++){
        leftArray[i] = arr[left + i];
    }
    
    for(int j = 0; j < n2; j++){
        rightArray[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(leftArray[i] <= rightArray[j]){
            arr[k++] = leftArray[i++];
        }
        else{
            arr[k++] = rightArray[j++];
        }
    }

    while(i < n1){
        arr[k++] = leftArray[i++];
    }

    while(j < n2){
        arr[k++] = rightArray[j++];
    }
}


void mergeSort(int arr[], int left, int right){
	if(left < right){
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		
		merge(arr, left, mid, right);
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

    mergeSort(arr, 0, 9);

    printf("Sorted array in ascending order:\n");
    printArray(arr, 10);

    return 0;
}

