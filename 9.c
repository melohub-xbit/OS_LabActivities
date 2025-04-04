/* Program Number: 9
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program prints different details of a file

These details are present in the stat struct
a. Inode
b. Number of hard links
c. UID
d. GID
e. Size
f. Block size
g. Number of blocks
h. Time of last access
i. Time of last modification
j. Time of last change
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat stats_file;
    stat(argv[1], &stats_file);
    
    printf("File: %s\n", argv[1]);
    printf("a. Inode: %lu\n", stats_file.st_ino);
    printf("b. Number of Hard Links: %lu\n", stats_file.st_nlink);
    printf("c. UID: %d\n", stats_file.st_uid);
    printf("d. GID: %d\n", stats_file.st_gid);
    printf("e. Size: %ld bytes\n", stats_file.st_size);
    printf("f. Block Size: %ld bytes\n", stats_file.st_blksize);
    printf("g. Number of Blocks: %ld\n", stats_file.st_blocks);
    printf("h. Time of last access: %s", ctime(&stats_file.st_atime));
    printf("i. Time of last modification: %s", ctime(&stats_file.st_mtime));
    printf("j. Time of last change: %s", ctime(&stats_file.st_ctime));

    return 0;
}
