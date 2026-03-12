#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Child process (PID %d) is running...\n", getpid());
        exit(0);
    } else {
        printf("Parent (PID %d) waiting for child...\n", getpid());
        wait(NULL);
        printf("Parent: Child cleaned up (No Zombie).\n");
    }
    return 0;
}