/* Program Number: 27
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program retrieves the maximum and minimum real-time priority.
*/ 

#include <stdio.h>
#include <sched.h>

int main() {
    printf("Minimum priority: %d\n", sched_get_priority_min(SCHED_FIFO));
    printf("Maximum priority: %d\n", sched_get_priority_max(SCHED_FIFO));
    return 0;
}
