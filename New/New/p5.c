#include <stdio.h> // Include standard input/output library for printf and scanf

int main() {
    // Declare arrays to store process data for up to 10 processes
    // pid: Process ID, at: Arrival Time, bt: Burst Time
    // ct: Completion Time, tat: Turnaround Time, wt: Waiting Time
    int pid[10], at[10], bt[10], ct[10], tat[10], wt[10];
    
    // n: Number of processes, i & j: Loop counters, temp: Used for swapping
    int n, i, j, temp;
    
    // Variables to store total times for calculating averages
    float total_tat = 0, total_wt = 0;
    
    // Keeps track of the current time in the CPU (starts at 0)
    int current_time = 0;

    // --- STEP 1: INPUT ---
    // Ask the user how many processes they want to schedule
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Loop to get Arrival Time and Burst Time for each process
    for(i = 0; i < n; i++) {
        pid[i] = i + 1; // Assign Process ID (1, 2, 3...)
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]); // Read inputs
    }

    // --- STEP 2: SORTING (Bubble Sort) ---
    // FCFS means "First Come First Serve", so we MUST process them in order of Arrival Time.
    // If the user enters them out of order, this sorts them.
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            // Check if the current process arrived LATER than the next one
            if(at[j] > at[j+1]) {
                // If yes, SWAP them. We must swap AT, BT, and PID 
                // so the data stays together for that specific process.
                
                // Swap Arrival Time
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                // Swap Process ID
                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }

    // --- STEP 3: CALCULATION ---
    // Now that they are sorted, we process them one by one.
    for(i = 0; i < n; i++) {
        // IDLE TIME CHECK:
        // If the CPU is free (current_time) but the process hasn't arrived yet (at[i]),
        // we must wait. Move current_time forward to when the process arrives.
        if(current_time < at[i]) {
            current_time = at[i];
        }

        // Calculate Completion Time:
        // It finishes when it started (current_time) + how long it takes (bt)
        ct[i] = current_time + bt[i];

        // Calculate Turnaround Time:
        // TAT = Completion Time - Arrival Time
        tat[i] = ct[i] - at[i];

        // Calculate Waiting Time:
        // WT = Turnaround Time - Burst Time
        wt[i] = tat[i] - bt[i];

        // Update current_time:
        // The CPU is now busy until this process finishes.
        current_time = ct[i];

        // Add to totals (used for averages later)
        total_tat = total_tat + tat[i];
        total_wt = total_wt + wt[i];
    }

    // --- STEP 4: OUTPUT ---
    // Print the table header
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("--------------------------------------------------\n");

    // Loop through and print the details for each process
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Print Averages
    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}