/* Program Number: 4
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program opens an existing file, and it is opened by giving the O_EXCL flag, which doesn't open an already existing file... if a file is not there, it is created and opened, if it is already there, it won't open it

doesn't open a file if it already exists
O_EXCL used along with O_CREAT
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("existing.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("Error opening file with O_EXCL");
        return 1;
    }

    printf("File opened successfully; file descriptor = %d\n", fd);
    close(fd);
    return 0;
}

