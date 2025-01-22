#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t t = fork();
    if(t == 0) {
        system("./q5.sh");
    } else {
        system("./q6.sh");
    }
    return 0;
}
