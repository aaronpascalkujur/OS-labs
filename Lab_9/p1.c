#include <stdio.h>
#include <limits.h>

int main() {
    int pid[10], at[10], bt[10], ct[10], tat[10], wt[10], is_completed[10] = {0};
    int g_pid[20], g_start[20], g_end[20];
    int n, i, current_time = 0, completed = 0, g_count = 0;
    float total_tat = 0, total_wt = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        scanf("%d %d", &at[i], &bt[i]);
    }

    while(completed != n) {
        int min_idx = -1;
        int min_bt = INT_MAX;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && is_completed[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    min_idx = i;
                } else if(bt[i] == min_bt) {
                    if(at[i] < at[min_idx]) {
                        min_idx = i;
                    }
                }
            }
        }

        if(min_idx != -1) {
            g_pid[g_count] = pid[min_idx];
            g_start[g_count] = current_time;
            current_time += bt[min_idx];
            g_end[g_count] = current_time;
            g_count++;

            ct[min_idx] = current_time;
            tat[min_idx] = ct[min_idx] - at[min_idx];
            wt[min_idx] = tat[min_idx] - bt[min_idx];
            
            total_tat += tat[min_idx];
            total_wt += wt[min_idx];
            
            is_completed[min_idx] = 1;
            completed++;
        } else {
            if(g_count == 0 || g_pid[g_count-1] != -1) {
                g_pid[g_count] = -1;
                g_start[g_count] = current_time;
                g_end[g_count] = current_time + 1;
                g_count++;
            } else {
                g_end[g_count-1] = current_time + 1;
            }
            current_time++;
        }
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