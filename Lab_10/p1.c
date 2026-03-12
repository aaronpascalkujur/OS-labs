#include <stdio.h>

struct Process {
    int pid, bt, pr, wt, tat;      
};
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].pr);
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].pr > p[j+1].pr) {
                swap(&p[j], &p[j+1]);
            }
        }
    }

  
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    
    float total_wt = 0, total_tat = p[0].bt;

    for(int i = 1; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nPID\tBT\tPriority\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}