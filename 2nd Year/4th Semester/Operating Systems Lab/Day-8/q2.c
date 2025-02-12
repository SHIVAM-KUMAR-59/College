#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

struct data{
    int arr[10];
    int n;
};

int binarySearch(int arr[], int n){
    int s = 0;
    int e = 9;
    while(s <= e){
        int mid = (s + e) / 2;
        if(arr[mid] == n){
            return mid;
        }else if(arr[mid] < n){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    int a[2][2], index[2];  
    int t, first, second;

    pipe(a[0]);  
    pipe(a[1]);
    pipe(index);  

    struct data x = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3};  
    struct data y = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9}; 

    write(a[0][1], &x, sizeof(x));
    write(a[1][1], &y, sizeof(y));

    for(int i = 0; i < 2; i++){
        t = fork();
        if(t == 0){  
            struct data p;
            read(a[i][0], &p, sizeof(p));
            int found = binarySearch(p.arr, p.n);
            write(index[1], &found, sizeof(found));  
            return 0;  
        }
    } 

    read(index[0], &first, sizeof(first));
    read(index[0], &second, sizeof(second));

    printf("First: %d\n", first);
    printf("Second: %d\n", second);

    printf("Elements between indices %d and %d: ", first, second);
    for(int i = first; i <= second; i++){
        printf("%d ", x.arr[i]);
    }
    printf("\n");

    return 0;
}
