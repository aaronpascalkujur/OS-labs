#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t p1, p2;
    printf("Parent P (PID %d) starts.\n", getpid());

    p1 = fork();
    if (p1 == 0) {
        printf("Child P1 (PID %d) starts.\n", getpid());
        
        p2 = fork();
        if (p2 == 0) {
            printf("Grandchild P2 (PID %d) runs.\n", getpid());
            exit(0);
        }
        wait(NULL);
        printf("Child P1 finishes after P2.\n");
        exit(0);
    }
    wait(NULL);
    printf("Parent P finishes after P1.\n");
    return 0;
}