/* Program Number: 6
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program takes input from user using the read() system call, by specifying stdin fd as source, and writes the input to stdout using write() system call

max 512 characters may be read

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buf[512];
    int countRead;

    printf("Input (Ctrl+D to exit):\n");
    
    while ((countRead = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, countRead);
    }

    if (countRead == -1) {
        perror("Error reading input");
        return 1;
    }

    return 0;
}
