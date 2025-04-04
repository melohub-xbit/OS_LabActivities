/* Program Number: 2
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program just runs in the background, so the process ID of proc that is created for this program is shown in the /proc directory, and inside /proc/<PID> all the details of this process are there

// the process ID is shown in /proc directory
// kill <PID> to stop it
*/

#include <stdio.h>
#include <unistd.h>


int main() {
    printf("Background process created with PID: %d\n", getpid());

    while (1) {
        sleep(7);
        printf("Process %d running in the background....\n", getpid());
    }

    return 0;
}
