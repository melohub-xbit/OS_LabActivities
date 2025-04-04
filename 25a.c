/* Program Number: 25a
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program executes a program using the exec system call.
*/ 

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing ls -l command...\n");
    
    execl("/bin/ls", "ls", "-l", NULL);
    
    // This line will only execute if execl fails
    printf("execl failed\n");
    
    return 0;
}
