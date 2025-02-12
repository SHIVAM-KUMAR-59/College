#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int t, a[2][2];
    pipe(a[0]);
    pipe(a[1]);

    t = fork();
    if (t > 0) { 
        write(a[0][1], "5", 2); 
        wait(NULL);
    } 
    else if (t == 0) {  
        char p[10]; 
        int v;
        
        read(a[0][0], p, sizeof(p)); 
        v = atoi(p); 
        v++;
        printf("%d\n", v);

        char s[10];
        sprintf(s, "%d", v); 
        
        write(a[1][1], s, 2); 
    }
    if(t>0){
    char d[10];
    read(a[1][0], d, 1); 
    printf("%s\n", d);
    }
    
    return 0;
}