/* Program Number: 23
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates an orphan process. (orphan process if parent exits before child)
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        sleep(5);
        printf("Child process (orphan) with new parent (PID: %d)\n", getppid());
        exit(0);
    } else {
        printf("Parent (PID: %d) exiting...\n", getpid());
        exit(0);
    }

    return 0;
}
