/*
Write a program to find the intersection of two sets(consider eachset is an array).
*/

#include <stdio.h>
#include<stdlib.h>
int main(){
    int n,m;
    printf("Enter the number of elements in the first set: ");
    scanf("%d",&n);
    printf("Enter the number of elements in the second set: ");
    scanf("%d",&m);
    
    int *a = malloc(n * sizeof(int));
    int *b = malloc(m * sizeof(int));

    printf("Enter the elements for first set: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the elements for second set: ");
    for(int i = 0; i < m; i++){
        scanf("%d",&b[i]);
    }

    printf("Intersecting elements are: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
                printf("%d ",a[i]);
            }
        }
    }
    return 0;
}