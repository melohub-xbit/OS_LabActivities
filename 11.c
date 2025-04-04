/* Program Number: 11
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program opens a file, duplicates the file descriptor using dup, dup2, and fcntl(), appends the file with both descriptors, and verifies whether the file is updated correctly.

// in the sample.txt, at the end of the code, it appends the string to the same file, every time the code runs
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1 = open("sample.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    
    int fd2 = dup(fd1);     
    int fd3 = dup2(fd1, 100); 
    int fd4 = fcntl(fd1, F_DUPFD, 0); 

    write(fd1, "fd1\n", 4);
    write(fd2, "fd2\n", 4);
    write(fd3, "fd3\n", 4);
    write(fd4, "fd4\n", 4);

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    return 0;
}

