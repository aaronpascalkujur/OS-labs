#include <stdio.h>
#include <limits.h>

int main() {
    int pid[10], at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int g_pid[100], g_start[100], g_end[100];
    int n, i, time = 0, completed = 0, min_m;
    int shortest = -1, prev_shortest = -1, finish_time;
    float total_tat = 0, total_wt = 0;
    int g_count = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed != n) {
        min_m = INT_MAX;
        shortest = -1;

        for (i = 0; i < n; i++) {
            if ((at[i] <= time) && (rt[i] < min_m) && rt[i] > 0) {
                min_m = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            if (g_count == 0 || g_pid[g_count - 1] != -1) {
                g_pid[g_count] = -1;
                g_start[g_count] = time;
                g_end[g_count] = time + 1;
                g_count++;
            } else {
                g_end[g_count - 1] = time + 1;
            }
            time++;
            continue;
        }

        if (shortest != prev_shortest) {
            g_pid[g_count] = pid[shortest];
            g_start[g_count] = time;
            g_end[g_count] = time + 1;
            g_count++;
        } else {
            g_end[g_count - 1] = time + 1;
        }

        rt[shortest]--;
        prev_shortest = shortest;
        time++;

        if (rt[shortest] == 0) {
            completed++;
            finish_time = time;
            ct[shortest] = finish_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            total_tat += tat[shortest];
            total_wt += wt[shortest];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f\n", total_tat / n);
    printf("Average WT = %.2f\n", total_wt / n);

    printf("\nGantt Chart:\n");
    for (i = 0; i < g_count; i++) {
        if (g_pid[i] == -1) printf("| IDLE ");
        else printf("|  P%d  ", g_pid[i]);
    }
    printf("|\n");

    printf("%d", g_start[0]);
    for (i = 0; i < g_count; i++) {
        printf("      %d", g_end[i]);
    }
    printf("\n");
    
    return 0;
}