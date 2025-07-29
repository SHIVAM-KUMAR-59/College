// WAP to check whether the next machine is little indian or big indian. Enter a number print the content of byte location and convert the indians and print.

#include<stdio.h>

int main() {
    int num;
    printf("Enter number:\n");
    scanf("%d", &num);

    char *c = (char *)&num;

    if((*c) == 1) {
        printf("Little indian\n");
    } else {
        printf("Big indian\n");
    }

    printf("Bytes of original number:\n");
    for(int i = 0; i < sizeof(int); i++) {
        printf("Byte %d: %d\n", i, c[i]);
    }

    int converted = 0;
    char *p = (char *)&converted;

    for(int i = 0; i < sizeof(int); i++) {
        p[i] = c[sizeof(int) - 1 - i];
    }

    printf("Bytes after converting endianness:\n");
    for(int i = 0; i < sizeof(int); i++) {
        printf("Byte %d: %d\n", i, p[i]);
    }

    return 0;
}
