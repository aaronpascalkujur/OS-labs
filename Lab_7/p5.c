#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0; fib[1] = 1;
    for(i=2; i<n; i++) fib[i] = fib[i-1] + fib[i-2];

    if (fork() == 0) {
        printf("Child (Even Indexes): ");
        for(i=0; i<n; i+=2) printf("%d ", fib[i]);
        printf("\n");
        exit(0);
    } else {
        wait(NULL);
        printf("Parent (Odd Indexes): ");
        for(i=1; i<n; i+=2) printf("%d ", fib[i]);
        printf("\n");
    }
    return 0;
}