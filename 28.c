/* Program Number: 28
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program prints the priority of the current process, and modifies by changing its nice value.
*/ 

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    printf("Current priority: %d\n", getpriority(PRIO_PROCESS, 0));
    // gave 0
    nice(10);
    printf("New priority: %d\n", getpriority(PRIO_PROCESS, 0));
    // gives +10
    return 0;
}
