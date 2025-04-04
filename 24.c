/* Program Number: 24
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates three child processes. The parent process waits for a specific child process using the waitpid system call (here the third child).
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int p1 = fork();

    if (p1 == 0) {
        printf("Child 1 (PID: %d)\n", getpid());
        exit(0);
    }

    int p2 = fork();

    if (p2 == 0) {
        printf("Child 2 (PID: %d)\n", getpid());
        exit(0);
    }

    int p3 = fork();

    if (p3 == 0) {
        printf("Child 3 (PID: %d)\n", getpid());
        exit(0);
    }

    // let's take that parent waits for child 3
    waitpid(p3, NULL, 0);
    printf("Parent waited for Child 3\n");

    return 0;
}
