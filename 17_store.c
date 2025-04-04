/* Program Number: 17_store
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates a file to store the ticket number, and exits
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("tickets.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("File creation failed");
        return 1;
    }
    
    int tkt = 1;
    int countWrite = write(fd, &tkt, sizeof(tkt));
    
    if (countWrite == -1) {
        perror("Write failed");
        close(fd);
        return 1;
    }
    close(fd);
    
    printf("Ticket initialized.\n");
    return 0;
}
