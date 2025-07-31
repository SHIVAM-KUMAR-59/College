// Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. Store the binary value in a separate disc file.

#include<stdio.h>
#include<stdlib.h>

void decimalToBinary(int num, char *binary, int index) {
    if(index < 0) {
        return;
    }

    binary[index] = (num % 2) + '0';
    decimalToBinary(num / 2, binary, index - 1);
}
int main(int count, char *args[]) {
    int n = atoi(args[1]);
    printf("Decimal number: %d\n", n);
    char binary[32];
    decimalToBinary(n, binary, 31);
    printf("Binary number: %s\n", binary);
    return 0;
}
