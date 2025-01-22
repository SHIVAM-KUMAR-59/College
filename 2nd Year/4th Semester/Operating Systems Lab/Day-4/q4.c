// WAP to show that a program is in zombie state

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int t = fork();
    if(t == 0){
        printf("Child process ID: %d\n",getpid());
        printf("Parent process ID: %d\n",getppid());
        exit(0);
    }else{
        printf("Parent process ID: %d\n",getpid());
        wait(NULL);
        printf("Zombie process ID: %d\n",t);
    }
    return 0;
}