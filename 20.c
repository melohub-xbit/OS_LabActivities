/* Program Number: 20
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program calls fork and prints both the parent and child process IDs.
*/ 

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    
    if (pid > 0) {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    } else if (pid == 0) {
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        perror("Fork failed");
    }
    
    return 0;
}
