// WAP to swap the content of 2 variables entered through command line using function and pointers
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main(int count, char *args[]) {
    int a = atoi(args[1]);
    int b = atoi(args[2]);
    printf("First number before swapping: %d\n", a);
    printf("Second number before swapping: %d\n", b);
    swap(&a, &b);
    printf("First number after swapping: %d\n", a);
    printf("Second number after swapping: %d\n", b);
    return 0;
}