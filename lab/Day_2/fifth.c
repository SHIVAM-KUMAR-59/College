#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter rows: \n");
    scanf("%d", &n);
    int **a = calloc(n, sizeof(int *));
    for(int i = 0; i < n; i++){
        a[i] = calloc(i+1,sizeof(int));
        for(int j = 0; j <= i; j++){
            a[i][j] = rand() % 100;
        }
    }
    printf("Matrix: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            printf("%d ", *(a[i]+j));
        }
        printf("\n");
    }
    free(a);
    return 0;
}