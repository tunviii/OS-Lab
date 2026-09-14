#include <stdio.h>

int main()
{
    int n, i, j;
    int at[10], bt[10], ct[10], wt[10], tat[10], p[10];
    float avgWT = 0, avgTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;

        printf("\nEnter Arrival Time and Burst Time for P%d: ", p[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }

    // Sort processes according to Arrival Time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp;

                // Swap Arrival Time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process Number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];

    for (i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    // Display results
    printf("\n\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i],
               ct[i], tat[i], wt[i]);
    }

    // Calculate averages
    avgWT = avgWT / n;
    avgTAT = avgTAT / n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}