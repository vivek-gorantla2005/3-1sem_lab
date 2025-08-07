#include <stdio.h>

int main() {
    int n;
    int p[10];
    int pri[10];
    int bt[10];
    int ct[10];
    int tat[10];
    int wt[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority
    for (int i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter priority of process %d (lower value = higher priority): ", i + 1);
        scanf("%d", &pri[i]);
        p[i] = i + 1; // Store process number
    }

    // Sort by priority (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pri[j] > pri[j + 1]) {
                // Swap priority
                int temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process ID
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Completion Time
    ct[0] = bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    // Turnaround Time = Completion Time (CT) since Arrival Time = 0
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i]; // AT is 0
    }

    // Waiting Time = Turnaround - Burst
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("\nProcess\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i], bt[i], pri[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
