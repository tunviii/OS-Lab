#include <stdio.h>

#define max 30

int main() {
    int i, j, n, temp;
    int p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter process number:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter Burst Time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(bt[j] > bt[j + 1]) {

                
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

   
    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];

        awt = awt + wt[i];
        atat = atat + tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               p[i], bt[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f\n", atat);

    return 0;
}
