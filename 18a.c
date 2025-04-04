/* Program Number: 18a
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program implements record locking using write locks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd = open("sample.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // put some records in it if empty
    struct stat file_stat;
    stat("sample.txt", &file_stat);
    
    if (file_stat.st_size == 0) {
        char *init_data = "Record1: Initial data\nRecord2: Initial data\nRecord3: Initial data\n";
        write(fd, init_data, strlen(init_data));
        
        printf("File initialized with records\n");
    }

    int rec_num = 2;
    int rec_size = 30;
    int rec_pos = (rec_num - 1) * rec_size;
    
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = rec_pos;
    lock.l_len = rec_size;
    
    printf("Applying write lock to record %d...\n", rec_num);
    fcntl(fd, F_SETLKW, &lock);
    printf("Record %d locked successfully\n", rec_num);
    
    char curr[rec_size + 1];
    lseek(fd, rec_pos, SEEK_SET);
    
    int readCount = read(fd, curr, rec_size);

    curr[readCount] = '\0';
    
    printf("Current record content: %s\n", curr);
    
    const char *new_content = "Record2: Updated data      \n";
    lseek(fd, rec_pos, SEEK_SET);
    
    write(fd, new_content, strlen(new_content));
    
    printf("Record updated successfully\n");
    printf("Press Enter to release lock...\n");
    getchar();
    
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    
    printf("Lock on record %d released\n", rec_num);
    close(fd);
    return 0;
}
