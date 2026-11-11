
#include <stdio.h>
#define MAX 30

void main()
{
    int i, n, time = 0, completed = 0;
    int bt[MAX], rem_bt[MAX], at[MAX], pr[MAX];
    int wt[MAX], tat[MAX], ct[MAX];
    int min, pos;

    float awt = 0, atat = 0;

    // 1. Input Section
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter burst time, arrival time and priority:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d", &bt[i], &at[i], &pr[i]);
        rem_bt[i] = bt[i];
    }

    // 2. Preemptive Priority Scheduling
    while(completed < n)
    {
        min = 999;
        pos = -1;

        // Find highest priority process among arrived processes
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rem_bt[i] > 0)
            {
                if(pr[i] < min)
                {
                    min = pr[i];
                    pos = i;
                }
            }
        }

        // CPU is idle
        if(pos == -1)
        {
            time++;
            continue;
        }

        // Execute process for one time unit
        rem_bt[pos]--;
        time++;

        // Check whether process is completed
        if(rem_bt[pos] == 0)
        {
            completed++;
            ct[pos] = time;
        }
    }

    // 3. Calculate Waiting Time and Turnaround Time
    printf("\nProcess\tBT\tAT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt = awt + wt[i];
        atat = atat + tat[i];

        // 4. Display Section
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, bt[i], at[i], pr[i], wt[i], tat[i]);
    }

    // 5. Average Calculation
    awt = awt / n;
    atat = atat / n;

    printf("\nAverage Waiting Time = %f", awt);
    printf("\nAverage Turnaround Time = %f\n", atat);
}
