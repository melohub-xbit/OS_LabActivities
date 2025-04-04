/* Program Number: 15
Student Name: Velidanda Krishna Sai; Register Number: IMT2023094
Date:
Description: This program prints all environment variables of the user
*/

#include <stdio.h>

extern char **environ;

int main() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
