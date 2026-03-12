#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t c1, c2, gc;

    c1 = fork();
    if (c1 == 0) {
        printf("Child 1 (PID %d) done.\n", getpid());
        exit(0);
    }

    c2 = fork();
    if (c2 == 0) {
        printf("Child 2 (PID %d) created.\n", getpid());
        gc = fork();
        if (gc == 0) {
            printf("Grandchild (PID %d) of C2 done.\n", getpid());
            exit(0);
        }
        wait(NULL);
        exit(0);
    }

    wait(NULL);
    wait(NULL);
    printf("Parent: All children finished.\n");
    return 0;
}