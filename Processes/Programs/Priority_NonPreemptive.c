#include <stdio.h>

#define MAX 30

int main()
{
    int i, j, n, t, pos;
    int bt[MAX], wt[MAX], tat[MAX], pr[MAX];
    float awt = 0, atat = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time
    printf("Enter burst time of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Input priority
    printf("Enter priority of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sort processes by priority (ascending order)
    for (i = 0; i < n - 1; i++)
    {
        pos = i;

        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
            {
                pos = j;
            }
        }

        // Swap priorities
        t = pr[i];
        pr[i] = pr[pos];
        pr[pos] = t;

        // Swap burst times
        t = bt[i];
        bt[i] = bt[pos];
        bt[pos] = t;
    }

    // Calculate waiting and turnaround times
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;

        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }

        tat[i] = wt[i] + bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    // Display process details
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    // Calculate average times
    awt = awt / n;
    atat = atat / n;

    // Display averages
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}
