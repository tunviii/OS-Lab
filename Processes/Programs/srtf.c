#include <stdio.h>

#define MAX 10

int main()
{
    int n, time = 0;
    int at[MAX], bt[MAX], rt[MAX];
    int ct[MAX], wt[MAX], tat[MAX];
    int i, smallest;
    int remain = 0;
    float awt = 0, atat = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time
    printf("Enter arrival time and burst time of each process:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    // Execute SRTF scheduling
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    while (remain < n)
    {
        smallest = -1;

        // Find the arrived process with the shortest remaining time
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (smallest == -1 || rt[i] < rt[smallest])
                {
                    smallest = i;
                }
            }
        }

        // If no process has arrived, advance the CPU time
        if (smallest == -1)
        {
            time++;
            continue;
        }

        // Execute the selected process for one time unit
        rt[smallest]--;
        time++;

        // If the process finishes, calculate its times
        if (rt[smallest] == 0)
        {
            remain++;

            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];

            awt += wt[smallest];
            atat += tat[smallest];

            printf("P%d\t%d\t\t%d\n",
                   smallest + 1,
                   tat[smallest],
                   wt[smallest]);
        }
    }

    // Calculate average times
    awt = awt / n;
    atat = atat / n;

    // Display results
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}
