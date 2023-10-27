#include <stdio.h>

int main() {
    int n, i, j, wt[20], tat[20], bt[20], at[20], ct[20], total_wt = 0, total_tat = 0;
    // n is number of processes
    // at is arrival time
    // bt is burst time, for how long the CPU is using the CPU
    // ct is completion time, which is sum of arrival time and burst time
    // tat is turn around time, which is completion time - arrival time
    // wt is waiting time, which is turn around time - burst time
    // total_wt is sum of all wating time
    // total_tat is sum of all turn around time
    // average_wt is average waiting time
    // average_tat is average turn around time

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p_number[n];

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        p_number[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // sort based on arrival time first
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {

            // if arrival time of process i is greater than arrival time of process j
            // swap the arrival time and burst time of process i and j
            if (at[i] > at[j]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                int temp2 = p_number[i];
                p_number[i] = p_number[j];
                p_number[j] = temp2;
            }
        }
    }


    // Calculate completion time for each process
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    // Calculate turnaround time and waiting time for each process
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and turnaround time
    float avg_wt = (float) total_wt / n;
    float avg_tat = (float) total_tat / n;

    // Print results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        // printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p_number[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);

    return 0;
}