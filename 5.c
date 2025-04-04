/* Program Number: 5
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates infinite txt files, named as file_1.txt and so on, every 3s
The file descriptors of each created file are stored, and printed after creating each file
It creates 10 files, and the FD's of the files are visible under /proc/PID of process of this program/fd

a new fd is added and seen every 3s
after 10 files are created, it sleeps for 30s to check fds of the files that were created and opened, and then closes all the fds

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int count = 1;
    char fname[30];
    int fds[100];


    while (1) {
        snprintf(fname, sizeof(fname), "file_%d.txt", count);
        int fd = creat(fname, 0644);

        if (fd == -1) {
            perror("Error creating file");
            return 1;
        }

        fds[count] = fd;

        printf("Created file: %s (FD: %d)\n", fname, fd);
        sleep(3);

        count++;

        if (count > 10) {
            sleep(30);
            break;
        }
    }

    for (int i = 1; i < count-1; i++) {
        close(fds[i]);
    }


    return 0;
}
