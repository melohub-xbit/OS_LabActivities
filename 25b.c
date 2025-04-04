/* Program Number: 25b
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program passes input to an executable program using the exec system call.

// here, the argument is the content to be sent to echo.
*/ 

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }
    
    printf("Executing echo with argument: %s\n", argv[1]);
    
    execl("/bin/echo", "echo", "Hello,", argv[1], NULL);
    
    // This line will only execute if execl fails
    printf("execl failed\n");
    
    return 0;
}
