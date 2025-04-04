/* Program Number: 1b
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates a new text file, writes a sample text into it, and creates a hard link using the link system call

Corresponding shell script is 1b.sh
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    char *src_file_hard_link = "src_file_hard_link.txt";
    char *hard_link_name = "hard_link.txt";
    const char *content = "Testing file for hard link creation.\n";

    int fd = open(src_file_hard_link, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error creating source file");
        return 1;
    }
    write(fd, content, strlen(content));
    close(fd);
    
    if (link(src_file_hard_link, hard_link_name) == -1) {
        perror("Error creating hard link");
        return 1;
    }

    printf("Hard link '%s' created: Links to '%s'.\n", hard_link_name, src_file_hard_link);
    return 0;
}
