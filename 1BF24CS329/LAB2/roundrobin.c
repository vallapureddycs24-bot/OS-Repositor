#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
    }
    for(int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    int time = 0, completed = 0;
    while(completed < n) {
        int executed = 0;
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                executed = 1;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    completed++;
                }
            }
        }
        if(!executed) {
            time++;
        }
    }
    float avg_tat = 0, avg_wt = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

        avg_tat += tat[i];
        avg_wt  += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
