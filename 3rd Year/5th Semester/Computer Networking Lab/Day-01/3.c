// WAP to extract each byte from a given number and store them in separate character variable and print content of those variables

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a;
    printf("Enter the number:\n");
    scanf("%d", &a);
    char arr[256] = (bytes)(a);
    printf("%s", arr);
    
    return 0;
}