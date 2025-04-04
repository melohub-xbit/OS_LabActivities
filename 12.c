/* Program Number: 12
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program checks the opening mode of a file using fcntl()
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Usage: EXE <filename>\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int flag = fcntl(fd, F_GETFL);
    if (flag == -1) {
        perror("fcntl error");
        close(fd);
        return 1;
    }

    printf("File mode: ");
    if ((flag & O_ACCMODE) == O_RDWR)
        printf("Read-Write\n");
    else if ((flag & O_ACCMODE) == O_RDONLY)
        printf("Read-only\n");
    else if ((flag & O_ACCMODE) == O_WRONLY)
        printf("Write-only\n");

    close(fd);
    return 0;
}
