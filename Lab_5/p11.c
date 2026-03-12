#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 10;
    pid_t p1, p2;
    printf("Parent Process: PID = %d\n", getpid());
    p1 = fork();
    if (p1 == 0) {
        x = x + 20;
        printf("Child 1 (p1): PID = %d, Parent PID = %d, Result = %d\n", getpid(), getppid(), x);
        exit(0);
    }
    else {
        p2 = fork();    
        if (p2 == 0) {
            x = x * 5;
            printf("Child 2 (p2): PID = %d, Parent PID = %d, Result = %d\n", getpid(), getppid(), x);
            exit(0);
        }
        else {
            printf("Parent: Both children created.\n");
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}