/* Program Number: 8
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program opens a file in read only mode and reads line by line, and displays each line as it read

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int fd = open("sample.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char letter;
    int count;
    
    while ((count = read(fd, &letter, 1)) > 0) {
        printf("%c", letter);
    }

    if (count == -1) {
        perror("Error reading file");
    }

    close(fd);
    return 0;
}
