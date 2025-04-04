/* Program Number: 19
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program creates processes in different states - running, sleeping and stopped
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {

    // run as ./a.out & (in background)
    printf("Process (PID: %d) running.\n", getpid());
    
    printf("Process sleeping for 15 seconds...\n");
    sleep(15);

    printf("Process stopping itself.\n");
    printf("Resume with kill -CONT %d.\n", getpid());
    raise(SIGSTOP);

    printf("Process resumed. Exiting now.\n");
    return 0;
}
