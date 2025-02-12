// WAP to create n child process, each process should display its own ID and parent ID
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>
int main(){
    int n;
    printf("Enter the number of child process: ");
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int t = fork();
        if(t == 0){
            printf("Child process ID: %d\n",getpid());
            printf("Parent process ID: %d\n",getppid());
            exit(0);
        }
    }
    return 0;
}