/*
WAP to create the following process structure( make use of wait system call)
p1 -> p2
p1 -> p3 -> p4
p2 -> p6
p2 -> p5 -> p7
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid;

    printf("P1 created. PID: %d, PPID: %d\n", getpid(), getppid());

    // Create P2
    pid = fork();
    if (pid == 0) {
        // P2 process
        printf("P2 created. PID: %d, PPID: %d\n", getpid(), getppid());

        // Create P6
        pid = fork();
        if (pid == 0) {
            // P6 process
            printf("P6 created. PID: %d, PPID: %d\n", getpid(), getppid());
            exit(0); // P6 exits
        }
        wait(NULL); // Wait for P6 to complete

        // Create P5
        pid = fork();
        if (pid == 0) {
            // P5 process
            printf("P5 created. PID: %d, PPID: %d\n", getpid(), getppid());

            // Create P7
            pid = fork();
            if (pid == 0) {
                // P7 process
                printf("P7 created. PID: %d, PPID: %d\n", getpid(), getppid());
                exit(0); // P7 exits
            }
            wait(NULL); // Wait for P7 to complete
            exit(0); // P5 exits
        }
        wait(NULL); // Wait for P5 to complete
        exit(0); // P2 exits
    }

    // Create P3
    pid = fork();
    if (pid == 0) {
        // P3 process
        printf("P3 created. PID: %d, PPID: %d\n", getpid(), getppid());

        // Create P4
        pid = fork();
        if (pid == 0) {
            // P4 process
            printf("P4 created. PID: %d, PPID: %d\n", getpid(), getppid());
            exit(0); // P4 exits
        }
        wait(NULL); // Wait for P4 to complete
        exit(0); // P3 exits
    }

    // P1 waits for P2 and P3 to complete
    wait(NULL);
    wait(NULL);

    printf("P1 exiting. PID: %d\n", getpid());
    return 0;
}
