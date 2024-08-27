#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
    printf("Random array: \n");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    // reversing
    int i = 0, j = 9;
    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    printf("\nReversed array: \n");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}