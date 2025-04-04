/* Program Number: 16a
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program implements a write lock using mandatory locking.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("sample.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Applying write lock...\n");
    
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error applying write lock");
        close(fd);
        return 1;
    }
    
    printf("Write lock applied successfully\n");
    printf("Press Enter to release lock...\n");
    getchar();

    printf("Releasing write lock...\n");
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error releasing lock");
    } else {
        printf("Write lock released successfully\n");
    }

    close(fd);
    return 0;
}
