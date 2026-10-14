#include <stdio.h>

#define MAX 30

int main()
{
    int i, j, n, temp;
    int p[MAX], bt[MAX], wt[MAX], tat[MAX];
    float awt = 0, atat = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process numbers
    printf("Enter the process numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Input burst times
    printf("Enter burst time of each process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    // Sort processes by burst time (ascending order)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process numbers
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
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

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               p[i], bt[i], wt[i], tat[i]);
    }

    // Calculate average times
    awt = awt / n;
    atat = atat / n;

    // Display averages
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}
