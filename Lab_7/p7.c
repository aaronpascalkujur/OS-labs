#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int start, end;
    printf("Enter range (start end): ");
    scanf("%d %d", &start, &end);

    if (fork() == 0) {
        printf("Child Primes: ");
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) printf("%d ", i);
        }
        printf("\n");
        exit(0);
    } else {
        wait(NULL);
        printf("Parent: Child finished task.\n");
    }
    return 0;
}