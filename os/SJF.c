#include <stdio.h>

void main() {
    int p[10];
    int bt[10];
    int ct[10];
    int tat[10];
    int wt[10];
    int n;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Bubble sort by burst time (SJF)
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs accordingly
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Completion Time
    int wtsum = 0;
    for (int i = 0; i < n; i++) {
        wtsum += bt[i];
        ct[i] = wtsum;
    }

    // Turnaround Time = Completion Time (AT = 0)
    int tsum = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];
        tsum += tat[i];
    }

    // Waiting Time = Turnaround Time - Burst Time
    int wtotal = 0;
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        wtotal += wt[i];
    }

    printf("\nP\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i]+1, bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", (float)tsum / n);
    printf("Average Waiting Time = %.2f\n", (float)wtotal / n);
}
