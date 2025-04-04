/* Program Number: 17_book
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program open the ticket init file, implements a write lock, reads the ticket number, increments the number, prints the new ticket number, and then closes the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("tickets.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLKW, &lock);
    
    //read current ticket
    int ticket;
    read(fd, &ticket, sizeof(ticket));

    printf("Reserving ticket: %d\n", ticket);
    ticket++;

    //increment and write new ticket number
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));

    // new ticket number available for booking, after booking the previous one
    printf("New ticket number available: %d\n", ticket);
    
    // Release the lock before closing
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    
    close(fd);
    return EXIT_SUCCESS;
}
