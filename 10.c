/* Program Number: 10
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program opens a file in read-write mode, writes 10 bytes, moves the file pointer by 10 bytes using lseek, and then writes another 10 bytes.

// seeking ahead by 10 bytes fills the 9 bytes after the first written 10 bytes with \0 characters (as displayed by the od command), and starts writing the next 10 characters after the 9 \0's
// offset is 20
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    write(fd, "ABCDEFGHIJ", 10);
    int offset = lseek(fd, 10, SEEK_CUR);

    printf("offset=%d\n", offset);

    write(fd, "ABCDEFGHIJ", 10);

    close(fd);
    return 0;
}
