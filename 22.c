/* Program Number: 22
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates a zombie state in the running program.
// if parent sleeps before child exits, child is in Zombie state
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Parent process (PID: %d). Child PID: %d (Zombie)\n", getpid(), pid);
        sleep(15);
    }
    else if (pid == 0) {
        printf("Child process (PID: %d) exiting...\n", getpid());
        exit(0);
    } 
    else {
        perror("Fork failed");
    }

    return 0;
}
