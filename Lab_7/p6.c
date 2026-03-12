#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void create_grandkids(int id) {
    if(fork() == 0) { printf("Grandchild of C%d (PID %d)\n", id, getpid()); exit(0); }
    if(fork() == 0) { printf("Grandchild of C%d (PID %d)\n", id, getpid()); exit(0); }
    wait(NULL); wait(NULL);
}

int main() {
    printf("Parent (PID %d)\n", getpid());

    if (fork() == 0) {
        printf("Child 1 (PID %d)\n", getpid());
        create_grandkids(1);
        exit(0);
    }

    if (fork() == 0) {
        printf("Child 2 (PID %d)\n", getpid());
        create_grandkids(2);
        exit(0);
    }

    wait(NULL); wait(NULL);
    printf("Parent: Tree complete.\n");
    return 0;
}