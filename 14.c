/* Program Number: 14
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program determines the type of a file using stat().

The different types that can be checked are:

(mode is the struct stat.st_mode)

S_ISREG(mode)
    Is nonzero for regular files
S_ISBLK(mode)
    Is nonzero for block special files
S_ISDIR(mode)
    Is nonzero for directories
S_ISFIFO(mode)
    Is nonzero for pipes and FIFO special files
S_ISLNK(mode)
    Is nonzero for symbolic links
S_ISSOCK(mode)
    Is nonzero for local sockets
S_ISCHR(mode)
    Is nonzero for character special files

// OS Native objects can also be checked with:
S_ISNATIVE(mode)
    Is nonzero for operating system native objects

otherwise unknown type

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Usage: <name of exe> <filename>\n");
        return 1;
    }

    struct stat file_stat;
    stat(argv[1], &file_stat);
    
    printf("File type of %s: ", argv[1]);
    if (S_ISREG(file_stat.st_mode)) printf("Regular file\n");
    else if (S_ISBLK(file_stat.st_mode)) printf("Block device\n");
    else if (S_ISDIR(file_stat.st_mode)) printf("Directory\n");
    else if (S_ISFIFO(file_stat.st_mode)) printf("FIFO pipe\n");
    else if (S_ISLNK(file_stat.st_mode)) printf("Symbolic link\n");
    else if (S_ISSOCK(file_stat.st_mode)) printf("Socket\n");
    else if (S_ISCHR(file_stat.st_mode)) printf("Character device\n");
    else printf("Unknown file type\n");

    return 0;
}
