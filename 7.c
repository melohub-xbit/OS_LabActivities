/* Program Number: 7
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program replicated the working of the cp command

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s src_file dest_file\n", argv[0]);
        return 1;
    }

    int fd_src = open(argv[1], O_RDONLY);

    int fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    char letter;
    
    while ((read(fd_src, &letter, 1)) > 0) {
        write(fd_dest, &letter, 1);
    }

    close(fd_src);
    close(fd_dest);

    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);
    return 0;
}
