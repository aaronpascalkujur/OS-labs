#include <stdio.h>

int main() {
    int pid[10], at[10], bt[10], ct[10], tat[10], wt[10];
    int g_pid[20], g_start[20], g_end[20];
    int n, i, j, temp, current_time = 0, g_count = 0;
    float total_tat = 0, total_wt = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        scanf("%d %d", &at[i], &bt[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(at[j] > at[j+1]) {
                temp = at[j]; at[j] = at[j+1]; at[j+1] = temp;
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = pid[j]; pid[j] = pid[j+1]; pid[j+1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(current_time < at[i]) {
            g_pid[g_count] = -1;
            g_start[g_count] = current_time;
            g_end[g_count] = at[i];
            g_count++;
            current_time = at[i];
        }

        g_pid[g_count] = pid[i];
        g_start[g_count] = current_time;
        ct[i] = current_time + bt[i];
        g_end[g_count] = ct[i];
        g_count++;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        current_time = ct[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", total_tat / n);
    printf("\nAverage WT = %.2f\n", total_wt / n);

    printf("\nGantt Chart:\n");
    for(i = 0; i < g_count; i++) {
        if(g_pid[i] == -1) printf("| IDLE ");
        else printf("|  P%d  ", g_pid[i]);
    }
    printf("|\n");

    printf("%d", g_start[0]);
    for(i = 0; i < g_count; i++) {
        printf("      %d", g_end[i]);
    }
    printf("\n");

    return 0;
}