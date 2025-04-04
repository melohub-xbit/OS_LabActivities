/* Program Number: 13
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program waits for input from STDIN for 10s using select, exits if no input, otherwise, prints the given input
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set read_fds;
    struct timeval timeout;

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input (10 sec timeout)...\n");

    int result = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select error");
        return 1;
    } else if (result == 0) {
        printf("No input received. Exiting.\n");
    } else {
        printf("Input available! Reading...\n");
        // read input
        char inp[1000];
        read(STDIN_FILENO, inp, sizeof(inp));
        printf("Input: %s", inp);

    }

    return 0;
}
