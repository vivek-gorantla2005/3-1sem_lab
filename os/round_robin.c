#include <stdio.h>

void main() {
    int n, i, qt;
    int bt[10], rem_bt[10], wt[10], tat[10];
    int time = 0, count = 0;

    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &qt);

    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // At least one process is left

                if (rem_bt[i] > qt) {
                    time += qt;
                    rem_bt[i] -= qt;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i]; // Waiting time = current time - burst
                    rem_bt[i] = 0;
                    tat[i] = time;        // Turnaround time = completion time
                }
            }
        }

        if (done == 1)
            break;
    }

    // Display result
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}
