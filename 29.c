/* Program Number: 29
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program obtains the scheduling policy and modifies it (e.g., SCHED_FIFO, SCHED_RR).

// sched_setscheduler() worked only with root privileges, so sudo ./a.out worked, but not direct ./a.out
*/  

#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy = sched_getscheduler(0);  // 0 means current process
    
    printf("Current scheduling policy: ");
    switch(policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER (normal)\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown (%d)\n", policy);
    }
    
    // Change to FIFO scheduling
    struct sched_param param;
    param.sched_priority = 10;
    
    int result = sched_setscheduler(0, SCHED_FIFO, &param);
    
    printf("Scheduler changed to SCHED_FIFO\n");
    
    // Verify the change
    policy = sched_getscheduler(0);
    printf("New scheduling policy: ");
    switch(policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER (normal)\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown (%d)\n", policy);
    }

    
    return 0;
}
