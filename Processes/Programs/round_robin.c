#include <stdio.h>

void main()
{
    int i, n, qt, count = 0, temp = 0, sq = 0;
    int bt[10], wt[10], tat[10], rem_bt[10];

    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of each process:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);

        // Initially, remaining burst time = original burst time
        rem_bt[i] = bt[i];
    }

    printf("Enter quantum time: ");
    scanf("%d", &qt);

    while(1)
    {
        count = 0;

        for(i = 0; i < n; i++)
        {
            // Process is already completed
            if(rem_bt[i] == 0)
            {
                count++;
                continue;
            }

            // Process needs more than one quantum
            if(rem_bt[i] > qt)
            {
                rem_bt[i] = rem_bt[i] - qt;
                sq = sq + qt;
            }
            else
            {
                // Process will finish in this turn
                sq = sq + rem_bt[i];
                rem_bt[i] = 0;

                // Completion/Turnaround time
                tat[i] = sq;

                count++;
            }
        }

        // All processes completed
        if(count == n)
            break;
    }

    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for(i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];

        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], tat[i], wt[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);
}
