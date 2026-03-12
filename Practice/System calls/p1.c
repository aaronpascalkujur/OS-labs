#include <stdio.h>
#include <unistd.h>     
#include <sys/wait.h>   
#include <stdlib.h>     

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("I am the child. My PID is %d\n", getpid());
        exit(0); 
    } 
    else if (pid > 0) {
        printf("I am the parent. My PID is %d\n", getpid());
     
        wait(NULL); 
        printf("Child is dead. Parent exiting.\n");
    }

    return 0;
}