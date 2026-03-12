#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    if (fork() == 0) {
        printf("Child 1: Short task (2s)\n");
        sleep(2);
        printf("Child 1: Done\n");
        exit(0);
    }

    if (fork() == 0) {
        printf("Child 2: Long task (5s)\n");
        sleep(5);
        printf("Child 2: Done\n");
        exit(0);
    }

    wait(NULL);
    wait(NULL);
    printf("Parent: Longest task finished. Exiting.\n");
    return 0;
}