#include <stdio.h>
#include <stdlib.h>

void main() {
    int n;
    printf("enter the number of processes:\n");
    scanf("%d", &n);

    int at[10];
    int bt[10];

    printf("enter arrival and burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("enter arrival time for process %d: ", i);
        scanf("%d", &at[i]);  
        printf("enter burst time for process %d: ", i);
        scanf("%d", &bt[i]); 
    }

    int ct[10];

    //cal completion time
    int sum = at[0]; 
    for (int i = 0; i < n; i++) {
        sum = sum + bt[i];
        ct[i] = sum;
    }

    // calculate turnaround time
    int total = 0;
    int tat[10];
    for (int k = 0; k < n; k++) {
        tat[k] = ct[k] - at[k];
        total += tat[k];
    }

    // calculate waiting time
    int waitingTotal = 0;
    int wt[10];
    for (int j = 0; j < n; j++) {
        wt[j] = tat[j] - bt[j];
        waitingTotal += wt[j];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", (float)total / n);
    printf("Average Waiting Time = %.2f\n", (float)waitingTotal / n);
}
