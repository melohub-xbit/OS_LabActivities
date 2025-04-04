/* Program Number: 3
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates a new file using the creat() system call, and prints its file descriptor which is returned by creat()

the file descriptor printed is the least number available after assigning fd for all open files
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = creat("test_file.txt", 0666);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    printf("File created successfully. File descriptor: %d\n", fd);
    close(fd);
    return 0;
}