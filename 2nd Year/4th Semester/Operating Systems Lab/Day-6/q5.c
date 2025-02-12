#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int t, a[3][2];
    char s[] = "Hello";  

    for (int i = 0; i < 3; i++) {
        pipe(a[i]);
        t = fork();

        if (t == 0) {
            char p[10]; 
            read(a[i][0], p, sizeof(p));
            printf("%s\n", p);
            exit(0);
        }
        write(a[i][1], s, sizeof(s));  
    }

    for (int i = 0; i < 3; i++) {
        wait(NULL);  
    }

    return 0;
}
