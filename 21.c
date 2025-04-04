/* Program Number: 21
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program opens a file, calls fork, and allows both the child and parent processes to write to the file.

// both child and parent write to the same file
// either parent or child can write first, if parent doesn't wait for the child to complete
// if parent waits, child writes first
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd = open("sample.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    
    int pid = fork();

    if (pid == 0) {
        write(fd, "Child - write\n", 14);
    } else if (pid > 0) {
        // if parent should wait for child
        // int status;
        // waitpid(pid, &status, 0);
        write(fd, "Parent - write\n", 15);
    } 
    else {
        perror("Fork failed");
    }

    close(fd);
    return 0;
}
