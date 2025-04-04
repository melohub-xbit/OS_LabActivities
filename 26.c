/* Program Number: 26
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program executes ls -Rl using the following system calls:
a. execl
b. execlp
c. execle
d. execv
e. execvp
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // a. Using execl
    printf("About to execute ls -Rl using execl\n");
    execl("/bin/ls", "ls", "-R", "-l", NULL);
    
    // b. Using execlp
    // printf("About to execute ls -Rl using execlp\n");
    // execlp("ls", "ls", "-R", "-l", NULL);
    
    // c. Using execle
    // printf("About to execute ls -Rl using execle\n");
    // char *envp[] = {"PATH=/bin:/usr/bin", NULL};
    // execle("/bin/ls", "ls", "-R", "-l", NULL, envp);
    
    // d. Using execv
    // printf("About to execute ls -Rl using execv\n");
    // char *args1[] = {"ls", "-R", "-l", NULL};
    // execv("/bin/ls", args1);
    
    // e. Using execvp
    // printf("About to execute ls -Rl using execvp\n");
    // char *args2[] = {"ls", "-R", "-l", NULL};
    // execvp("ls", args2);
    
    // This will only execute if exec fails
    perror("exec failed");
    return 1;
}
