#include <stdio.h>

#define MAX 30

int main()
{
    int i, n;
    int bt[MAX], at[MAX], wt[MAX], tat[MAX], temp[MAX];
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

    // Input arrival time
    printf("Enter arrival time of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &at[i]);
    }

    // Initialize completion timeline
    temp[0] = 0;

    // Calculate waiting and turnaround times
    for (i = 0; i < n; i++)
    {
        temp[i + 1] = temp[i] + bt[i];

        wt[i] = temp[i] - at[i];

        if (wt[i] < 0)
        {
            wt[i] = 0;
            temp[i + 1] = at[i] + bt[i];
        }

        tat[i] = wt[i] + bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    // Display process details
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    // Calculate average times
    awt = awt / n;
    atat = atat / n;

    // Display results
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}
