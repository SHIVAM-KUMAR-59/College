// WAP to extract each byte from a given number and store them in separate character variable and print content of those variables

#include <stdio.h>

int main() {
    int num;
    char byte1, byte2, byte3, byte4;

    printf("Enter an integer: ");
    scanf("%u", &num);

    byte1 = (num & 0x000000FF);
    byte2 = (num >> 8) & 0x000000FF;
    byte3 = (num >> 16) & 0x000000FF;
    byte4 = (num >> 24) & 0xFF;

    printf("Byte 1: %d\n", byte1);
    printf("Byte 2: %d\n", byte2);
    printf("Byte 3: %d\n", byte3);
    printf("Byte 4: %d\n", byte4);

    return 0;
}
