/* Program Number: 1a
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates a new text file, writes a sample text into it, and creates a soft link for it using system call symlink

Corresponding shell script is 1a.sh
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    char *src_file_soft_link = "src_file_soft_link.txt";
    char *soft_link_file_name = "soft_link.txt";
    const char *content = "Test file for soft link creation.\n";

    int fd = open(src_file_soft_link, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error creating src_file_soft_link file");
        return 1;
    }
    write(fd, content, strlen(content));
    close(fd);
    
    if (symlink(src_file_soft_link, soft_link_file_name) == -1) {
        perror("Error creating soft link");
        return 1;
    }

    printf("Soft link '%s' created: Links to '%s'.\n", soft_link_file_name, src_file_soft_link);
    return 0;
}
