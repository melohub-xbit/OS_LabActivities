/* Program Number: 1c
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates a new FIFO pipe, using the mkfifo system call

Corresponding shell script is 1c.sh
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char *fifo = "fifo_pipe";

    if (mkfifo(fifo, 0666) == -1) {
        perror("Error creating FIFO");
        return 1;
    }

    printf("FIFO '%s' created successfully.\n", fifo);
    return 0;
}
