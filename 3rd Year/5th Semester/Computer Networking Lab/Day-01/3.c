// WAP to extract each byte from a given number and store them in separate character variable and print content of those variables

#include <stdio.h>

int main() {
    unsigned int num;
    char byte1, byte2, byte3, byte4;

    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    byte1 = (num & 0x000000FF);
    byte2 = (num & 0x0000FF00) >> 8;
    byte3 = (num & 0x00FF0000) >> 16;
    byte4 = (num & 0xFF000000) >> 24;

    printf("Byte 1: 0x%02X\n", (unsigned char)byte1);
    printf("Byte 2: 0x%02X\n", (unsigned char)byte2);
    printf("Byte 3: 0x%02X\n", (unsigned char)byte3);
    printf("Byte 4: 0x%02X\n", (unsigned char)byte4);

    return 0;
}
