/*
WAP to enter a number and store the number accorss a following structure and trim the content of each member of structure. Then aggreggate each member of struct to form the original number and print the same
struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
}
*/
#include <stdio.h>
struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    unsigned int num;
    unsigned char byte1, byte2, byte3, byte4;

    printf("Enter an integer: ");
    scanf("%u", &num);

    byte1 = (num & 0xFF);
    byte2 = (num >> 8) & 0xFF;
    byte3 = (num >> 16) & 0xFF;
    byte4 = (num >> 24) & 0xFF;

    struct pkt p;
    p.ch1 = byte1;
    p.ch2[0] = byte2;
    p.ch2[1] = byte3;
    p.ch3 = byte4;

    printf("Byte 1: %d\n", p.ch1);
    printf("Byte 2: %d\n", p.ch2[0]);
    printf("Byte 3: %d\n", p.ch2[1]);
    printf("Byte 4: %d\n", p.ch3);

    int first = (( char)p.ch1);
    int second = (( char)p.ch2[0]) << 8;
    int third = (( char)p.ch2[1]) << 16;
    int fourth = (( char)p.ch3) << 24;

    printf("first: %d\n", first);
    printf("second: %d\n", second);
    printf("third: %d\n", third);
    printf("fourth: %d\n", fourth);

    int restored = first | second | third | fourth;
    printf("restored: %d\n", restored);

    return 0;
}
