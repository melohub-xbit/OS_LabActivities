/* Program Number: 30
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program executes a task at a specific time using a Daemon process.
*/  

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
  
int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Daemon Process PID: %d\n", pid);
        exit(0);
    }
    if (pid == 0) {
        umask(0);  // Reset file mode mask
        setsid();  // Create a new session
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
                
        while (1) {
            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            
            // Run at 1:00 PM (13:00 in 24-hour format)
            if (t->tm_hour == 13 && t->tm_min == 00) {
                system("task.sh");
            }
            sleep(60);
        }
    }
    return 0;
}
