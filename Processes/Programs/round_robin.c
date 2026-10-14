#include <stdio.h>

#define MAX 10

int main()
{
    int i, n, qt, count, temp, sq = 0;
    int bt[MAX], wt[MAX], tat[MAX], rem_bt[MAX];
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
        rem_bt[i] = bt[i];
    }

    // Input time quantum
    printf("Enter time quantum: ");
    scanf("%d", &qt);

    // Execute Round Robin scheduling
    while (1)
    {
        count = 0;

        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] == 0)
            {
                count++;
                continue;
            }

            if (rem_bt[i] > qt)
            {
                rem_bt[i] -= qt;
                sq += qt;
            }
            else
            {
                sq += rem_bt[i];
                rem_bt[i] = 0;
                tat[i] = sq;
            }
        }

        if (count == n)
        {
            break;
        }
    }

    // Calculate waiting time and averages
    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], tat[i], wt[i]);
    }

    // Calculate average times
    awt = awt / n;
    atat = atat / n;

    // Display results
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}
