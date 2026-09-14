#include <stdio.h>

void main()
{
    int n, time, at[10], bt[10], rt[10], ct, i, smallest;
    int remain = 0;

    float awt = 0, atat = 0;

    printf("Enter no. of process: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time of process:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\n\nProcess\t| Turnaround Time | Waiting Time\n\n");

    for (time = 0; remain != n; time++)
    {
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i])
            {
                smallest = i;
            }
        }

        rt[smallest]--;

        if (rt[smallest] == 0)
        {
            remain++;

            ct = time + 1;

            printf("\nP[%d]\t|\t%d\t\t%d",
                   smallest + 1,
                   ct - at[smallest],
                   ct - bt[smallest] - at[smallest]);

            awt = awt + ct - bt[smallest] - at[smallest];

            atat = atat + ct - at[smallest];
        }
    }

    awt = awt / n;
    atat = atat / n;

    printf("\n\nAverage Waiting Time = %f", awt);
    printf("\nAverage Turnaround Time = %f", atat);
}