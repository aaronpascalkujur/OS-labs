#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int priority;   // Priority
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
};

void sortProcessesByPriority(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Sort in ascending order of priority number (Lower number = Higher Priority)
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculateTimes(struct Process p[], int n) {
    p[0].wt = 0; // Waiting time for the first process is 0
    p[0].tat = p[0].bt; // Turnaround time is its burst time

    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }
}

void printProcessDetails(struct Process p[], int n) {
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].priority, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("------------------------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

void printGanttChart(struct Process p[], int n) {
    printf("\nGantt Chart:\n");
    
    // Print top bar
    for (int i = 0; i < n; i++) {
        printf("--------");
    }
    printf("-\n|");
    
    // Print process IDs
    for (int i = 0; i < n; i++) {
        printf("  P%d  \t|", p[i].pid);
    }
    printf("\n");
    
    // Print bottom bar
    for (int i = 0; i < n; i++) {
        printf("--------");
    }
    printf("-\n");
    
    // Print timeline
    printf("0");
    for (int i = 0; i < n; i++) {
        printf("\t%d", p[i].tat);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter Burst Time for Process P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        printf("Enter Priority for Process P%d (Lower number = Higher Priority): ", p[i].pid);
        scanf("%d", &p[i].priority);
    }

    // Step 1: Sort processes by Priority
    sortProcessesByPriority(p, n);

    // Step 2: Calculate Waiting Time and Turnaround Time
    calculateTimes(p, n);

    // Step 3: Print the results and metrics
    printProcessDetails(p, n);

    // Step 4: Display the Gantt Chart
    printGanttChart(p, n);

    return 0;
}