// Write a program in C to find GCD of two numbers using recursion.

#include<stdio.h>
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    printf("Enter the number of pairs: ");
    scanf("%d", &n);
    int arr[n * 2];
    printf("Enter the pairs: ");
    for(int i = 0; i < n * 2; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("All the pairs\n");
    for(int i = 0; i < n * 2; i += 2) {
        printf("GCD of %d and %d is: %d\n", arr[i], arr[i + 1], gcd(arr[i], arr[i + 1]));
    }
    return 0;
}