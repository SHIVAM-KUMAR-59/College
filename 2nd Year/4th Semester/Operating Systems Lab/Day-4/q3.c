/*
WAP to create the following process structure( make use of wait system call)
p1 -> p2
p1 -> p3 -> p4
p2 -> p6
p2 -> p5 -> p7
*/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
        int t = fork();
    for(int i = 0; i < 2; i++){
        if(t != 0){
            int a = fork();
            printf("Child Process ID of P%d: %d and parent ID: %d\n", i + 1, getpid(), getppid());
        }
    }
    return 0;
}