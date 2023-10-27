#include <stdio.h>

int main() {
    int n, i, j, wt[20], tat[20], bt[20], at[20], ct[20], total_wt = 0, total_tat = 0;


    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p_number[n];

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        p_number[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {

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


    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

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