/* Program Number: 16b
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program implements a read lock using mandatory locking.
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

    printf("Applying read lock...\n");
    
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error applying read lock");
        close(fd);
        return 1;
    }
    
    printf("Read lock applied successfully\n");
    printf("Press Enter to release lock...\n");
    getchar();

    printf("Releasing read lock...\n");
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error releasing lock");
    } else {
        printf("Read lock released successfully\n");
    }

    close(fd);
    return 0;
}
